#include <reg51.h>

sbit buzz=P1^1;

void delay( unsigned char time){
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1575;j++);
}

unsigned char ex0_isr_counter = 0;

void buzzer (void) interrupt 0
{
buzz =0;
delay(100);
buzz=1;   
}


void main (void)
{
P0=0xFF;
/*-----------------------------------------------
Configure INT0 (external interrupt 0) to generate
an interrupt on the falling-edge of /INT0 (P3.2).
Enable the EX0 interrupt and then enable the
global interrupt flag.
-----------------------------------------------*/
	
	
IT0 = 0;   // Configure interrupt 0 for falling edge on /INT0 (P3.2)
EX0 = 1;   // Enable EX0 Interrupt
EA = 1;    // Enable Global Interrupt Flag


while (1); 
}
