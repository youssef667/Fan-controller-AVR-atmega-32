/*
 * MINIPROJECT3.c
 *
 *  Created on: Oct 7, 2021
 *      Author: youssef
 */

#include "ADC_DRIVER_YOUSSEF.h"
#include "DC_MOTOR_DRIVER.h"
#include "lm35_sensor.h"
#include "lcd.h"

int main(void)
{
	   ADC_ConfigType TYPE = {INTERNAL_VOLTAGE_REFERENCE,F_CPU_8 , Polling};

	   ADC_init(& TYPE);

       LCD_init();

	   DcMotor_Init();

	   LCD_displayString("TEMP Value =  ");

	while(1){

		LCD_moveCursor(0,12);

		if((LM35_getTemperature(& TYPE)) <30)
	     {
			DcMotor_Rotate(1,0);

			LCD_displayString(" ");

			LCD_intgerToString(LM35_getTemperature(& TYPE));
			LCD_displayString("C");
			LCD_moveCursor(1,4);

			LCD_displayString("FAN IS OFF");

	     }

		else if(((LM35_getTemperature(& TYPE)) >=30) && ((LM35_getTemperature(& TYPE)) <60 ))
		{
		   DcMotor_Rotate(1,25);

		   LCD_displayString(" ");

		   LCD_intgerToString(LM35_getTemperature(& TYPE));
		   LCD_displayString("C");
		   LCD_moveCursor(1,2);

		   LCD_displayString("duty cycle=25%");

		}
		else if(((LM35_getTemperature(& TYPE)) >=60) && ((LM35_getTemperature(& TYPE)) <90 ))
				{
			DcMotor_Rotate(1,50);

			LCD_displayString(" ");

			LCD_intgerToString(LM35_getTemperature(& TYPE));
			LCD_displayString("C");
			LCD_moveCursor(1,2);

			LCD_displayString("duty cycle=50%");


				}
		else if(((LM35_getTemperature(& TYPE)) >=90) && ((LM35_getTemperature(& TYPE)) <120 ))
				{
			DcMotor_Rotate(1,75);

			LCD_displayString(" ");

			LCD_intgerToString(LM35_getTemperature(& TYPE));
			LCD_displayString("C");
			LCD_moveCursor(1,2);

			LCD_displayString("duty cycle=75%");
				}
		else if(((LM35_getTemperature(& TYPE)) >=120) )
				{
			DcMotor_Rotate(1,100);

			LCD_displayString(" ");

			LCD_intgerToString(LM35_getTemperature(& TYPE));
			LCD_displayString("C");
			LCD_moveCursor(1,1);

			LCD_displayString("duty cycle=100%");


				}

	}
}
