#include<stdio.h>
#include<reg51.h>
void delay(unsigned int);       
void count1(void);    
void count2(void);
sbit NR=P0^0; sbit NY=P0^1; sbit NG=P0^2; 
sbit ER=P0^4; sbit EY=P0^5; sbit EG=P0^6;
sbit WRR=P1^0; sbit WY=P1^1; sbit WG=P1^2; 
sbit SR=P1^4; sbit SY=P1^5; sbit SG=P1^6; 
unsigned char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
unsigned char b[]={0x3F,0x06,0x5B};
unsigned int i,j;             

void main()                           
  {
		P3=0xC0;
		P2=0xC0;
     NR=1; NY=1; NG=0;       
     SR=1; SY=1; SG=0;         
     ER=0; EY=1; EG=1;        
     WRR=0; WY=1; WG=1;
     count1();                            
     NR=1; NY=1; NG=0;    
     SR=1; SY=1; SG=0;      
     ER=1; EY=0; EG=1;     
     WRR=1; WY=0; WG=1;
		count2();                         
     NR=0; NY=1; NG=1;      
     SR=0; SY=1; SG=1;       
     ER=1; EY=1; EG=0;     
     WRR=1; WY=1; WG=0;
		 count1();
     NR=1; NY=0; NG=1;     
     SR=1; SY=0; SG=1;
     ER=1; EY=1; EG=0;      
     WRR=1; WY=1; WG=0;
     count2();
	 }
	
	 
  void count1(void)     
    {
			P0=~0x4F;
			P1=~0x3F;
			delay(100);
			for(j=2;j>=0;j--)
			{
				P0=~b[j];
        for(i=9;i>=0;i--)
        {
         P1=~a[i];
         delay(100);
        }
			}
    }
		
		
  void count2(void) {
			delay(300);
    }
		
		
		
  void delay(unsigned int time)   {   
    
      for(i=0;i<time;i++)     
       {
         for(j=0;j<1275;j++);
       }
    }