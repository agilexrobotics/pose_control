#ifndef _L_SOLVE_H_
#define _L_SOLVE_H_

#include "../src/Eigen/Dense"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using namespace Eigen;

void test();

#define pi 3.1415926

class ARXARM
{

public:
    ARXARM(void);
    ~ARXARM() = default;


float l1 = 0;
float l2 = 0.264;
float l3 = 0.252;

float end2zero = 0.165; //+ 0.123;   //末端到腕心
float alpha[6] = {pi / 2, 0, 0, -pi / 2, pi / 2, 0};

float a[6] = {0.02, -0.264, 0.252, 0.06775, 0.0, 0};

float d[6] = {0.0, 0.0, 0.0, 0.0, 0.0, end2zero};

float grivty_joint_tor[6] = {0};
float grivty_motor_tor[6] = {0};
void l5_get_Tau(float q[6], float g_tor[6]);

void V_2_T(float end_pos_ori[6], float T[4][4]);

void T_2_V(float T[4][4], float end_pos_ori[6]);

void V_2_T_rpy(float end_pos_ori[6], float T[4][4]);

void fk(float q[6], float T[4][4]);

void my_invT(float T[4][4], float Tinv[4][4]);

void my_tr2dlta(float A[4][4], float B[4][4], float dlt[6]);

void my_get_jacobe(float q_[6], float jc[6][6]);

void ik_LM(float T_desir[4][4], float q0[6], float q_ik[6]);

float q0_test[6]={0}, q0_test1[6]={0};

bool is_in_workspace(float q[6]);
void l5_ik_lm(float q0[6], float endstate_[6], float jointstate[6]);
void l5_fk(float q[6], float send_end[6]);


};

#endif
