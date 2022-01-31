#include "stm32f10x.h"
#include "sys.h"

  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/

int Position_X,Position_Y;
int main(void)
  { 
		delay_init();	    	            //=====延时函数初始化	
		uart_init(9600);	            //=====串口初始化为
		JTAG_Set(SWD_ENABLE);           //=====打开SWD接口 可以利用主板的SWD接口调试
		LED_Init();                     //=====初始化与 LED 连接的硬件接口
	  KEY_Init();                     //=====按键初始化
		MY_NVIC_PriorityGroupConfig(2); //=====中断分组
		delay_ms(100);                  //=====延时等待
//	uart3_init(9600);               //=====串口3初始化
		Adc_Init();                     //=====adc初始化
		delay_ms(100);                  //=====延时等待
    OLED_Init();                    //=====OLED初始化	
		Screen_Init();                  //=====电阻屏IO初始化
		TIM1_Int_Init(99,7199);         //=====定时器10ms中断
    while(1)
	   {
			 printf("Position_X:%d",Position_X);//=====延时等待
			 printf("    Position_Y:%d\r\n",Position_Y);
			 	delay_ms(300);                  //=====延时等待
	   } 
}

