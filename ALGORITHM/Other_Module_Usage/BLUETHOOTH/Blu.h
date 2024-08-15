/**
  ****************************(C) COPYRIGHT 2024 HzMI****************************
  * @file       Blu.c/h
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
#ifndef BLU_H // 检查BLU_H宏是否已经定义，如果已定义则不执行下面的代码
#define BLU_H // 定义BLU_H宏，防止头文件被重复包含

#include "stdarg.h" // 包含可变参数列表的头文件
#include "main.h" // 包含主程序的头文件，可能包含全局变量和初始化代码
#include "stm32f4xx_hal_uart.h" // 包含用于STM32F4系列微控制器的HAL库中的UART模块的头文件

// 声明外部的UART句柄，这个句柄在别的地方定义，并在本文件中使�?
extern UART_HandleTypeDef huart1;

// 函数声明
// 初始化串口接收中断的函数
void BluRxUartInit(void);

// 处理串口接收数据包的函数
// 参数�?
// beginwith: 数据包开始的标识
// endwith: 数据包结束的标识
// datalength: 需要接收的数据长度
// 返回值：接收状态（1-接收完成�?0-接收未完成或失败�?
uint8_t BluRxHandle(uint8_t beginwith, uint8_t endwith, uint8_t datalength);

// 发送数据包的函�?
// 参数�?
// beginwith: 数据包头
// endwith: 数据包尾
// value: 要发送的数据�?
void BluSendDate(uint8_t beginwith, uint8_t endwith, uint8_t value);

#endif // BLU_H