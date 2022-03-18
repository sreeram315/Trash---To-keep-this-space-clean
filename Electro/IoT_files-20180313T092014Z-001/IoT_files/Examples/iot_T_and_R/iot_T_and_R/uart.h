


						void tt(unsigned char t)
						{
							while(!(UCSRA&(1<<UDRE)));				// hold until conversion is completed
							UDR=t;									// PUT data into UDR registor
						}


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
							UCSRB|=(1<<TXEN);				// transmitt enable
							UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);	// setting for 8 bit character size (ex: 'A' = 01000001)
						}




