#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "adc1.h"


int main(void)
{
	DDRC = 0;							// PORTC as input PORT for analog sensors
	DDRB = 0B11111111;					//PORTB as OUTPUT PORT
	DDRA |=(1<<PA7);						// OUTPUT direction for Buzzer
	
	adc();								//ADC initialization 
	while(1)
	{
		ADCSRA|=(1<<ADSC);								// ADC start conversion 
		while(!(ADCSRA&(1<<ADIF)));						// Wait until conversion is completed 
		as=ADC;										//Put the ADC value in as variable 
		
						if (as<13)						//if value of ADC is less then 13 
						{
							PORTB=0b00000000;			//then Turn OFF all LEDs
						}
						else
						{
							PORTB=0b11111111;			// Turn ON all (8) LEDs
							PORTA|=(1<<7);				// Buzzer ON
							_delay_ms(100);				// 100 millisecond delay
							PORTA&=~(1<<7);				//Turn OFF buzzer
							_delay_ms(100);				// 100 millisecond delay
						}
	}
	
}