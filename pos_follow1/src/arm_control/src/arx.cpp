#include <ros/ros.h>
#include <cmath>
#include <iostream>
#include <std_msgs/Float32MultiArray.h>
#include "utility.h"
#include "Hardware/can.h"
#include "Hardware/motor.h"
#include "Hardware/teleop.h"
#include "App/arm_control.h"
// #include "App/arm_control.cpp"
#include "App/keyboard.h"
#include "App/play.h"
#include "App/solve.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <thread>
#include <atomic>
#include <signal.h>
// #include "arm_control/PosCmd.h"
// #include "arm_control/JointControl.h"
// #include "arm_control/JointInformation.h"
// #include "arm_control/ChassisCtrl.h"
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/JointState.h>
int CONTROL_MODE=1; 
command cmd;

bool app_stopped = false;
void sigint_handler(int sig);
void safe_stop(can CAN_Handlej);

int main(int argc, char **argv)
{
    ros::init(argc, argv, "arm_node2"); 
    ros::NodeHandle node;
    Teleop_Use()->teleop_init(node);

    arx_arm ARX_ARM((int) CONTROL_MODE);

            // ros::Subscriber sub_pos = node.subscribe<arm_control::PosCmd>("master1_pos_back", 10, 
            //                             [&ARX_ARM](const arm_control::PosCmd::ConstPtr& msg) {
            //                                     ARX_ARM.arx5_cmd.x            = msg->x;
            //                                     ARX_ARM.arx5_cmd.y            = msg->y;
            //                                     ARX_ARM.arx5_cmd.z            = msg->z;
            //                                     ARX_ARM.arx5_cmd.waist_roll   = msg->roll;
            //                                     ARX_ARM.arx5_cmd.waist_pitch  = msg->pitch;
            //                                     ARX_ARM.arx5_cmd.waist_yaw    = msg->yaw;
            //                                     ARX_ARM.arx5_cmd.gripper      = msg-> gripper;

            //                             });


            // ros::Publisher pub_current = node.advertise<arm_control::JointInformation>("joint_information", 10);
            // ros::Publisher pub_pos = node.advertise<arm_control::PosCmd>("/follow1_pos_back", 10);
            

    ros::Subscriber sub_pos = node.subscribe<geometry_msgs::PoseStamped>("/master/end_right", 10, 
                                [&ARX_ARM](const geometry_msgs::PoseStamped::ConstPtr& msg) {
                                        ARX_ARM.arx5_cmd.x            = msg->pose.position.x;
                                        ARX_ARM.arx5_cmd.y            = msg->pose.position.y;
                                        ARX_ARM.arx5_cmd.z            = msg->pose.position.z;
                                        ARX_ARM.arx5_cmd.waist_roll   = msg->pose.orientation.x;
                                        ARX_ARM.arx5_cmd.waist_pitch  = msg->pose.orientation.y;
                                        ARX_ARM.arx5_cmd.waist_yaw    = msg->pose.orientation.z;
                                        ARX_ARM.arx5_cmd.gripper      = msg->pose.orientation.w;
                                });
    ros::Publisher pub_current = node.advertise<sensor_msgs::JointState>("/puppet/joint_right", 10);
    ros::Publisher pub_pos = node.advertise<geometry_msgs::PoseStamped>("/puppet/end_right", 10);
                            



    arx5_keyboard ARX_KEYBOARD;

    ros::Rate loop_rate(200);
    can CAN_Handlej;

    std::thread keyThread(&arx5_keyboard::detectKeyPress, &ARX_KEYBOARD);
    sleep(1);

    while(ros::ok())
    { 

        char key = ARX_KEYBOARD.keyPress.load();
        ARX_ARM.getKey(key);

        ARX_ARM.get_joint();
        // if(!ARX_ARM.is_starting){
        //      cmd = ARX_ARM.get_cmd();
        // }
        ARX_ARM.update_real(cmd);
    
////topic ////////////////////////////////////////////////////
                    // //发送关节数据
                    //             arm_control::JointInformation msg_joint;   

                    //             for(int i=0;i<7;i++)
                    //             {
                    //                 msg_joint.joint_pos[i] = ARX_ARM.current_pos[i];
                    //                 msg_joint.joint_vel[i] = ARX_ARM.current_vel[i];
                    //                 msg_joint.joint_cur[i] = ARX_ARM.current_torque[i];
                    //             }    

                    //             pub_current.publish(msg_joint);

                    // //发送末端姿态
                    //             arm_control::PosCmd msg_pos_back;            
                    //             msg_pos_back.x      =ARX_ARM.fk_end_pos[0];
                    //             msg_pos_back.y      =ARX_ARM.fk_end_pos[1];
                    //             msg_pos_back.z      =ARX_ARM.fk_end_pos[2];
                    //             msg_pos_back.roll   =ARX_ARM.fk_end_pos[3];
                    //             msg_pos_back.pitch  =ARX_ARM.fk_end_pos[4];
                    //             msg_pos_back.yaw    =ARX_ARM.fk_end_pos[5];
                    //             msg_pos_back.gripper=ARX_ARM.current_pos[6];

                    //             pub_pos.publish(msg_pos_back);     

       sensor_msgs::JointState msg_joint;
        msg_joint.header.stamp = ros::Time::now();
        int8_t num_joint = 7;
        msg_joint.name.resize(num_joint);
        msg_joint.velocity.resize(num_joint);
        msg_joint.position.resize(num_joint);
        msg_joint.effort.resize(num_joint);
        for(int i=0;i<7;i++)
        {
            msg_joint.name[i] = "joint" + std::to_string(i);
            msg_joint.position[i] = ARX_ARM.current_pos[i];
            msg_joint.velocity[i] = ARX_ARM.current_vel[i];
            msg_joint.effort[i] = ARX_ARM.current_torque[i];
        }
        pub_current.publish(msg_joint);

        geometry_msgs::PoseStamped msg_pos_back;
        msg_pos_back.header.stamp = msg_joint.header.stamp;
        msg_pos_back.pose.position.x      =ARX_ARM.fk_end_pos[0];
        msg_pos_back.pose.position.y      =ARX_ARM.fk_end_pos[1];
        msg_pos_back.pose.position.z      =ARX_ARM.fk_end_pos[2];
        msg_pos_back.pose.orientation.x   =ARX_ARM.fk_end_pos[3];
        msg_pos_back.pose.orientation.y   =ARX_ARM.fk_end_pos[4];
        msg_pos_back.pose.orientation.z   =ARX_ARM.fk_end_pos[5];
        msg_pos_back.pose.orientation.w   =ARX_ARM.current_pos[6];
        pub_pos.publish(msg_pos_back);      

////topic ////////////////////////////////////////////////////


        ros::spinOnce();
        loop_rate.sleep();

        CAN_Handlej.arx_1();
        
    }
    CAN_Handlej.arx_2();
    return 0;
}

