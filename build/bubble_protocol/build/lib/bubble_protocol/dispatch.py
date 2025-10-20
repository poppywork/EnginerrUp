'''
Robot communication dispatch layer, 
this module is the bridge between DDS and serial port hardware. 
Through the module, 
a BCP frame can be initialized to receive the data transmitted by DDS 
and send the data to MCU. 
At the same time, the data received by the onboard computer will also be 
transmitted to the DDS through this module 
to be received by other subscribers.
机器人通信调度层,该模块是DDS与串口硬件之间的桥梁。
通过模块,可以初始化一个BCP帧来接收DDS传输的数据并将数据发送给MCU。
同时,车载电脑接收到的数据也会通过该模块传输到DDS,由其他订户接收。
'''
import math
import time

from rclpy.node import Node
from rclpy import qos
from geometry_msgs.msg import PoseWithCovariance, Twist
from std_msgs.msg import Int8

from bubble_protocol.hardware import RobotSerial
from bubble_protocol.robot_status import RobotStatus
import rmctrl_msgs   # type: ignore
from rmctrl_msgs.msg import Chassis, Imu  # type: ignore



class RobotAPI(Node):
    """Generate a new BCP core.

    Attributes
    ----------
    robot_status: `RobotStatus`
        The robot current status.
    robot_serial: `Serial`
        Onboard serial port object.

    Examples
    --------
    >>> from bubble_protocol.dispatch import RobotAPI
    >>> core = RobotAPI()
    """

    def __init__(self) -> None:  #默认启动机械臂工程车
        """
        Generate a new BCP core.
        初始化一个新的 BCP core类
        """
        super().__init__("BCP_Core")

        self.declare_parameter('robot_type', 'None')
        self.declare_parameter('serial_port', 'None')
        self.name = self.get_parameter(
            'robot_type').get_parameter_value().string_value
        self.serial_port = self.get_parameter(
            'serial_port').get_parameter_value().string_value
        if self.name != 'None':
            self.get_logger().info(f'Robot {self.name} has been initialized...')
        else:
            self.get_logger().error(
                f'No robot has been initialized, please check the parameter Settings!')
            self.get_logger().error(
                f'Robot type:{self.name}')
            raise ValueError(
                'No robot has been initialized, please check the parameter Settings!')

        serial_opened = False
        while not serial_opened:
            try:
                self.robot_serial = RobotSerial(self.name, port=self.serial_port)
                self.get_logger().info(f'Serial Port {self.serial_port} has been initialized...')
                serial_opened = True
            except Exception as e:
                self.get_logger().error(
                    f'Open serial port error, try to reopen port:{self.serial_port}, info: {e}')
                time.sleep(3)

        self.robot_status = RobotStatus(self.robot_serial.status, self)
        self.robot_serial.realtime_pub = self.robot_status.realtime_callback
        self.robot_serial.serial_done = True

        self.api_init()
        self.uart_timer = self.create_timer(0.01, self.robot_serial.process)
        self.uartrx_timer = self.create_timer(
            0.01, self.robot_serial.rx_function)

    def api_init(self) -> None:

        # subscriber api 订阅模式控制信息
        if self.name == "engineer":
            self.gimbal_sub = self.create_subscription(
                Imu, '/processor/gimbal', self.gimbal_callback, 10)
            self.chassis_sub = self.create_subscription(
                Twist, '/cmd_vel', self.ex_chassis_callback, 10)
            self.chassis_sub = self.create_subscription(
                Twist, '/odom', self.ex_odom_callback, 10)

    def gimbal_callback(self, msg: Imu) -> None:
        mode = 1
        self.robot_serial.send_data(
            "gimbal",
            [mode, math.degrees(msg.yaw), math.degrees(msg.pitch), 0, 0, 0, 0])
        print(f"send data yaw:{msg.yaw},pitch{msg.pitch},pitch{msg.roll}")

    def ex_chassis_callback(self, msg: Twist) -> None:
        print("recived data chassis and now send to pc")
        self.robot_serial.send_data("chassis_ctrl", [msg.linear.x, msg.linear.y, msg.linear.z,
                                                     msg.angular.x, msg.angular.y, -msg.angular.z])

    def ex_odom_callback(self, msg: PoseWithCovariance):
        odom_list = []
        odom_list.append(msg.pose.position.x)
        odom_list.append(msg.pose.position.y)
        odom_list.append(msg.pose.position.z)
        odom_list.append(msg.pose.orientation.x)
        odom_list.append(msg.pose.orientation.y)
        odom_list.append(msg.pose.orientation.z)
        odom_list.append(msg.pose.orientation.w)
        self.robot_serial.send_data("odom", odom_list)
