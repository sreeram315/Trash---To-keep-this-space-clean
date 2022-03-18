
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "adc1.h"
#include "uart.h"

unsigned char arr[100];

int main(void)
{
							DDRA = 0b10000000;							// PORTA as input PORT for analog sensors
							DDRB = 0B11111111;					//PORTB as OUTPUT PORT
							DDRA |=(1<<PA7);						// OUTPUT direction for Buzzer
/************************************************************************/
/*                             Function initialization                                          */
/************************************************************************/
			adc();												//ADC initialization 
			u_init();											//UART initialization
	
	usart_tx("AT+CWQAP\r\n");									//disconnect previous connection (Wifi)
	delay;
	usart_tx("ATE1\r\n");										//Local ECHO ON
	delay;
	usart_tx("AT+CWJAP=\" wifi name \"\,\"   password    \"\r\n");		// connect to wifi network
	delay;	delay;						// to make (") to character use (\") Otherwise it will close the string and will show the ERROR
	
		buzzer();
		buzzer();
	while(1)
	{
		usart_tx("ATE1\r\n");												//Local ECHO ON
		_delay_ms(500);
		usart_tx("AT+CIPMUX=1\r\n");										// Enable multiple connection
		_delay_ms(500);
		usart_tx("AT+CIPSERVER=1,80\r\n");									//Enable PORT 80
		_delay_ms(500);
		usart_tx("AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80\r\n");		//Connect to ThingSpeak (IP address --> 184.106.153.149)
								delay;
										buzzer();
								delay;
										buzzer();
								delay;
																			// waiting for connection using delay
		usart_tx("AT+CIPSEND=4,44\r\n");									// send 44 characters on channel 4
		_delay_ms(1000);
		usart_tx("GET /update?key=WIGWO4TV8LFSFBHM&field1=");				// string to transmit the value of ADC
										ADCSRA|=(1<<ADSC);					// ADC conversion is start
										while(!(ADCSRA&(1<<ADIF)));			//wait for complete conversion
										as=ADC;								// initialize the value of ADC in as variable
										itoa(as,arr,10);					// int to char conversion
										usart_tx(arr);						// transmission of ADC value in the form of character
										usart_tx("\r\n");					//Pressing Enter using Controller 
								delay;
		usart_tx("AT+CIPCLOSE=4\r\n");										//Closing channel 4
	
										buzzer();
/************************************************************************/
/* Now Performing the task according to the value of ADC
If the value of ADC is less then 8 all LEDs should be ON otherwise OFF                                                                     */
/************************************************************************/
								if (as<8)
								{
									PORTB=0b1111;
								}
								else
								{
									PORTB=0b0000;	
								}
								
		
	}
	
}