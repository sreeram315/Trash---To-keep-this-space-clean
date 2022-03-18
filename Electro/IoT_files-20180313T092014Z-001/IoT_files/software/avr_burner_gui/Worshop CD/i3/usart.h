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