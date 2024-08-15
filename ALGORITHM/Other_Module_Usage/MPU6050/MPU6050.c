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
#include "MPU6050.h"

// 声明MPU6050的I2C地址变量，初始值设为0x68
static int16_t Mpu6050Addr = 0x68;
// 声明MPU6050数据结构体变量，用于存储传感器数据
MPU6050DATATYPE Mpu6050_Data;

/**
 * @brief 从I2C设备读取数据
 * @param DevAddr 设备地址
 * @param MemAddr 内存地址
 * @param oData   输出数据缓冲区
 * @param DataLen 数据长度
 * @return I2C操作状态
 */
int8_t Sensor_I2C1_Read(uint16_t DevAddr, uint16_t MemAddr, uint8_t *oData, uint8_t DataLen) {
    return HAL_I2C_Mem_Read(&hi2c1, DevAddr, MemAddr, 1, oData, DataLen, 1000); // 调用HAL库函数进行I2C读取
}

/**
 * @brief 向I2C设备写入数据
 * @param DevAddr 设备地址
 * @param MemAddr 内存地址
 * @param iData   输入数据缓冲区
 * @param DataLen 数据长度
 * @return I2C操作状态
 */
int8_t Sensor_I2C1_Write(uint16_t DevAddr, uint16_t MemAddr, uint8_t *iData, uint8_t DataLen) {
    return HAL_I2C_Mem_Write(&hi2c1, DevAddr, MemAddr, 1, iData, DataLen, 1000); // 调用HAL库函数进行I2C写入
}

/**
 * @brief 在I2C总线上搜索MPU6050设备
 * @return 找到的设备地址或错误代码0xD1
 */
int16_t Sensor_I2C1_Serch(void) {
    for(uint8_t i = 1; i < 255; i++) {
        if(HAL_I2C_IsDeviceReady(&hi2c1, i, 1, 1000) == HAL_OK) {
            Mpu6050Addr = i;
            return i; // 返回找到的设备地址
        }
    }
    return 0xD1; // 如果没有找到设备，返回错误代码
}

/**
 * @brief 初始化MPU6050传感器
 * @param Addr MPU6050的I2C地址
 * @return 初始化状态，0表示成功，-1表示失败
 */
int8_t MPU6050_Init(int16_t Addr) {
    uint8_t check;
    HAL_I2C_Mem_Read(&hi2c1, Addr, WHO_AM_I, 1, &check, 1, 1000); // 读取WHO_AM_I寄存器验证设备
    if(check == 0x68) {
        check = 0x00;
        Sensor_I2C1_Write(Addr, PWR_MGMT_1, &check, 1); // 唤醒MPU6050
        check = 0x07;
        Sensor_I2C1_Write(Addr, SMPLRT_DIV, &check, 1); // 设置采样率为1KHz
        check = 0x00;
        Sensor_I2C1_Write(Addr, ACCEL_CONFIG, &check, 1); // 设置加速度量程为±2g
        check = 0x00;
        Sensor_I2C1_Write(Addr, GYRO_CONFIG, &check, 1); // 设置陀螺量程为±250°/s
        
        Mpu6050_Data.MPU6050dt = 10; // 设置数据更新间隔
        Mpu6050_Data.preMillis = 0; // 初始化上次数据时间戳
        // 初始化误差数组
        for(uint8_t i = 0; i < 6; ++i) {
            Mpu6050_Data.MPU6050ERROE[i] = 0;
        }
        return 0; // 返回成功代码
    }
    return -1; // 返回失败代码
}

