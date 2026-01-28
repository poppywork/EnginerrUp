#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <example_interfaces/msg/bool.hpp>
#include <example_interfaces/msg/float64_multi_array.hpp>
#include <rmctrl_msgs/msg/pose_command.hpp>

using MoveGroupInterface = moveit::planning_interface::MoveGroupInterface;
using Bool = example_interfaces::msg::Bool; 
using FloatArray = example_interfaces::msg::Float64MultiArray;
using PoseCmd = rmctrl_msgs::msg::PoseCommand;
using namespace std::placeholders;

class Commander
{
public:
    Commander(std::shared_ptr<rclcpp::Node> node)
    {
        node_ = node;
        arm_ = std::make_shared<MoveGroupInterface>(node_,"arm");
        arm_->setMaxVelocityScalingFactor(1.0);
        arm_->setMaxAccelerationScalingFactor(1.0);
        gripper_ = std::make_shared<MoveGroupInterface>(node_,"gripper");

        open_gripper_sub_ = node_->create_subscription<Bool>(
            "open_gripper", 10 ,std::bind(&Commander::OpenGripperCallback,this,_1));

        joint_cmd_sub_ = node_->create_subscription<FloatArray>(
            "joint_commander", 10 ,std::bind(&Commander::JointCmdCallback,this,_1));
        
        pose_cmd_sub_ = node_->create_subscription<PoseCmd>(
            "pose_commander", 10 ,std::bind(&Commander::PoseCmdCallback,this,_1));
    }

    void GoToNamedTarget(const std::string &name)
    {
        arm_->setStartStateToCurrentState();
        arm_->setNamedTarget(name);
        PlanAndExecute(arm_);
    }

    void GoToJointTarget(const std::vector<double> &joints)
    {
        arm_->setStartStateToCurrentState();
        arm_->setJointValueTarget(joints);
        PlanAndExecute(arm_);
    }

    void GoToPoseTarget(double x,double y,double z,double roll,double pitch,
                        double yaw,bool cartesian_path=false)
    {
        tf2::Quaternion q;
        q.setRPY(roll,pitch,yaw);
        q.normalize();

        geometry_msgs::msg::PoseStamped target_pose;
        target_pose.header.frame_id = "base_link";
        target_pose.pose.position.x = x;
        target_pose.pose.position.y = y;
        target_pose.pose.position.z = z;
        target_pose.pose.orientation.x = q.getX();
        target_pose.pose.orientation.y = q.getY();
        target_pose.pose.orientation.z = q.getZ();
        target_pose.pose.orientation.w = q.getW();

        arm_->setStartStateToCurrentState();
        if(cartesian_path == true)
        {
            moveit_msgs::msg::RobotTrajectory trajectory;
            std::vector<geometry_msgs::msg::Pose> waypoints;

            waypoints.push_back(target_pose.pose);

            double fraction = arm_->computeCartesianPath(waypoints, 0.01, 0.0, trajectory);
            RCLCPP_INFO(node_->get_logger(), "笛卡尔规划执行比例 fraction = %.2f", fraction);
            if(fraction >= 0.95)
            {
                arm_->execute(trajectory);
                RCLCPP_INFO(node_->get_logger(), "执行笛卡尔规划");
            }
        }
        else
        {
            arm_->setPoseTarget(target_pose);
            PlanAndExecute(arm_);
        }

    }

    void OpenGripper()
    {
        gripper_->setStartStateToCurrentState();
        gripper_->setNamedTarget("gripper_open");
        PlanAndExecute(gripper_);
    }

    void CloseGripper()
    {
        gripper_->setStartStateToCurrentState();
        gripper_->setNamedTarget("gripper_close");
        PlanAndExecute(gripper_);
    }


private:

    void PlanAndExecute(const std::shared_ptr<MoveGroupInterface> &interface)
    {
        MoveGroupInterface::Plan plan;
        if(interface->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS)
        {
            interface->execute(plan);
        }
    }

    void OpenGripperCallback(const Bool &msg)
    {
        if(msg.data)
        {
            OpenGripper();
        }
        else
        {
            CloseGripper();
        }
    }

    void JointCmdCallback(const FloatArray &msg)
    {
        auto joints = msg.data;
        if(joints.size() == 6)
        {
            GoToJointTarget(joints);
        }
    }

    void PoseCmdCallback(const PoseCmd &msg)
    {
        GoToPoseTarget(msg.x, msg.y, msg.z, msg.roll, msg.pitch, msg.yaw, msg.cartesian_path);
    }

    std::shared_ptr<rclcpp::Node> node_;
    std::shared_ptr<MoveGroupInterface> arm_;
    std::shared_ptr<MoveGroupInterface> gripper_;

    rclcpp::Subscription<Bool>::SharedPtr open_gripper_sub_;
    rclcpp::Subscription<FloatArray>::SharedPtr joint_cmd_sub_;
    rclcpp::Subscription<PoseCmd>::SharedPtr pose_cmd_sub_;

};


int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<rclcpp::Node>("commander");
    auto commander = Commander(node);
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}
