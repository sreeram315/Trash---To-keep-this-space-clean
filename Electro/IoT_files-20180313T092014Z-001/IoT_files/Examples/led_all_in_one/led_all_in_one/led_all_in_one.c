/*
 * led2.c
 *
 * Created: 8/24/2017 9:55:10 AM
 *  Author: traner
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i,j;
	DDRB = 0b11111111;									// For OUTPUT direction
    while(1)											// infinite loop
    {
		
		PORTB = 0b00001111;								//turn ON all 4 led
		_delay_ms(1000);								// delay of one second
		
		
		for (i=0;i<=3;i++)
		{
			PORTB = (1<<i);								//led shifting	
			_delay_ms(1000);								//delay of 1 second
		}
		
		for (i=3;i>=0;i--)
		{
			PORTB = (1<<i);								//led shifting
			_delay_ms(1000);								//delay of 1 second
		}
		
		
        for (i=3,j=0;i>=2,j<=1;i--,j++)					//loop to shift LED for 0 to 3 
        {
			PORTB = (1<<i)|(1<<j);						// led shifting
			_delay_ms(1000);							// delay of one second
        }
		
		
    }
}