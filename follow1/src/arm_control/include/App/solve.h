#ifndef _solve_H_
#define _solve_H_
  
#include "../utility.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
// #include <Eigen/Core>
#include <string.h>

#include <time.h>
#include <iostream>
#include <fstream>
#include <memory.h>
#include <dirent.h>
#include <vector>


enum arx5_state {NORMAL, OUT_RANGE, OUT_BOUNDARY};

#define FORWARD 0
#define DOWNWARD 1

#define filter_cmd    0.3f
#define PI 3.1415926

struct command
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float base_yaw = 0.0f;
    float waist_roll = 0.0f;
    float gripper = 0.0f;
    float waist_yaw = 0.0f;
    float waist_pitch = 0.0f;
    bool reset = false;
    int mode = FORWARD;
    float x_t,y_t,z_t,waist_roll_t,gripper_t,base_yaw_t=0,waist_yaw_t,waist_pitch_t;
    float key_x=0,key_y=0,key_z=0,key_roll=0,key_gripper=0,key_base_yaw=0,key_yaw=0,key_pitch=0;
    int key_x_t=0,key_y_t=0,key_z_t=0,key_roll_t=0,key_gripper_t=0,key_base_yaw_t=0,key_yaw_t=0,key_pitch_t=0;

    bool key_reset,key_i,key_p,key_o,key_c,key_t,key_g,key_m;
    int key_reset_t=0,key_i_t=0,key_p_t=0,key_o_t=0,key_c_t=0,key_t_t=0,key_g_t=0,key_m_t=0;

    bool key_u,key_j,key_h,key_k,key_v,key_b;
    int key_u_t=0,key_j_t=0,key_h_t=0,key_k_t=0,key_v_t=0,key_b_t=0;   

    // bool key_pit,key_yaw,key_n,key_ya,key_yb,key_pb;
    // int key_l_t=0,key_m_t=0,key_n_t=0,key_ya_t=0,key_yb_t=0,key_pb_t=0;   

    float reset_k=0.0001;
    float control_x=0,control_y=0,control_z=0,control_pit=0,control_yaw=0,control_roll=0;
    float pre_control_x=0,pre_control_y=0,pre_control_z=0,pre_control_pit=0,pre_control_yaw=0,pre_control_roll=0;

};

class arx_solve
{


public:
    arx_solve(void);
    ~arx_solve()=default;

    // Inverse kinamics calculation parameters


    // ros::NodeHandle nh;

    // ros::Publisher pos_pub = nh.advertise<geometry_msgs::Vector3>("armcontrol/current_pos", 10);
    // ros::Publisher vel_pub = nh.advertise<geometry_msgs::Vector3>("armcontrol/current_vel", 10);
    // ros::Publisher ang_pub = nh.advertise<geometry_msgs::Vector3>("armcontrol/current_angle", 10);

    float kx = 100;
    float ky = 100;
    float kz = 400;
    float kroll = 0;
    float kpitch = 400;
    float kyaw = 100;

    float kdx = 20;
    float kdy = 20;
    float kdz = 20;
    float kdroll = 0;
    float kdpitch = 20;
    float kdyaw = 10;

    double eps=1E-5;
    int maxiter=500;
    double eps_joints=1E-15;

    float Lower_Joint[7] = { -3.14  ,-0.1      ,-0.1   ,-1.571 ,-1.571,-6.28 ,-9};
    float Upper_Joint[7] = { 2.618 , 3.14   ,3.14, 1.571 , 1.571 , 6.28 ,9};

    // Save the coordinates on previous round
    float prev_x = 0, prev_y = 0, prev_z = 0, prev_roll = 0, prev_pitch = 0, prev_yaw = 0, prev_base_yaw = 0;

    void solve_init(std::string file_list_t);
    void calc_joint_acc(command arx_cmd_t);
    void arm_calc1(command arx_cmd_t,float *back_pos,bool control_mode_t);
    arx5_state arm_calc2(command arx_cmd_t,float *back_pos,float *send_pos,bool control_mode_t,float gripper);

    // arx5_state arm_calc2(command arx_cmd_t,float *back_pos,float *send_pos,bool control_mode_t);
    bool all_in_range =true;
    float jointpositions_t[7]={};
    // 假设所有关节位置都为0
    int all_zeros = 1;
    // 初始化计算完成标志变量
    int calc_done_t = 0;
    void send_pos(float * get_pos,float * send_pos);
    float joint_torque[7]={};
    float End_Effector_Pose[6]={};
    float ramp(float goal, float current, float ramp_k);
    void init_pos(float* target_pos, float* current_pos,float * target_pos_temp,bool &is_starting,bool &is_arrived ,bool &teach2pos_returning,int &temp_init);
    // void init_pos(float* target_pos, float* current_pos,float * target_pos_temp,bool* is_starting,bool* is_arrived ,bool* teach2pos_returning,int* temp_init);

    void send_pos_v(float * get_pos,float * send_pos, float * send_vel);

    int calc_init=0;



private:

    float pos_filted[3], vel_filted[3];

};

#endif