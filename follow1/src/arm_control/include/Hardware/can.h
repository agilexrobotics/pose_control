#ifndef _CAN_H_
#define _CAN_H_

#include <stdint.h>
#include <string.h>
#include <iostream>
#include "../libcan/SocketCAN.h"
#include "../../include/Hardware/motor.h"
#include <ros/ros.h>
#include <ros/package.h>


#define LEFT_WHEEL 1
#define RIGHT_WHEEL 0
#define MOTOR_NUM 8 


typedef struct
{
    float imu[3];  //单位 rad    顺序yaw pitch roll
    float last_imu[3]; //上一时刻的imu角度数据
    float gyro[3]; //单位 rad/s  顺序pitch  roll  yaw
} IMU_Float_t;

typedef struct{
    int8_t   temperature;
    int16_t	 speed_rpm;
    int16_t  real_current;
    uint16_t position;
    int8_t   round_cnt;
    float    total_angle;
    float    total_angle_last;
	
}m_rmd_t;


class can
{
public:
    can();
    ~can();


    void can1_ReceiveFrame(can_frame_t *frame);


    void CAN_cmd_readMotorID(void);
    void CAN_cmd_getMotorParam(uint16_t motor_id, uint8_t param_cmd);
    void CAN_cmd_init(uint16_t motor_id,uint8_t cmd);
    void Can_cmd_position(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status);

    void Send_moto_Cmd1(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor);
    void CAN_cmd_fpc1(float kp[4], float kd[4], float pos[4], float spd[4], float tor[4]);
    void CAN_cmd_fpc2(float kp[4], float kd[4], float pos[4], float spd[4], float tor[4]);
    void MotorSetting(uint16_t motor_id,uint8_t cmd);

    void GetImuAngle(uint8_t *data);
    void GetImuGyro(uint8_t *data);
    // // int freq = 0;
    void CAN_GRIPPER(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);
    //dubuf DM
    void Send_moto_Cmd2(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor);
    void Enable_Moto(uint16_t ID);
    void Set_Zero(uint16_t ID);
    void clear(uint16_t ID);

    void arx_1();
    void arx_2();

private:

    SocketCAN can1_adapter;

};

#endif