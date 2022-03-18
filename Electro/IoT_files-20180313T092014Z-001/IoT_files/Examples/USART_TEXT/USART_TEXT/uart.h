/*
 * IncFile1.h
 *
 * Created: 1/23/2018 10:51:13 AM
 *  Author: ancha
 */ 
#ifndef _Buzzer_
#define _Buzzer_
void buzzer()
	{
			PORTD|=(1<<2);
			_delay_ms(100);
			PORTD&=~(1<<2);
			_delay_ms(100);
	}			
#endif

#ifndef _UART_H_
#define _UART_H_


unsigned char rx()
{
	
	while(!(UCSRA&(1<<RXC)));
	PORTB = UDR;
}

void tt(unsigned char t)
{
	while(!(UCSRA&(1<<UDRE)));				// hold until conversion is completed
	UDR=t;									// PUT data into UDR registor
}

/*usart_tx_int(unsigned int *tx)
{
	while(*tx!='\0')
	{
		tt(*tx);
		tx++;
	}
}*/
void usart_tx(unsigned char *tx)
{
	while(*tx!='\0')						// transfer data until we get NULL character ('\0')
	{
		tt(*tx);
		tx++;								// next character
	}
}
void u_init()
{
	UBRRL=8;					// PUT that value for 115200 BAUDRATE by chart
	UCSRB|=(1<<TXEN)|(1<<RXEN);				// transmitt enable
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);	// setting for 8 bit character size (ex: 'A' = 01000001)
}




#endif /* _UART_H_ */