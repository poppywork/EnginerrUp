#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt16
import threading
from pynput import keyboard

class KeyboardBitmaskNode(Node):
    def __init__(self):
        super().__init__('keyboard_bitmask_node')
        self.publisher_ = self.create_publisher(UInt16, 'keyboard_state', 10)

        # 定义按键顺序（共16个，对应bit0~bit15）
        self.key_sequence = [
            'w', 's', 'a', 'd',          # bit0~3
            'shift', 'ctrl',              # bit4~5
            'q', 'e', 'r', 'f', 'g',     # bit6~10
            'z', 'x', 'c', 'v', 'b'      # bit11~15
        ]
        # 建立按键名 -> bit位置的映射（用于快速查找）
        self.key_to_bit = {key: idx for idx, key in enumerate(self.key_sequence)}
        
        # 当前按键状态掩码
        self.state_mask = 0
        
        # 启动监听线程
        self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.listener.start()
        
        self.get_logger().info('键盘位掩码节点已启动')
        self.get_logger().info('支持的按键: ' + ' '.join(self.key_sequence))
        self.get_logger().info('ESC键退出节点')
    
    def get_key_name(self, key):
        """将pynput的key对象统一转换为字符串标识"""
        try:
            # 普通字符键
            return key.char
        except AttributeError:
            # 特殊键：shift, ctrl, esc等
            if key == keyboard.Key.shift or key == keyboard.Key.shift_l or key == keyboard.Key.shift_r:
                return 'shift'
            elif key == keyboard.Key.ctrl or key == keyboard.Key.ctrl_l or key == keyboard.Key.ctrl_r:
                return 'ctrl'
            elif key == keyboard.Key.esc:
                return 'esc'
            else:
                # 忽略其他特殊键（如alt, cmd等）
                return None
    
    def update_and_publish(self, key_name, pressed):
        """更新某个按键的状态并发布新掩码"""
        if key_name not in self.key_to_bit:
            return  # 不是我们关心的按键
        
        bit = self.key_to_bit[key_name]
        old_mask = self.state_mask
        
        if pressed:
            self.state_mask |= (1 << bit)
        else:
            self.state_mask &= ~(1 << bit)
        
        # 只有状态发生变化时才发布
        if self.state_mask != old_mask:
            msg = UInt16()
            msg.data = self.state_mask
            self.publisher_.publish(msg)
            self.get_logger().debug(f'更新掩码: 0x{self.state_mask:04X}')
    
    def on_press(self, key):
        key_name = self.get_key_name(key)
        if key_name == 'esc':
            self.get_logger().info('ESC按下,正在关闭节点...')
            self.destroy_node()
            rclpy.shutdown()
            return
        if key_name:
            self.update_and_publish(key_name, pressed=True)
    
    def on_release(self, key):
        key_name = self.get_key_name(key)
        if key_name:
            self.update_and_publish(key_name, pressed=False)
    
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