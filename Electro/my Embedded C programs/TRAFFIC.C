#include<stdio.h>
#include<reg51.h>
void delay(unsigned int);       
void count1(void);    
void count2(void);
sbit NR=P0^0; sbit NY=P0^1; sbit NG=P0^2; sbit NGL=P0^3; 
sbit ER=P0^4; sbit EY=P0^5; sbit EG=P0^6; sbit EGL=P0^7;  
sbit WER=P1^0; sbit WEY=P1^1; sbit WEG=P1^2; sbit WEGL=P1^3;  
sbit SR=P1^4; sbit SY=P1^5; sbit SG=P1^6; sbit SGL=P1^7; 
unsigned char a[10]={0x90,0x80,0xF8,0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};
unsigned char b[7]={0xA4,0xF9}; 
unsigned int i,j;             

void main()                           
  {
		P3=0xC0;
		P2=0xC0;
     NR=1; NY=1; NG=0; NGL=1;       
     SR=1; SY=1; SG=0; SGL=1;         
     ER=0; EY=1; EG=1; EGL=1;        
     WER=0; WEY=1; WEG=1; WEGL=1;   
      {
       count1();                            
      }
     NR=1; NY=1; NG=0; NGL=1;    
     SR=1; SY=1; SG=0; SGL=1;      
     ER=1; EY=0; EG=1; EGL=1;     
     WER=1; WEY=0; WEG=1; WEGL=1;
      {
       count2();                         
      }
     NR=0; NY=1; NG=1; NGL=1;      
     SR=0; SY=1; SG=1; SGL=1;       
     ER=1; EY=1; EG=0; EGL=1;     
     WER=1; WEY=1; WEG=0; WEGL=1;
      {
       count1();
      }
     NR=1; NY=0; NG=1; NGL=1;     
     SR=1; SY=0; SG=1; SGL=1;
     ER=1; EY=1; EG=0; EGL=1;      
     WER=1; WEY=1; WEG=0; WEGL=1;
       {
       count2();
       }
     
       
     }
  void count1(void)     //Sub routine for displaying numbers in segments for red signal
    {
    for(j=1;j>=0;j--)
      {
				P3=b[j];
       for(i=9;i>=0;i--)
       {
        P2=a[i];
        delay(100);
        }
      }
    }
  void count2(void) //Sub routine for displaying numbers in segments for yellow signal
    {
			delay(300);
    }
  void delay(unsigned int time)   {   //Sub routine for creating delay
    
      for(i=0;i<time;i++)     //Creating delay using number count
       {
         for(j=0;j<1275;j++);
       }
    }