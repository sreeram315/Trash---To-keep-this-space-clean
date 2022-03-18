/*
 * lcd_blinking.c
 *
 * Created: 8/18/2017 4:51:36 PM
 *  Author: traner
 */ 


#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0xff;
	int i=0;
    while(1)
    {
		for(i=0;i<4;i++)
		{
        PORTB |= (1<<i);		
		_delay_ms(1000);
		PORTB &=~ (1<<i);
		_delay_ms(1000);
		}
}
}