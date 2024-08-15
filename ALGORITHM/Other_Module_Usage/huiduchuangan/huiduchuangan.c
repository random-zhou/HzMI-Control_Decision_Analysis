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
#include "huiduchuangan.h" // 包含灰度传感器通道相关的头文件
#include "math.h" // 包含数学函数库的头文件
#include "stdio.h" // 包含标准输入输出库的头文件

// 定义灰度传感器状态数组和误差数组，以及扫描模式和上一次的灰度传感器误差
uint8_t huidu_state[huidu_length] = {0}; // 状态数组，初始化为0
int8_t huidu_error[huidu_length] = {-35, -19, -14, 6, 6, 14, 19, 35}; // 误差数组
uint8_t scan_mode = increase_mode; // 默认扫描模式，假设increase_mode之前已定义
int8_t lasthuiduacl = 0; // 上一次的灰度传感器误差

// 扫描灰度传感器现在状态的函数
void huidu_scan(void)
{
    switch (scan_mode) // 根据扫描模式进行不同的扫描操作
    {
    case 0: // 第0种模式，没有提供具体实现
        break;
    case 1: { // 第1种模式，正向扫描
        // 遍历所有传感器，读取状态并存入数组
        for (i = 0; i < huidu_length; i++) // 缺少变量i的声明
        {
            huidu_state[i] = hd_gpio_read(i);
            // 打印读取的状态，实际使用时应注释或删除此行
            // printf("%d", hd_gpio_read(i));
        }
        // 打印换行，实际使用时应注释或删除此行
        // printf("\n");
        break;
    }
    case 2: { // 第2种模式，反向扫描
        for (i = huidu_length - 1; i >= 0; i--) // 缺少变量i的声明
        {
            huidu_state[i] = hd_gpio_read(i);
        }
        break;
    }
    }
}

// 通过灰度传感器的状态值判断当前误差的函数
int16_t error_judge(uint8_t a[])
{
    static uint8_t sum = 0; // 用于判断是否正常沿着黑线行驶的累计变量
    int8_t d = 0; // 用于存储最终的误差值

    // 遍历状态数组，根据状态和误差数组计算误差
    for (i = 0; i < huidu_length; i++) // 缺少变量i的声明
    {
        if (huidu_state[i] == 1)
        {
            // 当状态为1时的代码未提供
        }
        else if (huidu_state[i] == 0) // 识别到黑线
        {
            if (abs(huidu_error[i]) > abs(lasthuiduacl)) // 使用abs函数计算绝对值
            {
                lasthuiduacl = huidu_error[i]; // 更新上一次的灰度传感器误差
            }
            sum++;
        }
    }

    // 特殊情况处理代码未提供...

    // 更新上一次误差和当前误差
    sum = 0;
    lasthuiduacl = d; // 这里应该是lasthuiduacl，而不是d
    d = lasthuiduacl; // 这里应该是huiduacl，而不是d
    lasthuiduacl = 0; // 重置上一次的灰度传感器误差
    // 缺少变量huiduacl的定义和更新

    return d; // 返回最终的误差值
}

// 读取灰度传感器引脚的电平值的函数
uint8_t hd_gpio_read(uint8_t j)
{
    uint8_t f; // 用于存储读取到的电平值
    // 根据传入的引脚编号j，读取对应的电平值
    switch (j)
    {
    // 每个case对应一个传感器的读值，这里只是示例，value1等变量需要在其他地方定义
    case 0:
        f = value1;
        break;
    case 1:
        f = value2;
        break;
    // ... 其他case类似
    case 7:
        f = value8;
        break;
    default:
        break;
    }

    return f; // 返回读取到的电平值
}