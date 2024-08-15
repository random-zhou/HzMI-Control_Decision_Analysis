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
#ifndef __MPU6050_H // 检查MPU6050_H宏是否已经定义，防止头文件被重复包含
#define __MPU6050_H

#include "main.h" // 包含主程序文件，通常包含全局变量和初始化代码

// 以下是MPU6050寄存器地址定义
#define SMPLRT_DIV   0x19  // 采样率分频寄存器，典型值：0x07(125Hz)
#define CONFIG       0x1A  // 低通滤波频率配置寄存器，典型值：0x06(5Hz)
#define GYRO_CONFIG  0x1B  // 陀螺仪配置寄存器，典型值：0x18(不自检�?2000deg/s)
#define ACCEL_CONFIG 0x1C  // 加速度计配置寄存器，典型值：0x01(不自检�?2G�?5Hz)

#define ACCEL_XOUT_H 0x3B  // X轴加速度�?8位数据寄存器
#define ACCEL_XOUT_L 0x3C  // X轴加速度�?8位数据寄存器
#define ACCEL_YOUT_H 0x3D  // Y轴加速度�?8位数据寄存器
#define ACCEL_YOUT_L 0x3E  // Y轴加速度�?8位数据寄存器
#define ACCEL_ZOUT_H 0x3F  // Z轴加速度�?8位数据寄存器
#define ACCEL_ZOUT_L 0x40  // Z轴加速度�?8位数据寄存器

#define TEMP_OUT_H   0x41  // 温度传感器高8位数据寄存器
#define TEMP_OUT_L   0x42  // 温度传感器低8位数据寄存器

#define GYRO_XOUT_H  0x43  // X轴陀螺仪�?8位数据寄存器
#define GYRO_XOUT_L  0x44  // X轴陀螺仪�?8位数据寄存器
#define GYRO_YOUT_H  0x45  // Y轴陀螺仪�?8位数据寄存器
#define GYRO_YOUT_L  0x46  // Y轴陀螺仪�?8位数据寄存器
#define GYRO_ZOUT_H  0x47  // Z轴陀螺仪�?8位数据寄存器
#define GYRO_ZOUT_L  0x48  // Z轴陀螺仪�?8位数据寄存器

#define PWR_MGMT_1   0x6B  // 电源管理寄存器，典型值：0x00(正常启用)
#define WHO_AM_I     0x75  // IIC地址寄存器，用于验证连接的设备，默认数�?0x68，只�?
#define MPU6050_ADDR 0xD0  // MPU6050手册上的I2C地址

// 定义MPU6050数据结构体，包含加速度、角速度和温度数�?
typedef struct {
    float Accel[3];  // 三轴加速度数据数组
    float Gyro[3];   // 三轴角速度数据数组
    float Temp;      // 温度数据
    uint8_t MPU6050dt; // 数据更新间隔
    uint64_t preMillis; // 上次数据更新的时间戳
    float MPU6050ERROE[6]; // 误差估计数组
} MPU6050DATATYPE;

// 声明外部MPU6050数据结构体变量和I2C句柄变量
extern MPU6050DATATYPE Mpu6050_Data;
extern I2C_HandleTypeDef hi2c1;

// 函数原型声明
int16_t Sensor_I2C1_Serch(void); // 搜索I2C设备地址的函�?
int8_t MPU6050_Init(int16_t Addr); // 初始化MPU6050传感器的函数

int8_t Sensor_I2C1_ReadOneByte(uint16_t DevAddr, uint16_t MemAddr, uint8_t *oData); // 从I2C设备读取单字节数据的函数
int8_t Sensor_I2C1_WriteOneByte(uint16_t DevAddr, uint16_t MemAddr, uint8_t *iData); // 向I2C设备写入单字节数据的函数

void getMPU6050Data(void); // 获取MPU6050传感器数据的函数
void dataGetERROR(void); // 计算数据误差的函�?
void MPU6050_Read_Accel(void); // 从MPU6050读取加速度数据的函�?
void MPU6050_Read_Gyro(void); // 从MPU6050读取角速度数据的函�?
void MPU6050_Read_Temp(void); // 从MPU6050读取温度数据的函�?

#endif // __MPU6050_H