
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i;
	DDRB = 0b11111111;				// For OUTPUT direction
    while(1)						// infinite loop
    {
        for (i=3;i>=0;i--)				//loop to shift LED for 0 to 3 
        {
			PORTB = (1<<i);			// led shifting
			_delay_ms(1000);		// delay of one second
        }
    }
}