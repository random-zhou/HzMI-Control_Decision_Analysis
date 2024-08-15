/**
  ****************************(C) COPYRIGHT 2024 HzMI****************************
  * @file       MPU6050.c/h
  * @brief      
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Aug-15-2024      ZGY              1. done
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2024 HZMI****************************
  */
// IMU.c - 该文件包含了处理IMU（惯性测量单元）数据的函数。

#include <math.h>  // 引入标准数学库，以便使用数学函数如sqrt和atan2。
#include "Quaternion.h"  // 引入四元数相关的头文件，可能包含四元数操作的函数和定义。

// 宏定义，用于将弧度转换为角度，以及将角度转换为弧度。
#define RtA 57.295779f  // 弧度到角度的转换系数。
#define AtR 0.0174533f  // 角度到弧度的转换系数。

// 以下宏定义被注释掉，它们可能用于调整加速度计和陀螺仪的比例因子。
// #define Acc_G       0.0011963f
// #define Gyro_G      0.0610351f
// #define Gyro_Gr     0.0010653f

// 定义滤波器的增益系数，Kp影响滤波器对加速度计的信任程度，Ki是积分增益。
#define Kp 18.0f  // 比例增益，数值越大，表示越信任加速度计数据。
#define Ki 0.008f  // 积分增益。

// 声明外部变量，这些变量可能在其他文件中定义。
extern float p;
extern float i;

// 定义时间周期的一半，用于简化积分计算。
#define halfT 0.0025f

// 定义四元数的初始值和积分误差变量，四元数用于表示IMU的姿态。
float q0 = 1, q1 = 0, q2 = 0, q3 = 0;
float exInt = 0, eyInt = 0, ezInt = 0;

// 定义滤波器最终输出的角度，分别表示俯仰角（Pitch）、横滚角（Roll）和偏航角（Yaw）。
float FilterPitch = 0, FilterRoll = 0, FilterYaw = 0;

// 声明用于计算偏航角的变量。
float imuyaw, imuyawlast, iyaw, imux;

// IMU_Update函数，根据陀螺仪和加速度计的输入数据更新IMU姿态。
void IMU_Update(float gyrox, float gyroy, float gyroz, float accx, float accy, float accz) {
    // 将输入的加速度计和陀螺仪数据分别赋值给局部变量。
    float ax = accx, ay = accy, az = accz;
    float gx = gyrox, gy = gyroy, gz = gyroz;

    // 计算四元数的乘积项。
    float q0q0 = q0 * q0;
    float q0q1 = q0 * q1;
    float q0q2 = q0 * q2;
    float q1q1 = q1 * q1;
    float q1q3 = q1 * q3;
    float q2q2 = q2 * q2;
    float q2q3 = q2 * q3;
    float q3q3 = q3 * q3;

    // 当加速度传感器在任意方向上的测量值为0时，返回，避免除以0。
    if (ax * ay * az == 0)
        return;

    // 注释掉的部分可能是用于调整陀螺仪数据的比例因子。
    // gx *= Gyro_Gr;
    // gy *= Gyro_Gr;
    // gz *= Gyro_Gr;

    // 将陀螺仪的角速度数据从度/秒转换为弧度/秒。
    gx *= AtR;
    gy *= AtR;
    gz *= AtR;

    // 归一化加速度计数据，得到重力方向的单位向量。
    float norm = sqrt(ax * ax + ay * ay + az * az);
    ax = ax / norm;
    ay = ay / norm;
    az = az / norm;

    // 根据当前四元数和角速度计算估计的角速度方向。
    float vx = 2 * (q1 * q3 - q0 * q2);
    float vy = 2 * (q0 * q1 + q2 * q3);
    float vz = q0q0 - q1q1 - q2q2 + q3q3;

    // 计算参考方向和传感器测量方向之间的误差。
    ex = (ay * vz - az * vy);
    ey = (az * vx - ax * vz);
    ez = (ax * vy - ay * vx);

    // 积分误差，用于消除系统偏差。
    exInt = exInt + ex * Ki;
    eyInt = eyInt + ey * Ki;
    ezInt = ezInt + ez * Ki;

    // 根据比例-积分-微分（PID）控制调整陀螺仪数据。
    gx = gx + Kp * ex + exInt;
    gy = gy + Kp * ey + eyInt;
    gz = gz + Kp * ez + ezInt;

    // 根据调整后的角速度数据更新四元数。
    q0 = q0 + (-q1 * gx - q2 * gy - q3 * gz) * halfT;
    q1 = q1 + (q0 * gx + q2 * gz - q3 * gy) * halfT;
    q2 = q2 + (q0 * gy - q1 * gz + q3 * gx) * halfT;
    q3 = q3 + (q0 * gz + q1 * gy - q2 * gx) * halfT;

    // 四元数归一化，确保其长度为1。
    norm = sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
    q0 = q0 / norm;
    q1 = q1 / norm;
    q2 = q2 / norm;
    q3 = q3 / norm;

    // 根据四元数计算Pitch、Roll和Yaw角度。
    // 注释掉的部分是原始的Yaw计算方式。
    // FilterYaw  = atan2(2 * q1 * q2 + 2 * q0 * q3, -2 * q2*q2 - 2 * q3* q3 + 1) * RtA;           // yaw
    FilterPitch = asin(-2 * q1 * q3 + 2 * q0 * q2) * RtA; // pitch
    FilterRoll = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * RtA; // roll


}