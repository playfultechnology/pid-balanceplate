#include "control.h"	
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
int Max_Target=100;
u8 Flag_Target;// �����־λ
int Flag_Move; //�趨������־λ
/**************************************************************************
�������ܣ���ʱ�жϺ��� ���еĿ��ƴ��붼��������		 
#define  XM PBout(13)
#define  YM PBout(14)
#define  XP PBout(15)
#define  YP PBout(12)
**************************************************************************/
void TIM1_UP_IRQHandler(void)
{    
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
	{   
			    TIM_ClearITPendingBit(TIM1, TIM_IT_Update  );  //���TIMx���жϴ�����λ:TIM �ж�Դ
					if(++Flag_Target>4)  Flag_Target=0;
					if(Flag_Target==1)    //��һ��10ms �ɼ�X������
					{
						YM=0;    //��X����+3.3V��ѹ   M��-����˼  P�ǣ�����˼
						YP=1;
						XM=1;
						XP=0;	 
						Position_X=Get_Adc(Y_IN)/15; //����X�����						
						YM=1;   //�ָ�֮ǰ��״̬
						YP=0;
						XM=0;
						XP=1;
					}
						 else 	if(Flag_Target==2) //�ڶ���10ms ����PS2ң�ز�����PID����
					{
					}
					 else 	if(Flag_Target==3) //������10ms �ɼ�Y������
					{
						YM=1; //��Y����+3.3V��ѹ
						YP=0;
						XM=0;
						XP=1;	
						Position_Y=Get_Adc(X_IN)/20; //����Y�����   		
						YM=0;   //�ָ�֮ǰ��״̬
						YP=1;
						XM=1;
						XP=0;	 
					}
						else 	if(Flag_Target==4)   //���ĸ�10ms PID����
					{
			
					}									
    	}       	
} 

