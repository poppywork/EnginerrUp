# Engineering_Up 项目配置指南新机要下载

##
clash_verge下载网址：https://clashverge.wiki/download/

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
2、cd src/rm_driver
3、git clone https://github.com/Livox-SDK/Livox-SDK2.git
4、cd ./Livox-SDK2/
5、mkdir build 
6、cd build
7、cmake .. && make -j8
8、sudo make install
9、cd ..   cd ..
10、cd livox_ros_driver2
11、source /opt/ros/humble/setup.sh
12、./build.sh humble  
13、cd 自己工作空间
14、colcon build (如果显示黄色,再构建一次)



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

## 构建地图+保存地图
1、启动 mapping.sh 开始建图
2、cd maps目录
3、ros2 run nav2_map_server map_saver_cli -f room202-5 保存地图

### 建图导航小tips
1、/home/zrk/EnginerrUp/src/rm_navigation/navi/params/nav2_params.yaml 在这个文件修改导航的参数
官方文档在https://fishros.org/doc/nav2/plugins/index.html#planners
2、


## 配置Moveit2环境指令:
sudo apt install ros-humble-moveit（报错了就修复一下源，报错AI可以解答你）
sudo apt install ros-humble-moveit-setup-assistant
sudo apt install ros-humble-moveit-*

网址:https://blog.csdn.net/joyopirate/article/details/129424607?ops_request_misc=elastic_search_misc&request_id=5c41293e69b7297bf39eefe8573b74ef&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-129424607-null-null.142^v102^pc_search_result_base8&utm_term=%E5%9C%A8ros2%E4%B8%AD%EF%BC%8C%E9%80%9A%E8%BF%87Moveit2&spm=1018.2226.3001.4187

## 重新修改moveit2模型
1、正常导出urdf文件夹
2、修改joint_limits.yaml文件里的报错，将整数改为小数(还有initial_position的)
3、在moveit_controllers.yaml的控制器后面加上
    action_ns: follow_joint_trajectory
    default: true
4、将新出的config的文件覆盖掉原来的engineer_bringup里的yaml文件(ros2_controller文件)
5、在urdf文件更新ros2_control标签的内容，把${initial_positions['joint_gripper_right']}这些换成想要的数字，比如0.0
6、打开engineer_bingup  launch文件启动机器人
7、启动控制器
8、向控制器发布话题即可

##如何继续部署到工程车上:
1、修改engineer_moveit2.launch.xml上的包名，文件名等
2、将movie2助手生成的包从头到尾移到自己创的功能包里面，比如bringup功能包里面的config文件夹



## 如何配置深度相机环境
#一、配必要文件
1.sudo apt install libgflags-dev  
2.sudo apt install ros-$ROS_DISTRO-image-geometry 
3.sudo apt install ros-$ROS_DISTRO-camera-info-manager
4.sudo apt install ros-$ROS_DISTRO-image-transport 
5.sudo apt install ros-$ROS_DISTRO-image-publisher 
6.sudo apt install libgoogle-glog-dev 
7.sudo apt install libusb-1.0-0-dev 
8.sudo apt install libeigen3-dev
9.sudo apt install -y nlohmann-json3-dev

cd/Enginerr/src/rm_visual
git clone https://github.com/libuvc/libuvc.git
cd libuvc
mkdir build && cd build
cmake .. && make -j4
sudo make install
sudo ldconfig # Refreshing the link library

cd/Enginerr/src/rm_visual
git clone https://github.com/Chenyudog/ros2_astra_camera
cd ~/工作空间/src/ros2_astra_camera/astra_camera/scripts
sudo bash install.sh
sudo udevadm control --reload-rules && sudo udevadm trigger

编译：
cd ~/ros2_ws
source /opt/ros/humble/setup.bash 
colcon build 
source /opt/ros/humble/setup.bash 
source ./install/setup.bash 
ros2 launch astra_camera astra.launch.xml