// 读取MPU6050加速度传感器数据的函数
void MPU6050_Read_Accel(void) {
    uint8_t Read_Buf[6];
    Sensor_I2C1_Read(Mpu6050Addr, ACCEL_XOUT_H, Read_Buf, 6); // 读取加速度数据
    Mpu6050_Data.Accel[0] = (int16_t)(Read_Buf[0] << 8 | Read_Buf[1]); // 转换X轴加速度值
    Mpu6050_Data.Accel[1] = (int16_t)(Read_Buf[2] << 8 | Read_Buf[3]); // 转换Y轴加速度值
    Mpu6050_Data.Accel[2] = (int16_t)(Read_Buf[4] << 8 | Read_Buf[5]); // 转换Z轴加速度值

    // 将加速度值转换为实际的g（9.8m/s^2）
    Mpu6050_Data.Accel[0] = Mpu6050_Data.Accel[0] / 16384.0f;
    Mpu6050_Data.Accel[1] = Mpu6050_Data.Accel[1] / 16384.0f;
    Mpu6050_Data.Accel[2] = Mpu6050_Data.Accel[2] / 16384.0f;
}

// 读取MPU6050陀螺仪传感器数据的函数
void MPU6050_Read_Gyro(void) {
    uint8_t Read_Buf[6];
    Sensor_I2C1_Read(Mpu6050Addr, GYRO_XOUT_H, Read_Buf, 6); // 读取陀螺仪数据
    Mpu6050_Data.Gyro[0] = (int16_t)(Read_Buf[0] << 8 | Read_Buf[1]); // 转换X轴陀螺仪值
    Mpu6050_Data.Gyro[1] = (int16_t)(Read_Buf[2] << 8 | Read_Buf[3]); // 转换Y轴陀螺仪值
    Mpu6050_Data.Gyro[2] = (int16_t)(Read_Buf[4] << 8 | Read_Buf[5]); // 转换Z轴陀螺仪值

    // 将陀螺仪值转换为实际的角度每秒
    Mpu6050_Data.Gyro[0] = Mpu6050_Data.Gyro[0] / 131.0f;
    Mpu6050_Data.Gyro[1] = Mpu6050_Data.Gyro[1] / 131.0f;
    Mpu6050_Data.Gyro[2] = Mpu6050_Data.Gyro[2] / 131.0f;
}

// 读取MPU6050温度传感器数据的函数
void MPU6050_Read_Temp(void) {
    uint8_t Read_Buf[2];
    Sensor_I2C1_Read(Mpu6050Addr, TEMP_OUT_H, Read_Buf, 2); // 读取温度数据
    Mpu6050_Data.Temp = (int16_t)(Read_Buf[0] << 8 | Read_Buf[1]); // 转换温度值

    // 将原始温度值转换为摄氏度
    Mpu6050_Data.Temp = 36.53f + (Mpu6050_Data.Temp / 340.0f);
}

// 获取MPU6050传感器数据的函数
void getMPU6050Data() {
    MPU6050_Read_Temp(); // 获取温度数据
    MPU6050_Read_Accel(); // 获取加速度数据
    MPU6050_Read_Gyro(); // 获取陀螺仪数据
}

// 计算传感器数据误差的函数
void dataGetERROR() {
    for(uint8_t i = 0; i < 100; ++i) {
        MPU6050_Read_Temp();
        MPU6050_Read_Accel();
        MPU6050_Read_Gyro();
        Mpu6050_Data.MPU6050ERROE[0] += Mpu6050_Data.Accel[0];
        Mpu6050_Data.MPU6050ERROE[1] += Mpu6050_Data.Accel[1];
        Mpu6050_Data.MPU6050ERROE[2] += Mpu6050_Data.Accel[2] - 9.8f; // 减去重力加速度
        Mpu6050_Data.MPU6050ERROE[3] += Mpu6050_Data.Gyro[0];
        Mpu6050_Data.MPU6050ERROE[4] += Mpu6050_Data.Gyro[1];
        Mpu6050_Data.MPU6050ERROE[5] += Mpu6050_Data.Gyro[2];
        HAL_Delay(10); // 等待10ms
    }
    // 计算误差平均值
    for(uint8_t i = 0; i < 6; ++i) {
		Mpu6050_Data.MPU6050ERROE[i] /= 100.0f;
	}
}