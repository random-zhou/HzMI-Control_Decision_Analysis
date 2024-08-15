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
// IMU.h - 这个文件是IMU（惯性测量单元）数据处理模块的头文件。

#ifndef _IMU_H // 检查_IMU_H宏是否已经定义，以防止头文件被重复包含。
#define _IMU_H

#include "main.h" // 包含主程序文件，通常包含全局变量和初始化代码。
#include "MPU6050.h" // 包含MPU6050传感器的头文件，该文件可能包含与MPU6050通信和数据处理相关的宏定义、类型定义和函数原型。

// 外部变量声明，这些变量在其他文件中定义，并用于存储IMU数据处理后的姿态角度。
extern float FilterPitch; // 存储滤波后的俯仰角（Pitch）。
extern float FilterRoll;   // 存储滤波后的横滚角（Roll）。
extern float FilterYaw;    // 存储滤波后的偏航角（Yaw）。

/*************************
 * 函数原型：IMU_Update
 * 功能描述：该函数用于根据陀螺仪和加速度计的最新数据更新IMU的姿态估计。
 * 输入参数：
 *    gyrox - X轴陀螺仪的角速度数据。
 *    gyroy - Y轴陀螺仪的角速度数据。
 *    gyroz - Z轴陀螺仪的角速度数据。
 *    accx  - X轴加速度计的数据。
 *    accy  - Y轴加速度计的数据。
 *    accz  - Z轴加速度计的数据。
 *************************/
void IMU_Update(float gyrox, float gyroy, float gyroz, float accx, float accy, float accz);

#endif // _IMU_H