#define F_CPU 16000000
#include<avr/io.h>
#include<util/delay.h>

int main()
{
DDRA=0xff;
DDRB=0xff;
DDRC=0xff;
DDRD=0xff;

while(1)
{
PORTA=0xff;
_delay_ms(20);
 PORTB=0xff;
_delay_ms(100);
 
  PORTC=0xff;
 PORTD=0xff;
 
_delay_ms(100);
PORTA=0x00;
  PORTB=0x05;
  PORTC=0x00;
  PORTD=0x00;
 _delay_ms(500);
 }

 }
