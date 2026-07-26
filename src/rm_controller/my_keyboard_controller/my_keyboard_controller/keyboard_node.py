#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt16, String
import threading
import json
from pynput import keyboard

class KeyboardBitmaskNode(Node):
    def __init__(self):
        super().__init__('keyboard_bitmask_node')
        self.publisher_ = self.create_publisher(UInt16, 'keyboard_state', 10)
        # 新增：用于触发 FoundationPose 重新识别的发布者
        self.reinit_pub_ = self.create_publisher(String, '/energy/reinit_request', 10)

        # 定义按键顺序（共16个，对应bit0~bit15）
        self.key_sequence = [
            'w', 's', 'a', 'd',          # bit0~3
            'shift', 'ctrl',              # bit4~5
            'q', 'e', 'r', 'f', 'g',     # bit6~10
            'z', 'x', 'c', 'v', 'b'      # bit11~15
        ]
        # 建立按键名 -> bit位置的映射
        self.key_to_bit = {key: idx for idx, key in enumerate(self.key_sequence)}
        
        # 当前按键状态掩码
        self.state_mask = 0
        
        # 启动键盘监听线程
        self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.listener.start()
        
        # 创建定时器，以固定频率发布当前掩码（例如 50Hz = 20ms）
        self.publish_timer = self.create_timer(0.02, self.publish_state)
        
        self.get_logger().info('键盘位掩码节点已启动（持续发布模式，50Hz）')
        self.get_logger().info('支持的按键: ' + ' '.join(self.key_sequence))
        self.get_logger().info('按下 z 键触发一次 FoundationPose 识别')
        self.get_logger().info('ESC键退出节点')
    
    def get_key_name(self, key):
        """将pynput的key对象统一转换为字符串标识"""
        try:
            return key.char  # 普通字符键
        except AttributeError:
            # 特殊键
            if key in (keyboard.Key.shift, keyboard.Key.shift_l, keyboard.Key.shift_r):
                return 'shift'
            elif key in (keyboard.Key.ctrl, keyboard.Key.ctrl_l, keyboard.Key.ctrl_r):
                return 'ctrl'
            elif key == keyboard.Key.esc:
                return 'esc'
            else:
                return None  # 忽略其他特殊键
    
    def update_mask(self, key_name, pressed):
        """更新掩码，不发布"""
        if key_name not in self.key_to_bit:
            return
        bit = self.key_to_bit[key_name]
        if pressed:
            self.state_mask |= (1 << bit)
        else:
            self.state_mask &= ~(1 << bit)
    
    def publish_state(self):
        """定时发布当前掩码"""
        msg = UInt16()
        msg.data = self.state_mask
        self.publisher_.publish(msg)
        self.get_logger().debug(f'发布掩码: 0x{self.state_mask:04X}')
    
    def trigger_foundationpose(self):
        """发送请求触发 FoundationPose 重新识别"""
        req = {
            "request_id": "keyboard_z_trigger",
            "reason": "key_press",
            "stamp_ns": self.get_clock().now().nanoseconds
        }
        msg = String()
        msg.data = json.dumps(req)
        self.reinit_pub_.publish(msg)
        self.get_logger().info('🔍 已发送 FoundationPose 重新识别请求')
    
    def on_press(self, key):
        key_name = self.get_key_name(key)
        if key_name == 'esc':
            self.get_logger().info('ESC按下,正在关闭节点...')
            self.destroy_node()
            rclpy.shutdown()
            return
        if key_name:
            self.update_mask(key_name, pressed=True)
    
    def on_release(self, key):
        key_name = self.get_key_name(key)
        if key_name:
            self.update_mask(key_name, pressed=False)
    
    def __del__(self):
        if hasattr(self, 'listener') and self.listener.running:
            self.listener.stop()

def main(args=None):
    rclpy.init(args=args)
    node = KeyboardBitmaskNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node.listener.running:
            node.listener.stop()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()