## ikfast求解器的配置
https://fishros.org.cn/forum/topic/680/moveit-ikfast%E8%BF%90%E5%8A%A8%E5%AD%A6%E6%8F%92%E4%BB%B6%E9%85%8D%E7%BD%AE-%E6%9C%80%E8%AF%A6%E7%BB%86-%E6%B2%A1%E6%9C%89%E4%B9%8B%E4%B8%80  //网址

cd elite_robot
xhost + && sudo docker run  -it --rm  -v /tmp/.X11-unix:/tmp/.X11-unix --device /dev/snd -e DISPLAY=unix$DISPLAY  -v `pwd`:`pwd`  -w `pwd` fishros2/openrave
# 进入镜像

catkin_make
# 编译


# 怎么解决rivz等报错问题
# 1. 清除过期的 ROS 源配置（避免干扰）
sudo rm -f /etc/apt/sources.list.d/ros-latest.list
sudo rm -f /etc/apt/sources.list.d/ros2-latest.list
sudo rm -f /etc/apt/sources.list.d/ros-official.list   
# 2. 添加官方 ROS 源（使用 packages.ros.org，国内镜像有时不同步）
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu focal main" > /etc/apt/sources.list.d/ros-latest.list'
# 3. 下载并添加新的 GPG 密钥（解决 EXPKEYSIG）
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
# 如果上面的 curl 失败，尝试从密钥服务器获取
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
# 4. 更新软件源（现在应该不再报签名错误）
sudo apt update
# 5. 安装缺失的包
sudo apt install -y ros-noetic-rviz-visual-tools
sudo apt install -y ros-noetic-moveit-visual-tools
sudo apt install -y ros-noetic-pcl-ros
# 6.编译
catkin_make

cd src/elite_description/urdf/

# 改写对应位置的.urdf文件生存ikfast能看懂的.dae文件
rosrun collada_urdf urdf_to_collada engineer.urdf engineer.dae

# 将文件的小数点缩短到小数点后五位
gedit /opt/ros/noetic/lib/moveit_kinematics/round_collada_numbers.py ./round_collada_numbers_modified.py

把 dom = etree.parse(input_file) 改成 parser = etree.XMLParser(huge_tree=True)   dom = etree.parse(input_file, parser=parser)

rosrun moveit_kinematics round_collada_numbers.py engineer.dae engineer.dae 5

# 验证
openrave engineer.dae //看一下模型对不对
openrave-robot.py engineer.dae --info links //看一下文件中的link

# 来生成ikfast针对机械臂的正逆解代码,生成.cpp文件，之后可以在ros2配置插件（关键的一步）
python `openrave-config --python-dir`/openravepy/_openravepy_/ikfast.py --robot=engineer.dae --iktype=transform6d --baselink=0 --eelink=6 --savefile=$(pwd)/ikfast_engineer.cpp

# 复制所需的头文件，接着直接使用g++进行编译(可有可无，用于生成可执行文件看看成功不成功)
cp /usr/local/lib/python2.7/dist-packages/openravepy/_openravepy_/ikfast.h .
g++ ikfastec66.cpp -o ikfast-ec66 -llapack -std=c++11

# 转折点:将生成的cpp文件和ikfast.h文件放到rm_description/urdf文件夹中

# 用moveit2工具生成ikfast插件包
mkdir engineer_ikfast_plugin   //存放插件功能包

cd Engineer/src/engineer_ikfast_plugin

ros2 run moveit_kinematics create_ikfast_moveit_plugin.py   engineer   arm   engineer_ikfast_plugin   "base_link"   "link_6" /home/zrk/EnginerrUp/src/rm_description/urdf/engineer_arm_ikfast_moveit_plugin.cpp  --moveit_config_pkg engineer_moveit2

colcon build

source install setup.bash

# 打开文件src/elite_moveit_ikfast_plugins/elite_moveit_ikfast_plugin_ec66/src/ec66_manipulator_ikfast_solver.cpp 接着修改低392行代码，在其上面添加上一行

IKFAST_API int* GetFreeParameters() { return NULL; }

# 之后就可以根据改kinematics.yaml文件来改求解器了

