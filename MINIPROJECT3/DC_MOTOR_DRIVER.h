/*
 * DC_MOTOR_DRIVER.h
 *
 *  Created on: Oct 7, 2021
 *      Author: youssef
 */

#ifndef DC_MOTOR_DRIVER_H_
#define DC_MOTOR_DRIVER_H_
#include "std_types.h"

#define motor_pin1   PIN0_ID
#define motor_pin2   PIN1_ID
#define motor_port   PORTB_ID
#define CW             0
#define A_CW           1
void DcMotor_Init(void);

void DcMotor_Rotate(uint8 state,uint8 speed);

#endif /* DC_MOTOR_DRIVER_H_ */
