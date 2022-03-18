#include<reg51.h>
sbit inc=P3^0;
sbit dec=P3^1;
unsigned int i=0;



void increment(){
	 unsigned char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	 if(i<999){
	 i+=1;
	 P1=~a[i/100];
		 
	
	 P2=~a[i%10];
	
	 
	 if(i<99)
	 P0=~a[i/10];
	 else if(i>99)
	 P0=~a[i/10%10];
	 
	 }
 }

void decrement(){
	 unsigned char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	 if(i>0){
	 i-=1;
	 P1=~a[i/100];
	 	
	 P2=~a[i%10];
	
	 if(i<99)
	 P0=~a[i/10];
	 else if(i>99)
	 P0=~a[i/10%10];
	 
	 }
 }



void main(void){
	unsigned char inc_pr=0,dec_pr=0;
	P3=0x00;
	P0=P2=P1=~0x3F;
		
	while(1){
		if(inc==1 && inc_pr==0){
			increment();
			inc_pr=1;
		}
		else if(inc!=1){
			inc_pr=0;
		}
		if(dec==1 && dec_pr==0){
			decrement();
			dec_pr=1;
		}
		else if(dec!=1){
			dec_pr=0;
		}
	}
}
			
			

		
