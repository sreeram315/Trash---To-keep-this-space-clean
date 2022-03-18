

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void buzzer()
{
	PORTB = 0;
	PORTD =0b00000100;						//To turn ON Buzzer (connected to PIN number PD2 )
	_delay_ms(500);							//Delay of Half second
	PORTD =0b00000000;						//To turn OFF Buzzer (connected to PIN number PD2 )
	_delay_ms(500);
									//turn PORTB zero.
	
}
int main(void)
{
	int i,j;
	DDRB = 0b11111111;						// For OUTPUT direction
	DDRD = 0b00000100;						// For Buzzer (connected to PIN number PD2 )
    while(1)								// infinite loop
    {
		buzzer();										//Buzzer function
		
		PORTB = 0b00001111;					//turn ON all 4 led
		_delay_ms(1000);					// delay of one second
		
		buzzer();										//Buzzer function
		
		for (i=0;i<=3;i++)
		{
			PORTB = (1<<i);					//led shifting	
			_delay_ms(500);								//delay of 1 second
		}
		
		buzzer();										//Buzzer function
		
		for (i=3;i>=0;i--)
		{
			PORTB = (1<<i);					//led shifting
			_delay_ms(500);								//delay of 1 second
		}
		
		buzzer();										//Buzzer function
		
        for (i=3,j=0;i>=2,j<=1;i--,j++)					//loop to shift LED for 0 to 3 
        {
			PORTB = (1<<i)|(1<<j);				// led shifting
			_delay_ms(1000);				// delay of one second
        }
		
		buzzer();										//Buzzer function
		buzzer();										//Buzzer function
    }
}