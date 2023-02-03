/*
 * ADC_DRIVER_YOUSSEF.c
 *
 *  Created on: Oct 5, 2021
 *      Author: youssef
 */


#include "ADC_DRIVER_YOUSSEF.h"
#include <avr/io.h>
#include "common_macros.h"


 extern volatile uint16 intruupt_adc =0;

ISR(ADC_vect)
{
	intruupt_adc = ADC;
}

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	 uint8 mode_variable;
	mode_variable = (Config_Ptr ->mode);
	ADMUX = ((Config_Ptr->ref_volt)<<5);

	SET_BIT(ADCSRA,ADEN);

	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->prescaler)& 0x07);


#if ( mode_variable == 1 )

	SET_BIT(ADCSRA,ADIE);


#endif
}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADC_ConfigType * Config_Ptr;
	channel_num &= 0x07;

	ADMUX &= 0xE0;

	ADMUX = ADMUX | channel_num;

	SET_BIT(ADCSRA,ADSC);
	if((Config_Ptr->mode) == Polling)
		{
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	SET_BIT(ADCSRA,ADIF);
		}
	return ADC;
}
