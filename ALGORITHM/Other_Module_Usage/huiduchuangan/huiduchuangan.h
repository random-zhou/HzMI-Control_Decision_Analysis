/**
  ****************************(C) COPYRIGHT 2024 HzMI****************************
  * @file       huiduchuangan.c/h
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
// 定义防止头文件被重复包含的宏
#ifndef __HUDUCHUANGAN_H
#define __HUDUCHUANGAN_H

// 定义8个灰度传感器的端口宏，具体的端口值需要在别处定义
#define port1   HUIDU_PORT
#define port2   HUIDU_PORT
#define port3   HUIDU_PORT
#define port4   HUIDU_PORT
#define port5   HUIDU_PORT
#define port6   HUIDU_PORT
#define port7   HUIDU_PORT
#define port8   HUIDU_PORT

// 定义8个灰度传感器的引脚宏，具体的引脚值需要在别处定义
#define pin1    HUIDU_H1_PIN
#define pin2    HUIDU_H2_PIN
#define pin3    HUIDU_H3_PIN
#define pin4    HUIDU_H4_PIN
#define pin5    HUIDU_H5_PIN
#define pin6    HUIDU_H6_PIN
#define pin7    HUIDU_H7_PIN
#define pin8    HUIDU_H8_PIN

// 定义8个灰度传感器电平值读取的宏，使用三元运算符根据DL_GPIO_readPins函数的返回值确定电平状态
#define value1  (DL_GPIO_readPins(port1,pin1))>0?(1):(0)
#define value2  (DL_GPIO_readPins(port2,pin2))>0?(1):(0)
#define value3  (DL_GPIO_readPins(port3,pin3))>0?(1):(0)
#define value4  (DL_GPIO_readPins(port4,pin4))>0?(1):(0)
#define value5  (DL_GPIO_readPins(port5,pin5))>0?(1):(0)
#define value6  (DL_GPIO_readPins(port6,pin6))>0?(1):(0)
#define value7  (DL_GPIO_readPins(port7,pin7))>0?(1):(0)
#define value8  (DL_GPIO_readPins(port8,pin8))>0?(1):(0)

// 定义灰度传感器的传感器个数为8
#define huidu_length 8

// 定义灰度传感器的扫描模式宏
#define none_mode           0  // 无扫描模式
#define increase_mode       1  // 递增扫描模式
#define decrease_mode       2  // 递减扫描模式

// 函数原型声明，通过灰度传感器的状态值判断当前误差，返回一个int16_t类型的值
int16_t error_judge(uint8_t a[]);

// 函数原型声明，读取灰度传感器引脚的电平值，返回一个uint8_t类型的值
uint8_t hd_gpio_read(uint8_t i);

// 函数原型声明，扫描灰度传感器现在状态，并将状态存储到数组中
void huidu_scan(void);

#endif // __HUDUCHUANGAN_H