#include <MsTimer2.h>        //定时中断
//////////触摸屏控制引脚//////////////////
#define YM        5    
#define YP        6  
#define XM        7  
#define XP        8  
int Position_X,Position_Y; //X Y方向的测量值
/**************************************************************************
函数功能：5ms控制函数 核心代码 作者：平衡小车之家
入口参数：无
返回  值：无
**************************************************************************/
void control(){  
    static u8 Flag_Target;
    sei();        //全局中断开启
    if(++Flag_Target>4)  Flag_Target=0;  //分频处理
      if(Flag_Target==1)    //第一个10ms 采集Y轴数据
    {    
       digitalWrite(YM, LOW);  //给X方向+3.3V电压
       digitalWrite(YP, HIGH);   
       digitalWrite(XM, HIGH);  
       digitalWrite(XP, LOW); 
       Position_Y=analogRead(3)*4/15; //测量Y方向的坐标          
       digitalWrite(YM, HIGH);  
       digitalWrite(YP, LOW); 
       digitalWrite(XM, LOW);  
       digitalWrite(XP, HIGH); 
    }
       else   if(Flag_Target==2) //第二个10ms 接收PS2遥控并调节PID参数
    {
    }
     else   if(Flag_Target==3) //第三个10ms 采集X轴数据
    {
       digitalWrite(YM, HIGH);  //给Y方向+3.3V电压//D3
       digitalWrite(YP, LOW); //  
       digitalWrite(XM, LOW);  //  
       digitalWrite(XP, HIGH); //  
       Position_X= analogRead(2)/5; //测量X方向的           
       digitalWrite(YM, LOW);  //
       digitalWrite(YP, HIGH); //  
       digitalWrite(XM, HIGH);  //  
       digitalWrite(XP, LOW); //  
     }
      else  if(Flag_Target==4)   //第四个10ms PID控制
    {
    }             
 }
/**************************************************************************
函数功能：初始化 相当于STM32里面的Main函数 作者：平衡小车之家
入口参数：无
返回  值：无
**************************************************************************/
void setup()   {                
   Serial.begin(9600);           //开启串口
   delay(200);                    //延时等待初始化完成
    pinMode(XM, OUTPUT);          //电机控制引脚
    pinMode(XP, OUTPUT);          //电机控制引脚，
    pinMode(YM, OUTPUT);          //电机速度控制引脚
    pinMode(YP, OUTPUT);          //电机速度控制引脚
   MsTimer2::set(10, control);    //使用Timer2设置定时中断
   MsTimer2::start();             //中断使能
}
/**************************************************************************
函数功能：主循环程序体
入口参数：无
返回  值：无
**************************************************************************/
void loop()   {      
        Serial.print("Position_X:"); 
        Serial.print(Position_X,DEC); 
        Serial.print("    Position_Y:"); 
        Serial.println(Position_Y,DEC);
        delay(300);                  //=====延时等待
}


