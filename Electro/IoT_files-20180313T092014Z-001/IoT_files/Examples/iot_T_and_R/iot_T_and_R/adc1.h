
#include <stdlib.h>
#include <string.h>
#define delay _delay_ms(2000)
void adc()
{
	ADCSRA = 0b10000111;	// Enable ADC 
	ADMUX = 0b11000000;		// for channel zero(ADC0)
}
unsigned char as;



void buzzer()
	{
			PORTA|=(1<<PA7);
			_delay_ms(100);
			PORTA&=~(1<<PA7);
			_delay_ms(100);
	}			
