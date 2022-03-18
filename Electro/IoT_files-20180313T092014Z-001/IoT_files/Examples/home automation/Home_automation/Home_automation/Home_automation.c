/************************************************************************/
/* Name transmission from controller to PC
This program works on 16Mhz (115200 BAUDRATE)                                                                    */
/***********************************************************************/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "uart.h"
unsigned char as[10],LK;
int main(void)
{
	DDRB = 0B11111111;					//PORTB as OUTPUT PORT
	DDRA |=(1<<PA7);						// OUTPUT direction for Buzzer
	
	u_init();							//uart initialization
	
	usart_tx("AT+CWQAP\r\n");
	/************************************************************************/
	/* Turning All LEDs one by one                                                                     */
	/************************************************************************/
	for (int i=0;i<=3;i++)
	{
		PORTB |= (1<<i);
		buzzer();
	}

	
	usart_tx("AT\r\n");
	_delay_ms(500);
	
	usart_tx("ATE1\r\n");
	_delay_ms(500);
	
	usart_tx("AT+CWJAP=\"anchal\"\,\"qwerqwer\"\r\r\n");
	delay;	buzzer();
	delay;	buzzer();
	delay;	buzzer();
	delay;
	
	while(1)
	{
		usart_tx("AT");
		usart_tx("\r\n");
		
		_delay_ms(500);
		
		usart_tx("ATE1\r\n");
		_delay_ms(500);
		
		usart_tx("AT+CIPMUX=1\r\n");
		_delay_ms(500);
		
		usart_tx("AT+CIPSERVER=1,80\r\n");
		_delay_ms(500);
		
		usart_tx("AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80\r\n");
		delay;delay;
		
		usart_tx("AT+CIPSEND=4,64\r\n");
		_delay_ms(500);
		
		usart_tx("GET /channels/341118/feeds.json?key=T30AHEJS0JGGRPIR&results=1\r\n");
		
		for (i=0;i<=297;i++)
		{
			LK = rx();
		}
		
		for (i=0;i<='6'&& LK!='f';i++)
		{
			LK = rx();
		}
		
		for (i=0;i<='6'&& LK!=':';i++)
		{
			LK = rx();
		}
		
		y = rx();
		LK = rx();
		
		for (int k=0;k<=6&&LK!='"';k++)
		{
			as[k]=LK;
			LK = rx();
		}
		
		PORTB=0xff;PORTA|=(1<<PA7);
		y=atoi(as);
		_delay_ms(1000);
		PORTB=0;PORTA&=~(1<<PA7);
		
		for (int u=0;u<=9;u++)
		{
			as[u]='\0';
		}
		if (y<=8)
		{
			PORTB = 0x0f;
		}
		else
		PORTB = 0;
		
		
	}
}


