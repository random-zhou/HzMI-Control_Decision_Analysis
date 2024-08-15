/**
  ****************************(C) COPYRIGHT 2024 HzMI****************************
  * @file       HC-SR04.c/h
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
#include "HC-SR04.h"

RubDisStr RubDis;
void Start_Detect()
{
      //在 Trig 管脚（触发信号）输入一个 10US 以上的高电平，启动测距
        HAL_GPIO_WritePin(U1_Port,U1_Pin,GPIO_PIN_SET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(U1_Port,U1_Pin,GPIO_PIN_RESET);
}

//超声波输入捕获中断
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{

    static uint8_t a=0;
    //判断定时器
    if (htim->Instance==TIM5)
    {
        //判断定时器通道
      switch (htim->Channel)
            {
            case HAL_TIM_ACTIVE_CHANNEL_1://通道一
                switch (a)
                {
                case 0://第一次上升沿触发
                //记录第一次触发时计数器的值
                    RubDis.Num1StaCCR=TIM5->CCR1;
                    //将触发方式改为下降沿
                    __HAL_TIM_SET_CAPTUREPOLARITY(&htim5,TIM_CHANNEL_1,TIM_ICPOLARITY_FALLING);
                    //记录已触发过一次
                    a++;
                    break;
                case 1://第二次下降沿触发
                    //记录第二次触发时计数器的值
                    RubDis.Num1EndCCR=TIM5->CCR1;
                    //判断计数器是否发生溢出
                    if (RubDis.OverFlowNum!=0&&(RubDis.Num1EndCCR<=RubDis.Num1StaCCR))//溢出标志位置位&&第二次计数值小于第一次计数值，则发生溢出（假设ARR=20000）
                    {
                        //进行溢出处理，并计算高电平时间
                        RubDis.Num1Dce=RubDis.Num1EndCCR+(20000-RubDis.Num1StaCCR)+RubDis.OverFlowNum*20000;
                    } else if (RubDis.OverFlowNum==0&&(RubDis.Num1EndCCR>=RubDis.Num1StaCCR))
                    {
                        //未发生溢出，直接计算高电平时间
                        RubDis.Num1Dce=RubDis.Num1EndCCR-RubDis.Num1StaCCR;
                    }
                    //由高电平时间计算距离
                    RubDis.Num1Dce=(RubDis.Num1Dce/1000000.0f)*340.0f/2.0f*100.0f; //单位是    cm
                    //完成一次测距，标志位初始化并把触发方式改回上升沿
                    a=0;
                    __HAL_TIM_SET_CAPTUREPOLARITY(&htim5,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);
                    break;

                default:
                    a=0;
                    break;
                }
                break;
                default:
                a=0;
                break;


           

         }
    }

}
