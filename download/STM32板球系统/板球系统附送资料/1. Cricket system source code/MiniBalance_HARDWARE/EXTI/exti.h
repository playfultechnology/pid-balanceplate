#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/

#define INT PAin(3)   //连接到MPU6050的中断引脚
void MiniBalance_EXTI_Init(void);	//外部中断初始化		
void Screen_Init(void);
void EXTI3_IRQHandler(void);
#endif


























