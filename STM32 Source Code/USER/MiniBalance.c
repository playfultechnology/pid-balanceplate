/**************************************************************************
 * Balance Plate
 *
 * See Also:
 * /MiniBalance/CONTROL/control.c
 * /MiniBalance/Datascope_DP/DataScope_DP.c // Generates
 * /MiniBalance/show/show.c // OLED output
 *
 **************************************************************************/

// INCLUDES
#include "stm32f10x.h"
#include "sys.h"

// GLOBALS
u8  Flag_Stop=1;                 // Stop flag bit and display flag bit. Default stop and display open
int Position_X, Position_Y;
float Balance_Kp=55, Balance_Ki=0.000, Balance_Kd=58, Data_Show, Data_Show2;
float Zero_X=133, Zero_Y=100, Target_X, Target_Y;
u8 delay_50, delay_flag;         // 50ms accurate demo flag
int PS2_LX=128, PS2_LY=128, PS2_RX=128, PS2_RY=128, PS2_KEY;     //PS2 remote control related

int main(void) { 
	delay_init();
	
	// INITIALISATION
	// Initialise serial port
	uart_init(128000);
	// Open the SWD interface which can be used for debugging
	JTAG_Set(SWD_ENABLE);
	LED_Init();
	KEY_Init();
	MY_NVIC_PriorityGroupConfig(2);
	delay_ms(100);
//	uart3_init(9600);
	Adc_Init();
	delay_ms(100);
    OLED_Init();
    TIM1_Int_Init(99,7199);
	TIM4_PWM_Init(9999,143);
	Screen_Init();
	PS2_Init();
	PS2_SetInit();
	
	// MAIN LOOP
    while(1) {
		// Read inputs
		PS2_KEY=PS2_DataKey();
		PS2_LX=PS2_AnologData(PSS_LX);
		PS2_LY=PS2_AnologData(PSS_LY);
		PS2_RX=PS2_AnologData(PSS_RX);
		PS2_RY=PS2_AnologData(PSS_RY);

		// Display outputs
		oled_show();
		DataScope();
		
		delay_flag=1;	
		delay_50=0;
		// Precise 50ms delay realized by INT interrupt of MPU6050
		while(delay_flag);
	} 
}