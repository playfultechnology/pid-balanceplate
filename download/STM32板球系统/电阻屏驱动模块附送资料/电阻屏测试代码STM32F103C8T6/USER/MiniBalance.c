#include "stm32f10x.h"
#include "sys.h"

  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/

int Position_X,Position_Y;
int main(void)
  { 
		delay_init();	    	            //=====��ʱ������ʼ��	
		uart_init(9600);	            //=====���ڳ�ʼ��Ϊ
		JTAG_Set(SWD_ENABLE);           //=====��SWD�ӿ� �������������SWD�ӿڵ���
		LED_Init();                     //=====��ʼ���� LED ���ӵ�Ӳ���ӿ�
	  KEY_Init();                     //=====������ʼ��
		MY_NVIC_PriorityGroupConfig(2); //=====�жϷ���
		delay_ms(100);                  //=====��ʱ�ȴ�
//	uart3_init(9600);               //=====����3��ʼ��
		Adc_Init();                     //=====adc��ʼ��
		delay_ms(100);                  //=====��ʱ�ȴ�
    OLED_Init();                    //=====OLED��ʼ��	
		Screen_Init();                  //=====������IO��ʼ��
		TIM1_Int_Init(99,7199);         //=====��ʱ��10ms�ж�
    while(1)
	   {
			 printf("Position_X:%d",Position_X);//=====��ʱ�ȴ�
			 printf("    Position_Y:%d\r\n",Position_Y);
			 	delay_ms(300);                  //=====��ʱ�ȴ�
	   } 
}

