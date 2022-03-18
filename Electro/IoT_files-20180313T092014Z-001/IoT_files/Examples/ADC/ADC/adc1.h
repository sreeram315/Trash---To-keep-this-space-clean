/*
 * adc1.h
 *
 * Created: 1/23/2018 10:26:34 AM
 *  Author: ancha
 */ 


#ifndef ADC1_H_
#define ADC1_H_
#include <stdlib.h>
#include <string.h>
#define dl _delay_ms(2000)
void adc()
{
	ADCSRA = 0b10000111;	// Enable ADC 
	ADMUX = 0b11000000;		// for channel zero(ADC0)
}
unsigned char as;


#endif /* ADC1_H_ */