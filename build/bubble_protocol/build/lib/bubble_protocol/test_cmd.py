# 导入必要的ROS 2和消息类型库
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rclpy.timer import Timer

class CmdVelPublisher(Node):
    """发布 /cmd_vel 话题的节点类，用于发送固定速度指令"""
    def __init__(self):
        # 初始化父类 Node，节点名称设为 "fixed_cmd_vel_publisher"（可自定义）
        super().__init__("fixed_cmd_vel_publisher")
        
        # 1. 创建 /cmd_vel 话题的发布者
        # 消息类型：Twist，队列大小：10（避免消息堆积）
        self.cmd_vel_publisher = self.create_publisher(
            msg_type=Twist,
            topic="/cmd_vel",
            qos_profile=10
        )
        
        # 2. 创建定时器，控制消息发布频率（这里设为 10Hz，即每秒发10次）
        # 定时器回调函数：self.timer_callback
        self.timer: Timer = self.create_timer(
            timer_period_sec=1.0,  # 周期=1/频率，0.1秒=10Hz
            callback=self.timer_callback
        )
        
        # 3. 打印初始化日志，确认节点启动
        self.get_logger().info("Fixed CmdVel Publisher Node Started!")
        self.get_logger().info(f"Publishing to /cmd_vel: vx=0.1, vy=0.1, vw=0.0 (10Hz)")

    def timer_callback(self):
        """定时器回调函数：每次触发时构造并发布 Twist 消息"""
        # 创建 Twist 消息对象（用于描述线性速度和角速度）
        twist_msg = Twist()
        
        # 设置线性速度（单位：m/s）
        twist_msg.linear.x = 0.0  # x轴速度（前进/后退，正数向前）
        twist_msg.linear.y = 0.0  # y轴速度（左右平移，仅全向底盘支持）
        twist_msg.linear.z = 0.0  # z轴速度（上下，一般底盘不支持）
        
        # 设置角速度（单位：rad/s）
        twist_msg.angular.x = 0.0  # x轴角速度（横滚，底盘不支持）
        twist_msg.angular.y = 0.0  # y轴角速度（俯仰，底盘不支持）
        twist_msg.angular.z = 0.5 # z轴角速度（转向，正数逆时针）
        
        # 发布消息
        self.cmd_vel_publisher.publish(twist_msg)

def main(args=None):
    """节点主函数：初始化ROS 2、启动节点、处理回调循环"""
    # 初始化 ROS 2 上下文
    rclpy.init(args=args)
    
    # 创建节点实例
    cmd_vel_publisher = CmdVelPublisher()
    
    try:
        # 启动节点回调循环（阻塞，直到节点关闭）
        rclpy.spin(cmd_vel_publisher)
    except KeyboardInterrupt:
        # 捕获 Ctrl+C 信号，打印关闭日志
        cmd_vel_publisher.get_logger().info("Node is shutting down...")
    finally:
        # 销毁节点实例，释放资源
        cmd_vel_publisher.destroy_node()
        # 关闭 ROS 2 上下文
        rclpy.shutdown()

# 程序入口：若直接运行该文件，执行 main 函数
if __name__ == "__main__":
    main()
