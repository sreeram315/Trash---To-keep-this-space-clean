

#define Baud_Rate 9600UL
#define ubrr_value ((F_CPU/(16UL*Baud_Rate)) - 1)

void usart_init()
{

   //Set Baud rate
   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);


   UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
   

   //Enable The receiver and transmitter

   UCSRB=(1<<RXEN)|(1<<TXEN);

}

////////////////////////////////////////////////

void usart_send(unsigned char data)
{
  //Wait until the transmitter is ready

   while(!(UCSRA & (1<<UDRE)))
   {
      //Do nothing
   }

   //Now write the data to USART buffer

   UDR=data;
}

////////////////////////////////////////////////

unsigned char usart_rec()
{
 //Wait untill a data is available

   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}
////////////////////////////////////////////////

void usart_string(unsigned char *str)
{
while(*str)
{
usart_send(*str++);
}
}
/////////////////////////////////////////////
void usart_num(unsigned int value)
{ 
unsigned int d=0,j=0;
unsigned char val[5]={'\0'};
 for(int i=3;i>=0;i--)
 {
 	d=value%10; 
	    val[i]=d+48;
	value=value/10;
}	
usart_string(val);
}

//////////////////////////////////////////

void adc_init()
{
	ADMUX = 0B01000000;
	ADCSRA =0b10000111; 
	}

///////////////////////////////////////////////////

unsigned int adc_read(unsigned char ch)
{	
	
	ADMUX=0x40|ch; 
	ADCSRA|=0b01000000;
	while((ADCSRA&0b00010000)==0b00000000);
        ADCSRA|=0b00010000;
	return ADC;
}
