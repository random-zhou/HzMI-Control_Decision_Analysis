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
 
#include "Blu.h" // 包含蓝牙相关的头文件


// 定义接收缓冲区，接收状态，数据长度和接收到的数据变量
uint8_t BluRxBuff[20]= {0}; // 接收缓冲区数组，大小为20
uint8_t BluRxState=0, Blulength=0, BluRxData=0; // 接收状态，数据长度和接收数据变量初始化为0

// 初始化串口接收中断
void BluRxUartInit(void)
{
    UART_Start_Receive_IT(&huart1, &BluRxData, 1); // 开始串口接收中断，一次接收一个字节
}

// 串口接收数据包处理函数
// 参数说明：
// beginwith: 数据包开始的标识
// endwith: 数据包结束的标识
// requiredataBlulength: 需要接收的数据包长度
// 返回值：接收状态（1-接收完成，0-接收未完成或失败）
uint8_t BluRxHandle(uint8_t beginwith, uint8_t endwith, uint8_t length)
{
    // 接收到的数据是帧头，并且接收状态为0（未开始接收）
    if (BluRxData == beginwith && BluRxState == 0)
    {
        // 存储数据到缓冲区，并且更新长度，设置接收状态为1（开始接收）
        BluRxBuff[Blulength++] = BluRxData;
        BluRxState = 1;
    }
    // 如果已经开始接收
    else if (BluRxState == 1)
    {
        // 存储数据到缓冲区并更新长度
        BluRxBuff[Blulength++] = BluRxData;
        // 如果接收到的数据是帧尾，并且长度符合要求
        if (BluRxData == endwith && BluRxState == 1)
        {
            // 打印接收到的数据
            printf("%s", BluRxBuff);
            // 清空缓冲区，重置长度和状态，准备下一次接收
            memset(BluRxBuff, 0, Blulength);
            Blulength = 0;
            BluRxState = 0;
            BluRxData = 0;
            UART_Start_Receive_IT(&huart1, &BluRxData, 1); // 重新开始接收
            return 1; // 返回接收完成状态
        }
        else // 数据长度不符合要求，清空缓冲区，重置状态和长度
        {
            memset(BluRxBuff, 0, Blulength);
            BluRxState = 0;
            BluRxData = 0;
            Blulength = 0;
        }
    }
    // 无论是否接收完成，都重新开始接收
    UART_Start_Receive_IT(&huart1, &BluRxData, 1);
    return 0; // 返回未完成或失败状态
}

// 串口打包发送函数
// 参数说明：
// beginwith: 数据包头
// endwith: 数据包尾
// value: 要发送的数据值
void BluSendDate(uint8_t beginwith, uint8_t endwith, uint8_t value)
{
    uint8_t temp[3]; // 临时数组用于存储打包后的数据
    uint8_t i = 0, j = 0;
    uint8_t floatVariable = value; // 用于存储float类型数据的变量
    uint8_t *pdata = (uint8_t *)&floatVariable; // 将float变量的地址转换为uint8_t类型指针

    // 设置数据包头
    temp[0] = beginwith;
    // 将float变量的值转换为字节并存储到临时数组
    for (i = 0; i < 3; i++)
    {
        temp[i + 1] = *pdata++;
    }
    // 设置数据包尾
    temp[2] = endwith;

    // 发送打包后的数据
    for (j = 0; j < 3; j++)
    {
        HAL_UART_Transmit(&huart1, &temp[j], 1, HAL_MAX_DELAY);
    }
}

