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
#if !defined(SENSOR_H)
#define SENSOR_H

#include "main.h"






//超声波引�?
#define U1_Port GPIOA
#define U1_Pin GPIO_PIN_4


typedef struct
{
    float Num1Dce;
    uint8_t OverFlowNum;
} RubDisStr;

extern RubDisStr RubDis;


void Start_Detect(void);


#endif // SENSOR_H
