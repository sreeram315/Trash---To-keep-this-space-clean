/*

	 In this program by converting analog voltage to digital
	 sending it to the serial terminal

*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "adc1.h"
#include "uart.h"
unsigned char arr[100];


int main(void)
{
	DDRA = 0;							// PORTA as input PORT for analog sensors
	DDRB = 0B11111111;					//PORTB as OUTPUT PORT
	DDRA |=(1<<7);						// OUTPUT direction for Buzzer
	
	PORTB=0xff;
	_delay_ms(1000);
	PORTB=0;
	_delay_ms(500);

	adc();								// ADC initialization
	u_init();							// usart initialization (serial communication)
	
			while(1)
			{
				ADCSRA|=(1<<ADSC);				// Start conversion 
				while(!(ADCSRA&(1<<ADIF)));		// hold until conversion is completed
				as=ADC;							//assigning the value of ADC in as variable 
				itoa(as,arr,10);				// integer to character conversion
				usart_tx(arr);					//Now transmitting the decimal value from controller 
				usart_tx("\r\n");				// (\r --> for new row)(\n --> for new line) both to press enter
				_delay_ms(1000);				// delay of one second
		
			}
}