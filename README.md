# pid-balanceplate
Servo-controlled Balance Plate using Arduino / STM32 

## Method of Operation
The plate is controlled by a PS2 controller:
 - Analog Stick : Move balance point
 - Buttons : Trace shape

## Code Structure
 - The main() program loop is contained in USER\MiniBalance.c, but you'll find it quite sparse - it begins by initialising all the hardware and then enters an infinite while() loop whose only function appears to be to update the display.
 - The reason is that the control loop is actually contained in the TIM1_UP_IRQHandler() function defined in BALANCE\CONTROL\control.c. This is an interrupt, as described at https://www.keil.com/pack/doc/CMSIS/Core/html/using_CMSIS.html. The original code comments state that it is triggered by the interrupt from a MPU6050, but that must be incorrect as there is no such component in the schematic, so seems to be based on internal interrupt timer instead. Calling this function at fixed, regular intervals makes PID updates more reliable. The control handler is responsible for:
   * Reading position input from screen
   * Kinematic Analysis
   * Setting PWM angle of servos
