#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
#define X_IN 2
#define Y_IN 1
void Adc_Init(void);
u16 Get_Adc(u8 ch);
int Get_battery_volt(void);   
void  ccd_Init(void);
#define FILTER_TIMES  20
#endif 

























