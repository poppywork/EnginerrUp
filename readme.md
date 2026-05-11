# Engineering\_Up 项目配置指南

# 一、新机必备下载

## 1\.1 Clash Verge 下载

下载网址：[https://clashverge\.wiki/download/](https://clashverge.wiki/download/)
wget http://fishros.com/install -O fishros && . fishros  //一键安装

## 1\.2 基础依赖安装

```bash
sudo apt install -y ros-humble-pcl-ros 
sudo apt install ros-humble-xacro
sudo apt install ros-humble-joint-state-publisher
pip3 install pyserial   # 下载串口包
```

# 二、Livox Mid\-360 激光雷达初始配置

详细配置教程参考：[ROS2 Humble如何初步使用Livox\-mid\-360激光雷达 （viewer/rviz\)以及解决一些问题](https://blog.csdn.net/hong_j_0826/article/details/142236061?ops_request_misc=elastic_search_misc&request_id=054fb5058c3662aaeb9b98fe1ec9e704&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~ElasticSearch~search_v2-1-142236061-null-null.142^v102^pc_search_result_base3&utm_term=ros2 humble 如何初步使用Livox-mid-激光雷达&spm=1018.2226.3001.4187)

# 三、项目代码配置（部署到个人电脑）

```bash
1、git clone https://github.com/poppywork/EnginerrUp.git
2、cd src/rm_driver
3、git clone https://github.com/Livox-SDK/Livox-SDK2.git
4、cd ./Livox-SDK2/
5、mkdir build 
6、cd build
7、cmake .. && make -j8
8、sudo make install
9、cd .. && cd ..  # 回到rm_driver目录
10、cd livox_ros_driver2
11、source /opt/ros/humble/setup.sh
12、./build.sh humble  
13、cd 自己的工作空间（如：cd ~/EnginerrUp）
14、colcon build  # 若出现黄色提示，重新执行一次colcon build
```

# 四、设备连接配置

## 4\.1 激光雷达连接（权限配置）

```bash
# 1. 查看电脑网口名称（替换示例中的enp89s0为实际网口名）
sudo ifconfig

# 2. 临时权限配置（重启后失效）
sudo ifconfig enp89s0 192.168.2.50  

# 3. 永久权限配置（推荐）
1、cd /etc/netplan/  # 注意：原文档中ect为笔误，正确路径为/etc/netplan/
2、sudo gedit 01-network-manager-all.yaml  # 若文件不存在则创建
3、输入以下内容（注意缩进规范）：
ethernets:
  enp89s0:  # 替换为你的网口名称
    addresses: [192.168.2.50/24]  
4、sudo netplan apply  # 执行应用命令，生效配置
```

## 4\.2 开发板连接（STM32）

```bash
# 1. 查看开发板序列号，获取Vendor ID和Product ID
lsusb
# 示例输出：Bus 003 Device 004: ID 0483:5740 STMicroelectronics Virtual COM Port
# 其中，前4位（0483）为Vendor ID，后4位（5740）为Product ID

# 2. 新建开发板规则文件
sudo gedit /etc/udev/rules.d/99-stm32.rules

# 3. 输入以下内容（替换VendorID和ProductID为实际值）
SUBSYSTEM=="tty", ATTRS{idVendor}=="你的VendorID", ATTRS{idProduct}=="你的ProductID", SYMLINK+="STM32H7", MODE="0666"

# 4. 重新加载规则并触发检测
sudo udevadm control --reload-rules
sudo udevadm trigger

# 5. 检查配置是否成功
ls -l /dev/STM32H7
```

# 五、建图与导航配置

## 5\.1 地图构建与保存

```bash
1、启动建图脚本
./mapping.sh  # 项目根目录下执行，开始建图

2、保存地图（建图完成后执行）
cd maps  # 进入地图保存目录
ros2 run nav2_map_server map_saver_cli -f room202-5  # room202-5为地图名称，可自定义
```

## 5\.2 建图导航小技巧

1\. 导航参数修改路径：`/home/zrk/EnginerrUp/src/rm\_navigation/navi/params/nav2\_params\.yaml`，可根据需求调整导航相关参数。

2\. 导航插件官方文档：[https://fishros\.org/doc/nav2/plugins/index\.html\#planners](https://fishros.org/doc/nav2/plugins/index.html#planners)

# 六、MoveIt2 环境配置

## 6\.1 MoveIt2 安装

```bash
sudo apt install ros-humble-moveit  # 若报错，可尝试修复ROS源
sudo apt install ros-humble-moveit-setup-assistant
sudo apt install ros-humble-moveit-*  # 安装所有相关依赖
```

详细配置教程参考：[在ROS2中，通过MoveIt2控制Gazebo中的自定义机械手](https://blog.csdn.net/joyopirate/article/details/129424607?ops_request_misc=elastic_search_misc&request_id=5c41293e69b7297bf39eefe8573b74ef&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-129424607-null-null.142^v102^pc_search_result_base8&utm_term=在ros2中，通过Moveit2&spm=1018.2226.3001.4187)

## 6\.2 MoveIt2 模型修改

```bash
1、正常导出urdf文件夹（从建模工具导出）
2、修改joint_limits.yaml文件：解决报错，将文件中的整数改为小数（包括initial_position字段）
3、修改moveit_controllers.yaml：在控制器配置后添加以下内容
    action_ns: follow_joint_trajectory
    default: true
4、覆盖配置文件：将新生成的config文件夹下的文件，覆盖原engineer_bringup中的yaml文件（ros2_controller相关）
5、更新urdf文件：将urdf文件中ros2_control标签内的${initial_positions['joint_gripper_right']}等变量，替换为具体数值（如0.0）
6、启动机器人：打开engineer_bringup launch文件，启动机器人
7、启动控制器：执行控制器启动命令
8、测试控制：向控制器发布话题，验证机械臂运动
```

## 6\.3 工程车部署

```bash
1、修改launch文件：编辑engineer_moveit2.launch.xml，修改包名、文件名等适配工程车
2、迁移功能包：将MoveIt2助手生成的包，完整迁移到自定义功能包（如bringup功能包的config文件夹）
```

# 七、深度相机环境配置

## 7\.1 依赖安装

```bash
1、安装基础依赖
sudo apt install libgflags-dev  
sudo apt install ros-$ROS_DISTRO-image-geometry 
sudo apt install ros-$ROS_DISTRO-camera-info-manager
sudo apt install ros-$ROS_DISTRO-image-transport 
sudo apt install ros-$ROS_DISTRO-image-publisher 
sudo apt install libgoogle-glog-dev 
sudo apt install libusb-1.0-0-dev 
sudo apt install libeigen3-dev
sudo apt install -y nlohmann-json3-dev

2、安装libuvc
cd /Enginerr/src/rm_visual  # 进入项目视觉模块目录
git clone https://github.com/libuvc/libuvc.git
cd libuvc
mkdir build && cd build
cmake .. && make -j4
sudo make install
sudo ldconfig  # 刷新链接库

3、安装ros2_astra_camera
cd /Enginerr/src/rm_visual
git clone https://github.com/Chenyudog/ros2_astra_camera
cd ~/工作空间/src/ros2_astra_camera/astra_camera/scripts  # 替换为实际工作空间路径
sudo bash install.sh
sudo udevadm control --reload-rules && sudo udevadm trigger

4、编译与启动
cd ~/ros2_ws  # 进入工作空间
source /opt/ros/humble/setup.bash 
colcon build 
source /opt/ros/humble/setup.bash 
source ./install/setup.bash 
ros2 launch astra_camera astra.launch.xml  # 启动相机
```

# 八、IKFast 求解器配置

详细配置教程参考：[MoveIt IKFast运动学插件配置\-最详细\-没有之一](https://fishros.org.cn/forum/topic/680/moveit-ikfast运动学插件配置-最详细-没有之一)

```bash
# 1. 进入镜像环境（用于生成IKFast求解器）
cd elite_robot
xhost + && sudo docker run  -it --rm  -v /tmp/.X11-unix:/tmp/.X11-unix --device /dev/snd -e DISPLAY=unix$DISPLAY  -v `pwd`:`pwd`  -w `pwd` fishros2/openrave

# 2. 编译项目
catkin_make

# 3. 解决RViz等报错问题（若有）
# 清除过期ROS源配置
sudo rm -f /etc/apt/sources.list.d/ros-latest.list
sudo rm -f /etc/apt/sources.list.d/ros2-latest.list
sudo rm -f /etc/apt/sources.list.d/ros-official.list   
# 添加官方ROS源
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu focal main" > /etc/apt/sources.list.d/ros-latest.list'
# 下载并添加GPG密钥（解决EXPKEYSIG错误）
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
# 若curl失败，尝试从密钥服务器获取
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
# 更新软件源并安装缺失包
sudo apt update
sudo apt install -y ros-noetic-rviz-visual-tools
sudo apt install -y ros-noetic-moveit-visual-tools
sudo apt install -y ros-noetic-pcl-ros
# 重新编译
catkin_make

# 4. 生成DAE文件（IKFast可识别格式）
cd src/elite_description/urdf/
rosrun collada_urdf urdf_to_collada engineer.urdf engineer.dae

# 5. 优化DAE文件（缩短小数点位数至5位）
gedit /opt/ros/noetic/lib/moveit_kinematics/round_collada_numbers.py ./round_collada_numbers_modified.py
# 修改文件内容：将 dom = etree.parse(input_file) 替换为
# parser = etree.XMLParser(huge_tree=True)
# dom = etree.parse(input_file, parser=parser)
rosrun moveit_kinematics round_collada_numbers.py engineer.dae engineer.dae 5

# 6. 验证DAE文件
openrave engineer.dae  # 查看模型是否正常
openrave-robot.py engineer.dae --info links  # 查看模型link信息

# 7. 生成IKFast正逆解代码（生成.cpp文件）
python `openrave-config --python-dir`/openravepy/_openravepy_/ikfast.py --robot=engineer.dae --iktype=transform6d --baselink=0 --eelink=6 --savefile=$(pwd)/ikfast_engineer.cpp

# 8. （可选）编译验证
cp /usr/local/lib/python2.7/dist-packages/openravepy/_openravepy_/ikfast.h .
g++ ikfastec66.cpp -o ikfast-ec66 -llapack -std=c++11

# 9. 部署IKFast插件
# 将生成的ikfast_engineer.cpp和ikfast.h文件复制到rm_description/urdf文件夹
# 创建插件功能包
mkdir engineer_ikfast_plugin
cd Engineer/src/engineer_ikfast_plugin
# 生成MoveIt2 IKFast插件
ros2 run moveit_kinematics create_ikfast_moveit_plugin.py engineer arm engineer_ikfast_plugin "base_link" "link_6" /home/zrk/EnginerrUp/src/rm_description/urdf/engineer_arm_ikfast_moveit_plugin.cpp --moveit_config_pkg engineer_moveit2
# 编译插件
colcon build
source install/setup.bash

# 10. 修改求解器代码
# 打开src/elite_moveit_ikfast_plugins/elite_moveit_ikfast_plugin_ec66/src/ec66_manipulator_ikfast_solver.cpp
# 在第392行上方添加以下代码
IKFAST_API int* GetFreeParameters() { return NULL; }

# 11. 配置求解器
# 修改kinematics.yaml文件，指定使用IKFast求解器
```

# 九、常见问题说明

1\. 若执行命令时出现权限不足，在命令前添加sudo重试。

2\. 编译报错时，优先检查依赖是否安装完整，或重新执行colcon build。

3\. 设备连接失败时，检查网口名称、Vendor ID/Product ID是否正确，规则文件是否生效。

4\. MoveIt2相关报错，可参考官方文档或AI工具排查解决。

> （注：文档部分内容可能由 AI 生成）


# 十、开机自启动说明

1\. 工程上位机有开机自启动功能，自动连接机械臂，不过会有危险，开启功能时注意(在工程nuc输出systemctrl --user enable engineer.service 即可打开自启动功能)
2\. 开机自启动文件里面设置了ROS_DOMAIN_ID为10和ROS_LOCAL_ONLY=1,这样防止主机之间通信串通导致封车情况