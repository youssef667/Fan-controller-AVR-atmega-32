/*
 * DC_MOTOR_DRIVER.c
 *
 *  Created on: Oct 7, 2021
 *      Author: youssef
 */


#include "common_macros.h"
#include "GPIO_YOUSSEF.h"
#include "DC_MOTOR_DRIVER.H"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "PWM_DC_MOTOR.h"
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(motor_port,motor_pin2 , PIN_OUTPUT);
	GPIO_setupPinDirection(motor_port,motor_pin1 , PIN_OUTPUT);
	GPIO_writePin(motor_port,motor_pin2 ,LOGIC_LOW);
	GPIO_writePin(motor_port,motor_pin1 ,LOGIC_LOW);


	}

void DcMotor_Rotate(uint8 state,uint8 speed)
{
     uint8 pwm_dutycycle ;
     pwm_dutycycle =speed*2.55;
     PWM_Timer0_Start(pwm_dutycycle );
 if (state ==CW)
 {
	 GPIO_writePin(motor_port,motor_pin2 ,LOGIC_HIGH);
	 	GPIO_writePin(motor_port,motor_pin1 ,LOGIC_LOW);
 }
 else
 {
	 GPIO_writePin(motor_port,motor_pin2 ,LOGIC_LOW);
	 	 	GPIO_writePin(motor_port,motor_pin1 ,LOGIC_HIGH);
 }



	}
