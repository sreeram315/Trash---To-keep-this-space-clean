

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i,j;
	DDRB = 0b11111111;	// For OUTPUT direction
    while(1)			// infinite loop
    {
        for (i=3,j=0;i>=2,j<=1;i--,j++)					//loop to shift LED for 0 to 3 
        {
			PORTB = (1<<i)|(1<<j);			// led shifting
			_delay_ms(1000);				// delay of one second
        }
    }
}