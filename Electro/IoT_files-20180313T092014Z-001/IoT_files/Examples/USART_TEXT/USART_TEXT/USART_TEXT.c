#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#define bs 7
#define w 4
#define d 6
#define con PORTC
int main(void)
{
	int r=0;
	int pr_r=0;
	DDRB=0B00000000;
//	DDRD=DDRD & (~(1<<4));
	DDRD=DDRD |(1<<6);
	DDRD=DDRD | (1<<5);
	PORTB=0b00000000;
//	PORTD|=(1<<4);
	
//	DDRB=0xFF;
	PORTD|=(1<<bs);
	PORTD&=~(1<<d);
	u_init();
	while(1)
	{
		usart_tx("AT\r\n");
		_delay_ms(900);
		usart_tx("ATE0\r\n");
		_delay_ms(900);
		usart_tx("AT+GMR\r\n");
		_delay_ms(900);
		usart_tx("AT+CWMODE=3\r\n");
		_delay_ms(1100);
		usart_tx("AT+CWJAP=\"S\",\"onetwonine\"\r\n");
		_delay_ms(15000);
		usart_tx("AT+CIPMUX=1\r\n");
		_delay_ms(1500);
		usart_tx("AT+CIPSERVER=1,80\r\n");
		_delay_ms(1500);
A:		PORTD&=(~(1<<bs));
B:		PORTD&=(~(1<<d));
		//goto B;
//		while(PINC&(1<<w));   
		PORTB|=(1<<bs);
		usart_tx("AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80\r\n");
		_delay_ms(2000);
		usart_tx("AT+CIPSEND=4,44\r\n");
		_delay_ms(2000);
//		r=31;
//		r=PINC;
//		PORTC=PORTB;
//		PINC=PINB;
		usart_tx("GET /update?key=F51MA6F1C1PL5C0E&field1=");
		PORTD|=(1<<d);
		
/*		if((~PINC & 0x1C)==0x00)
		usart_tx("28");
		else if((~PINC & 0x1D)==0x00)
		usart_tx("29");
		else if((~PINC & 0x1E)==0x00)
		usart_tx("30");
		else if((~PINC & 0x1F)==0x00)
		usart_tx("31");
		else if((~PINC & 0x20)==0x00)
		usart_tx("32");
		else if((~PINC & 0x21)==0x00)
		usart_tx("33");
		else if((~PINC & 0x22)==0x00)
		usart_tx("34");
		else if((~PINC & 0x23)==0x00)
		usart_tx("35");
		else if((~PINC & 0x24)==0x00)
		usart_tx("36");
		else if((~PINC & 0x25)==0x00)
		usart_tx("37");
		else if((~PINC & 0x26)==0x00)
		usart_tx("38");
		else if((~PINC & 0x27)==0x00)
		usart_tx("39");
		else if((~PINC & 0x28)==0x00)
		usart_tx("40");
		else if((~PINC & 0x29)==0x00)
		usart_tx("41");
		else if((~PINC & 0x2A)==0x00)
		usart_tx("42");
		else if((~PINC & 0x2B)==0x00)
		usart_tx("43");
		else if((~PINC & 0x2C)==0x00)
		usart_tx("44");
		else if((~PINC & 0x2D)==0x00)
		usart_tx("45");
		else if((~PINC & 0x2E)==0x00)
		usart_tx("46");
		else if((~PINC & 0x2F)==0x00)
		usart_tx("47");
		else if((~PINC & 0x30)==0x00)
		usart_tx("48");
		else if((~PINC & 0x31)==0x00)
		usart_tx("49");
		else if((~PINC & 0x32)==0x00)
		usart_tx("50");
		else if((~PINC & 0x33)==0x00)
		usart_tx("51");
		else if((~PINC & 0x34)==0x00)
		usart_tx("52");
		else if((~PINC & 0x35)==0x00)
		usart_tx("53");
		else if((~PINC & 0x36)==0x00)
		usart_tx("54");
		else if((~PINC & 0x37)==0x00)
		usart_tx("55");
		else
		usart_tx("99");*/

//		if((PORTC & 11010000)==)
		PORTD&=(~(1<<bs));
		C:
		r = PINB;
		if(r<28)
		goto C;
		_delay_ms(1);
		if(r==pr_r)
		goto C;
		
		PORTD|=(1<<bs);
		
		pr_r=r;
		
		switch(r)
		{
			case 28:
			usart_tx("28");
			break;
			
			case 29:
			usart_tx("29");
			break;
			
			case 30:
			usart_tx("30");
			break;
			
			case 31:
			usart_tx("31");
			break;
			
			case 32:
			usart_tx("32");
			break;
			
			case 33:
			usart_tx("33");
			break;
			
			case 34:
			usart_tx("34");
			break;
			
			case 35:
			usart_tx("35");
			break;
			
			case 36:
			usart_tx("36");
			break;
			
			case 37:
			usart_tx("37");
			break;
			
			case 38:
			usart_tx("38");
			break;
			
			case 39:
			usart_tx("39");
			break;
			
			case 40:
			usart_tx("40");
			break;
			
			case 41:
			usart_tx("41");
			break;
			
			case 42:
			usart_tx("42");
			break;
			
			case 43:
			usart_tx("43");
			break;
			
			case 44:
			usart_tx("44");
			break;
			
			case 45:
			usart_tx("45");
			break;
			
			case 46:
			usart_tx("46");
			break;
		
			case 47:	
			usart_tx("47");
			break;
			
			case 48:
			usart_tx("48");
			break;
			
			case 49:
			usart_tx("49");
			break;
			
			case 50:
			usart_tx("50");
			break;
			
			case 51:
			usart_tx("51");
			break;
			
			case 52:
			usart_tx("52");
			break;
			
			default:
			goto C;
		}
		pr_r=r;
	//	usart_tx("47");
		usart_tx("\r\n");
		
		_delay_ms(2000);
		
		_delay_ms(100);
		PORTD&=(~(1<<bs));
		PORTD|=(1<<d);
	//	PORTB&=~(1<<d);	
		goto A;
//	while(1);
	}
	
}