# Engineering_Up 项目配置指南新机要下载

## 新机下载
sudo apt install -y ros-humble-pcl-ros 
sudo apt install ros-humble-xacro
sudo apt install ros-humble-joint-state-publisher
pip3 install pyserial   下载串口包
-----------------------------------------------------------------------

## [初始配置mid360网址]
(https://blog.csdn.net/hong_j_0826/article/details/142236061?ops_request_misc=elastic_search_misc&request_id=054fb5058c3662aaeb9b98fe1ec9e704&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~ElasticSearch~search_v2-1-142236061-null-null.142^v102^pc_search_result_base3&utm_term=ros2%20humble%20%E5%A6%82%E4%BD%95%E5%88%9D%E6%AD%A5%E4%BD%BF%E7%94%A8Livox-mid-%E6%BF%80%E5%85%89%E9%9B%B7%E8%BE%BE&spm=1018.2226.3001.4187)

## 如何配置代码于自己电脑
1、git clone https://github.com/poppywork/EnginerrUp.git
2、cd ./Livox-SDK2/
3、rm build
4、mkdir build 
5、cd build
6、cmake .. && make -j8
7、sudo make install
8、cd /livox_ws/src/livox_ros_driver2
9、source /opt/ros/humble/setup.sh
10、./build.sh humble  
11、cd 自己工作空间
12、colcon build (如果显示黄色,再构建一次)


## 连接雷达权限需求
sudo ifconfig查看自己电脑网口名称(我的是enp89s0)
//给雷达临时权限指令
sudo ifconfig enp89s0 192.168.2.50  


//给雷达永久权限指令
1、cd  /ect/netplan/
2、sudo gedit 01-network-manager-all.yaml  (没有就创建一个)
3、输入:ethernets: #注意缩进
    enp89s0:  
      addresses: [192.168.2.50/24]  
4、sudo netplan apply //执行应用命令


## 连接开发板
lsusb
查看开发板序列号类似:Bus 003 Device 004: ID 0483:5740 STMicroelectronics Virtual COM Port  # Vendor ID (ID 后的前 4 位) 和 Product ID (后 4 位)，
sudo gedit /etc/udev/rules.d/99-stm32.rules 新建stm32开发板规则文件
输入: SUBSYSTEM=="tty", ATTRS{idVendor}=="你的VendorID", ATTRS{idProduct}=="你的ProductID", SYMLINK+="STM32H7", MODE="0666"
sudo udevadm control --reload-rules
sudo udevadm trigger  # 重新触发设备检测
ls -l /dev/STM32H7    #检查是否生成了 /dev/STM32H7






