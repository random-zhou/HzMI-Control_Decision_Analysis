# HzMI-Control_Decision_Analysis
- 赫兹矩阵创新实验室控制决策数据分析相关

![alt text](<HzMI logo.jpg>)

<a id="<返回目录>"></a>

#链接直通车

> [Data_Processing_Algorithm(数据处理算法系列)](#<Data_Processing_Algorithm(数据处理算法系列)>)

> [Motion_Control_Feedback_Algorithm(运动控制反馈数据处理算法系列)](#<Motion_Control_Feedback_Algorithm(运动控制反馈数据处理算法系列)>)

>[Communication_Formatting_Algorithm(通讯接受格式化算法系列)](#<Communication_Formatting_Algorithm(通讯接受格式化算法系列)>)

>[Optimization_Algorithm(常用优化算法)](#<Optimization_Algorithm(常用优化算法)>)

>[Motor_Drive_Control_Usage(电机驱动算法系列)](#<Motor_Drive_Control_Usage(电机驱动算法系列)>)

>[Other_Module_Usage(其他模块驱动算法系列)](#<Other_Module_Usage(其他模块驱动算法系列)>)

>[Parameter_Debugging_Assistant(调参助手)](#<Parameter_Debugging_Assistant(调参助手)>)

>[ROS related documents(ROS相关文档)](#<ROS相关文档>)


## Data_Processing_Algorithm(数据处理算法系列)

|document                        |Code.c                                                         |Code.h                                                                           |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|
|Struct_typedef(常用数据定义)     |                                                               |[struct_typedef.h](ALGORITHM/Data_Processing_Algorithm/struct_typedef.h)                     |
|user_lib(常用运算函数)           |                                                               |[user_lib.h](ALGORITHM/Data_Processing_Algorithm/user_lib.h)                                 |
|str_deal(字符串处理算法)         |[str_deal.c](ALGORITHM/Data_Processing_Algorithm/str_deal.c)               |[str_deal.h](ALGORITHM/Data_Processing_Algorithm/str_deal.h)                                 |
|vaildation_deal(校验算法)        |[vaildation_deal.c](ALGORITHM/Data_Processing_Algorithm/validation_deal.c) |[vaildation.h](ALGORITHM/Data_Processing_Algorithm/validation_deal.h)                        |
|filter(常用滤波算法)             |[filters.c](ALGORITHM/Data_Processing_Algorithm/filters.c)                  |[filters.h](ALGORITHM/Data_Processing_Algorithm/filters.h)                                   |
|sort_search_deal(常用排序&搜索算法)|[sort_search_deal.c](ALGORITHM/Data_Processing_Algorithm/sort_search_deal.c)|[sort_search_deal.h](ALGORITHM/Data_Processing_Algorithm/sort_search_deal.h)              |
|kalman_filter(卡尔曼滤波一阶&二阶) |[kalman_filter2.c](ALGORITHM/Data_Processing_Algorithm/kalman2.c)          |[kalman_filter2.h](ALGORITHM/Data_Processing_Algorithm/Kalman2.h)                            |

[返回目录](#<返回目录>)

<a id="<Motion_Control_Feedback_Algorithm(运动控制反馈数据处理算法系列)>"></a>

## Motion_Control_Feedback_Algorithm(运动控制反馈数据处理算法系列)

> ### PID

|document                        |Code.c                                                         |Code.h                                                                           |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|
|PID                             |[PID1.c](ALGORITHM\Motion_Control_Feedback_Algorithm/PID1.c)                       |[PID1.h](ALGORITHM\Motion_Control_Feedback_Algorithm/PID1.h)                                         |
|                                |[PID2.c](ALGORITHM\Motion_Control_Feedback_Algorithm/PID2.c)                       |[PID2.h](ALGORITHM\Motion_Control_Feedback_Algorithm/PID2.h)                                         |
|                                |[PID3.c](ALGORITHM\Motion_Control_Feedback_Algorithm/PID3.c)                       |[PID3.h](ALGORITHM\Motion_Control_Feedback_Algorithm/PID3.h)                                         |

> ### LQR

|document                        |Code.c                                                         |Code.h                                                                           |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|
|MPC                             |[MPC1.c]                                                       |[MPC1.h];                                                                        |
|                                |                                                               |                                                                                 |

> ### MPC

|document                        |Code.c                                                         |Code.h                                                                           |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|
|LQR                             |[LQR1.c]                                                       |[LQR1.h];                                                                        |
|                                |                                                               |                                                                                 |

[返回目录](#<返回目录>)


<a id="<Communication_Formatting_Algorithm(通讯接受格式化算法系列)>"></a>

## Communication_Formatting_Algorithm(通讯接受格式化算法系列)

> ### USART
>
|document                        |Code.c                                                         |Code.h                                                                                                              |
|--------------------------------|---------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
|USART+DMA(遥控串口)              |[Usart_DMA_hal.c](ALGORITHM/Communication_Formatting_Algorithm/USART/bsp_usart.c)         |[Usart_DMA_hal.h](ALGORITHM/Communication_Formatting_Algorithm/USART/bsp_usart.h)                    |
|USART_IT(重映射+中断打包接发)     |[USART_IT.c](ALGORITHM/Communication_Formatting_Algorithm/USART/usart.c)                  |[USART_IT.h](ALGORITHM/Communication_Formatting_Algorithm/USART/usart.h)                              |
|USART(环形队列)                   |                                                                |                                                                                                                   |

> ### SBUS系列
>
|document                        |Code.c                                                         |Code.h                                                                                                              |
|--------------------------------|---------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
|DBUS协议                         |                                                               |                                                                                                                   |
|SBUS协议                         |                                                               |                                                                                                                   |

>I2C
>
|document                        |Code.c                                                         |Code.h                                                                                                              |
|--------------------------------|---------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
|I2C(SoftWare)                   |                                                                |                                                                                                                  |
|I2C(HardWare)                   |                                                               |                                                                                                                   |  

>SPI
>
|document                        |Code.c                                                         |Code.h                                                                                                              |
|--------------------------------|---------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
|SPI(SoftWare)                   |                                                               |                                                                                                               |
|SPI(HardWare)                   |                                                               |                                                                                                                  |

[返回目录](#<返回目录>)


<a id="<Optimization_Algorithm(常用优化算法)>"></a>

## Optimization_Algorithm(常用优化算法(待更新))

|optimization_algorithm         |Code.py                                                         |Code.m                                                                            |Code.cpp                                                                         | 
|-------------------------------|----------------------------------------------------------------|----------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
|Genetic Algorithm(遗传算法)     |                                                                |                                                                                  |                                                                                 |
|Tabu Search(禁忌搜索)           |                                                                |                                                                                  |                                                                                 |
|Simulate Annealing(模拟退火)    |                                                                |                                                                                  |                                                                                 |
|Ant Colony Algorithm(蚁群算法)  |                                                                |                                                                                  |                                                                                 |
|Particle Swarm Optimization(粒子群算法)|                                                         |                                                                                  |                                                                                 |
|Bellman-Ford Algorithm(贝尔曼-福特算法)|                                                          |                                                                                  |                                                                                 |
|Floyd-Warshall Algorithm(弗洛伊德算法)|                                                           |                                                                                 |                                                                                   |
|Dijkstra's Algorithm(迪杰斯特拉算法)|                                                              |                                                                                 |                                                                                | 
|A* Search Algorithm(A*搜索算法)|                                                                  |                                                                                 |                                                                              |
|                                |                                                               |                                                                                 |                                                                                | 
[返回目录](#<返回目录>)

<a id="<Motor_Drive_Control_Usage(电机驱动算法系列)>"></a>

## Motor_Drive_Control_Usage(电机驱动算法系列)

> ### PWM驱动控制
> 
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|motor(普通直流电机-L298N驱动逻辑) |                                                               |                                                                                 |PWM                                   |
|stepmotor(步进电机-tb6600驱动逻辑)|[gpio_stepmotor.c](ALGORITHM/Motor_Drive_Control_Usage/STEPMOTOR/gpio_stepmotor.c)               |[gpio_stepmotor.h](ALGORITHM/Motor_Drive_Control_Usage/STEPMOTOR/gpio_stepmotor.h)     |引脚电平反转           |
|stepmotor(步进电机-tb6600驱动逻辑)|[pwm_stepmotor.c](ALGORITHM/Motor_Drive_Control_Usage/STEPMOTOR/pwm_stepmotor.c)                |[pwm_stepmotor.h](ALGORITHM/Motor_Drive_Control_Usage/STEPMOTOR/pwm_stepmotor.h)                           |时钟电平反转(PWM)                    |
|snail2305(Dji_2305-c615驱动逻辑) |                                                               |                                                                                 |PWM                                | 
|舵机                                |                                                               |                                                                                 |                                      |
|                                |                                                               |                                                                                 |                                     |


> ### CAN驱动控制
> 
|document                        |Code.c                                                         |Code.h                                                                           |other_info                                                                                     |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
|M2006(Dji_2006-c610驱动逻辑)    |[M2006_can.c](ALGORITHM/Motor_Drive_Control_Usage/M2006DRVCode/can.c)                         |[M2006_can.c](ALGORITHM/Motor_Drive_Control_Usage/M2006DRVCode/can.h)                                         |CAN   配置1M频率  电流控制              |
|                                |[M2006_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M2006DRVCode/bsp_can.c)                |[M2006_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M2006DRVCode/bsp_can.h)                                   |初始化于MX_init之后                  |
|                                |[M2006_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M2006DRVCode/CAN_receive2006.c)     |[M2006_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M2006DRVCode/CAN_receive2006.h)                      |控制电流大小范围(-16384,16384)       |
|M3508(Dji_3508-c620驱动逻辑)    |[M3508_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/can.c)                         |[M3508_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/can.h)                                             |CAN   配置1M频率  电流控制           |
|                                |[M3508_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/bsp_can.c)                |[M3508_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/bsp_can.h)                                   |初始化于MX_init之后                  |
|                                |[M3508_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/CAN_receive3508.c)     |[M3508_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/CAN_receive3508.h)                      |控制电流大小范围(-16384,16384)       |
|M3510(Dji_3510-820R驱动逻辑)    |[M3510_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3508DRVCode/can.c)                         |[M3510_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3510DRVCode/can.h)                                           |CAN    配置1M频率  电流控制            |
|                                |[M3510_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3510DRVCode/bsp_can.c)                 |[M3510_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M3510DRVCode/bsp_can.h)                                  |初始化于MX_init之后                  |
|                                |[M3510_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M3510DRVCode/CAN_receive3510.c)     |[M3510_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M3510DRVCode/CAN_receive3510.h)                      |控制电流大小范围(-16384,16384)        |
|M6020(Dji_6020自带驱动逻辑)     |[M6020_can.c](ALGORITHM/Motor_Drive_Control_Usage/M6020DRVCode/can.c)                         | [M6020_can.c](ALGORITHM/Motor_Drive_Control_Usage/M6020DRVCode/can.ch)                                        |CAN    配置1M频率  电压控制              | 
|                                |[M6020_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M6020DRVCode/bsp_can.c)                 |[M6020_bsp_can.c](ALGORITHM/Motor_Drive_Control_Usage/M6020DRVCode/bsp_canh)                                  |初始化于MX_init之后                    |
|                                |[M6020_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M6020DRVCode/CAN_receive6020.c)     |[M6020_can_receive.c](ALGORITHM/Motor_Drive_Control_Usage/M6020DRVCode/CAN_receive6020.h)                      |控制电压大小范围(-30000,30000)        |
|                                |                                                               |                                                                                 |                                      |
|                                |                                                               |                                                                                 |                                     |

> ### USART驱动控制
> 
|document                        |Code.c                                                         |Code.h                                                                           |other_info                                                                                     |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
|总线舵机                         |                                                               |                                                                                 |                                                                                               |
|                                |                                                               |                                                                                 |                                                                                           |

[返回目录](#<返回目录>) 

<a id="<Other_Module_Usage(其他模块驱动算法系列)>"></a> 

## Other_Module_Usage(其他模块驱动算法系列)

> ### OLED
>
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|OLED1(IIC)                      |[OLED1.c(IIC)](ALGORITHM/Other_Module_Usage/OLED/bsp_oled.c)             |[OLED1.h(IIC)](ALGORITHM/Other_Module_Usage/OLED/bsp_oled.h)                               |                                    |
|OLEDFONT1                       |                                                               |[OLEDFONT1.h](ALGORITHM/Other_Module_Usage/OLED/oledfont.h)                                |                                    |
|OLED2(IIC)-4Pin                 |[OLED2.c(IIC)](ALGORITHM/Other_Module_Usage/OLED/OLED.c)                 |[OLED2.h(IIC)](ALGORITHM/Other_Module_Usage/OLED/OLED.h)                                   |                                    |
|OLEDFONT2                       |[OLEDFONT2.c](ALGORITHM/Other_Module_Usage/OLED/OLED_FONT.c)             |[OLEDFONT2.h](ALGORITHM/Other_Module_Usage/OLED/OLED_FONT.h)                               |                                    |   
|                                |                                                               |                                                                                 |                                    |  

> ### DELAY
>
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|HAL_Delay_us(微秒延时)           |[HAL_Delay_us.c](ALGORITHM/Other_Module_Usage/DELAY/HAL_Delay_us.c)       |[HAL_Dealy_us.h](ALGORITHM/Other_Module_Usage/DELAY/HAL_Delay_us.h)               |                                   |
|                                |                                                               |                                                                                 |                                    |   

> ### MPU6050
>
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|MPU6050                         |[MPU6050.c](ALGORITHM/Other_Module_Usage/MPU6050/MPU6050.c)    |[MPU6050.h](ALGORITHM/Other_Module_Usage/MPU6050/MPU6050.h)                      |                                    |  
|Quaternion                      |[Quaternion.c](ALGORITHM/Other_Module_Usage/MPU6050/Quaternion.c)|[Quaternion.h](ALGORITHM/Other_Module_Usage/MPU6050/Quaternion.h)                  |                                    |  
|                                |                                                               |                                                                                 |                                    |  
> ### huiduchuangan（八路灰度传感器）
>
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|huiduchuangan                   |[huiduchuangan.c](ALGORITHM/Other_Module_Usage/huiduchuangan/huiduchuangan.c) |[huiduchuangan.h](ALGORITHM/Other_Module_Usage/huiduchuangan/huiduchuangan.h)|                         |  
|                                |                                                               |                                                                                 |                                    |  

> ### HC-SR04
>
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|HC-SR04                         |[HC-SR04.c](ALGORITHM/Other_Module_Usage/HC-SR04/HC-SR04.c)    |[HC-SR04.h](ALGORITHM/Other_Module_Usage/HC-SR04/HC-SR04.h)                  |                                    |  
|                                |                                                               |                                                                                 |                                    |  

> ### BLUETOOTH(蓝牙)
>
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|BLUETOOTH                       |[Blu.c](ALGORITHM/Other_Module_Usage/BLUETOOTH/Blu.c)          |[Blu.h](ALGORITHM/Other_Module_Usage/BLUETOOTH/Blu.h)                          |                                    |  
|                                |                                                               |                                                                                 |                                    |  

[返回目录](#<返回目录>)

<a id="<Parameter_Debugging_Assistant(调参助手)>"></a>

## Parameter_Debugging_Assistant(调参助手)
|document                        |Code.c                                                         |Code.h                                                                           |other_info                         |
|--------------------------------|---------------------------------------------------------------|---------------------------------------------------------------------------------|-----------------------------------|
|                                |                                                               |                                                                                 |                                   |       
|                                |                                                               |                                                                                 |                                    |
|                                |                                                               |                                                                                 |                                    |               

[返回目录](#<返回目录>)


<a id="<ROS相关文档>"></a>

# ROS相关文档
## ROS1系列

[返回目录](#<返回目录>)
## ROS2系列

[返回目录](#<返回目录>)

