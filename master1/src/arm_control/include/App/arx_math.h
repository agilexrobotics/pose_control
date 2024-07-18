#ifndef _ARX_MATH_H_
#define _ARX_MATHH_
  
#include <math.h>
#include <stdio.h>

#define pi 3.1415926



void gq_say();


void my_GetRPY(float R[3][3], float rpy[3]);


void get_dh_T(float a, float alpha, float d, float q, float R[4][4]);


void get_dh_R(float a, float alpha, float d, float q, float R[3][3]);


void get_mdh_T(float a, float alpha, float d, float q, float R[4][4]);

void get_mdh_R(float a, float alpha, float d, float q, float R[3][3]);

void R_rot_xyz (float roll,float pitch,float yaw, float Rx[3][3], float Ry[3][3], float Rz[3][3]);

void T_2_R(float T[4][4], float R[3][3]);


void T_2_P(float T[4][4], float P[3]);


void R_dot_P(float R[3][3], float P[3], float relt[3]);


void J_dot_P(float R[6][6], float P[6], float relt[6]);

void R_trans(float R[3][3], float Rt[3][3]);


void jcb_trans(float J[6][6], float Jt[6][6]);


    


void P_cros_P(float a[3], float b[3], float c[3]);

// 计算两个4x4矩阵的点乘


void J_dot_J(float matrixA[6][6], float matrixB[6][6], float result[6][6]) ;

void T_dot_T(float matrixA[4][4], float matrixB[4][4], float result[4][4]) ;

void R_dot_R(float matrixA[3][3], float matrixB[3][3], float result[3][3]) ;



void prt_jab(float matrix[6][6]);


void prt_R(float matrix[3][3]);


void prt_T(float matrix[4][4]);


void prt_P(float matrix[3]);





#endif