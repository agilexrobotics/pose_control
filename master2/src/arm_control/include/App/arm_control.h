#ifndef _ARM_CONTROL_H_
#define _ARM_CONTROL_H_

#include "utility.h"
#include "Hardware/teleop.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "../Hardware/can.h"
#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/Float64MultiArray.h>
#include "../Hardware/motor.h"
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <memory.h>
#include <dirent.h>
#include <vector>
#include <sensor_msgs/JointState.h>
#include "play.h"
#include "solve.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <tinyxml2.h>
#include <string>


#define JOYSTICK_DEADZONE 0.15 
#define filter_torque 0.3f

struct arx5roscmd
{
    float x=0;
    float y=0;
    float z=0;
    float roll=0;
    float pitch=0;
    float yaw=0;
    float gripper=0;
    int mode1=0;
    int mode2=0;

};


struct cartesian
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

struct cylinder
{
    float r = 0.0f;
    float phi = 0.0f;
    float z = 0.0f;
};

struct sphere
{
    float rho = 0.0f;
    float phi = 0.0f;
    float theta = 0.0f;
};

struct coordinate
{
    cartesian xyz_pos;
    cylinder cylinder_pos;
    sphere sphere_pos;
};

class FIFO_Queue
{
public:
    FIFO_Queue(uint queue_size);
    ~FIFO_Queue() = default;
    uint count = 0;
    uint write_ptr = 0, read_ptr = 0;
};

class arx_arm
{
public:
    arx_arm(int CONTROL_MODE);
    ~arx_arm()=default;

    bool is_real = false;
    arx5_state command_state;
    int control_mode=0;

    unsigned int loop_rate = 200;

    float current_pos[7] = {};
  
    int motor_signal_last_t[8] = {};
    float current_vel[7] = {0.0};

    float current_torque[7] = {0.0f};

    float target_pos[7] = {0.0f}, last_target_pos[7] = {0.0f};
    float gripper_pos[1]={};
    float target_pos_temp[7] = {0.0f};
    float target_vel[7] = {0.0f};
    float ros_control_pos[7] ={};
    float ros_control_pos_t[7] ={};
    float ros_control_vel[7] ={};
    float ros_control_cur[7] ={};

    float lower_bound_waist[3] = {  0.0, -0.4, -0.4};
    float upper_bound_waist[3] = {  0.4,  0.4,  0.4};

    float lower_bound_pitch = -1.35;
    float upper_bound_pitch = M_PI/2; 
    float lower_bound_yaw = -1.35;
    float upper_bound_yaw = 1.35;
    float lower_bound_roll = -1.35;
    float upper_bound_roll = 1.35;


    float max_torque = 15;

    float ramp(float final, float now, float ramp_k);
    float joystick_projection(float joy_axis);

    void get_joint();

    void init_step();
    bool is_starting = true,is_arrived = false;
    
    
    float joy_x=0,joy_y=0,joy_z=0,joy_yaw=0,joy_pitch=0,joy_roll=0,joy_gripper=0;
    float joy_x_t=0,joy_y_t=0,joy_z_t=0,joy_yaw_t=0,joy_pitch_t=0,joy_roll_t=0,joy_gripper_t=0;

    std::string model_path; 

    float prev_target_pos[6] = {0};
    bool teach2pos_returning = false;

    void calc_joint_acc();
    ros::NodeHandle nh;

    void rand_step();
    bool is_rand_moving = false;
    bool is_rand_mode = false;
    bool is_rand_return = false;
    bool button5_pressed = false;
    bool button3_pressed = 0;
    bool button0_pressed = 0;
    bool button_teach=0;
    bool button_replay=0;
    bool is_torque_control = false;
    bool is_teach_mode = false;
    bool teach_mode = false;

    bool is_recording=false;
    std::string out_teach_path;

    command get_cmd();
    command arx5_cmd;
    arx5roscmd arx5_ros_cmd;

    float Lower_Joint[7] = { -3.14  ,0      ,-0.1   ,-1.671 ,-1.671,-1.57 ,-9};
    float Upper_Joint[7] = { 2.618 , 3.14   ,3.24, 1.671 , 1.671, 1.57 ,9};

    void safe_model(void);
    void set_zero(void);
    void update(void);
    void update_real(command cmd);
    void motor_control();
    void joint_control();
    void gripper_control();

    int init_end=0,add_pos=0;
    float set_4005_out=0,set_pos_4005 = 0,k1_4005=400,k2_4005=3,init_pos_4005=0,pos_4005_t=0;
    can CAN_Handlej;
    arx5_play play;
    arx_solve solve;
    std::vector<std::string> play_file_list;
    std::vector<std::string> teach_file_list;
    bool current_normal=true;

    int temp_init=0;
    float init_kp=0,init_kp_4=0,init_kp_5=0,init_kd=0,init_kd_4=0,init_kd_6=0;

    int rosGetch();
    void getKey(char key_t);
    float gripper_cout=0,gripper_spd,gripper_max_cur=50;
    int restart_flag=0;
    float ros_move_k_x=100.0f,ros_move_k_y=100.0f,ros_move_k_z=100.0f,ros_move_k_yaw=100.0f,ros_move_k_pitch=100.0f,ros_move_k_roll=100.0f;
    void arm_replay_mode();
    void arm_torque_mode();
    void arm_reset_mode();
    void arm_get_pos();
    void arm_teach_mode();  
    void limit_pos();   
    void cmd_init();
    int play_gripper=0;
    void limit_joint(float* Set_Pos);
    int teach_flag=0;
    float J13_KP=150,J13_KD=1;
private:

    float test_pos = 0;
    uint test_cnt = 0;

};

#endif