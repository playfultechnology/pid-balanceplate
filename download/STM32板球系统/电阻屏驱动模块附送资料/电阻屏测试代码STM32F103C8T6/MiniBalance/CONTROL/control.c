#include "control.h"	
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
int Max_Target=100;
u8 Flag_Target;// 任务标志位
int Flag_Move; //设定动作标志位
/**************************************************************************
函数功能：定时中断函数 所有的控制代码都在这里面		 
#define  XM PBout(13)
#define  YM PBout(14)
#define  XP PBout(15)
#define  YP PBout(12)
**************************************************************************/
void TIM1_UP_IRQHandler(void)
{    
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{   
			    TIM_ClearITPendingBit(TIM1, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源
					if(++Flag_Target>4)  Flag_Target=0;
					if(Flag_Target==1)    //第一个10ms 采集X轴数据
					{
						YM=0;    //给X方向+3.3V电压   M是-的意思  P是＋的意思
						YP=1;
						XM=1;
						XP=0;	 
						Position_X=Get_Adc(Y_IN)/15; //测量X方向的						
						YM=1;   //恢复之前的状态
						YP=0;
						XM=0;
						XP=1;
					}
						 else 	if(Flag_Target==2) //第二个10ms 接收PS2遥控并调节PID参数
					{
					}
					 else 	if(Flag_Target==3) //第三个10ms 采集Y轴数据
					{
						YM=1; //给Y方向+3.3V电压
						YP=0;
						XM=0;
						XP=1;	
						Position_Y=Get_Adc(X_IN)/20; //测量Y方向的   		
						YM=0;   //恢复之前的状态
						YP=1;
						XM=1;
						XP=0;	 
					}
						else 	if(Flag_Target==4)   //第四个10ms PID控制
					{
			
					}									
    	}       	
} 

