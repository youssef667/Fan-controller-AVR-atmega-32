 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include <util/delay.h>
#include "ADC_DRIVER_YOUSSEF.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(const ADC_ConfigType * Config_Ptr)
{

	 uint8 mode_variable;
	mode_variable = (Config_Ptr ->mode);
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
#if ( mode_variable == 0 )
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	_delay_ms(5);
	/* Calculate the temperature from the ADC value*/

	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));


#else
	adc_value =intruupt_adc;

	_delay_ms(5);

	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
#endif
	return temp_value;
}

