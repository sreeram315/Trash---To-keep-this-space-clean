#include<reg51.h>

sbit pir_out = P0^1;
sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;



void delay(unsigned int z)
{
  unsigned int p,q;
  for(p=0;p<z;p++)    
  for(q=0;q<1375;q++);   
}

void lcd_cmd(unsigned char a){
	P2 = a;
	rs = 0;
	rw = 0;
	en = 1;
	delay(1);
	en=0;
}

void lcd_data(unsigned char a){
	
	P2=a;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
}

void A30_sec_counter()
{
	unsigned char i,j,a[3]={0x30,0x31,0x32};
	unsigned char b[10]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
	lcd_cmd(0xC0);
	for(i=2;i>=0;i--)
	{
		
		lcd_data(a[i]);
		for(j=9;j>=0;j--)
		{
			lcd_data(b[j]);
			delay(99);
			lcd_cmd(0x10);
			if(j==0)
				break;
		}
		lcd_cmd(0xC0);
		if(i==0)
			break;
	
	}
	
}

void lcd_line(int *ptr)
{
	unsigned char i=0;
	while( ptr[i] != '\0')
	{
		lcd_data(ptr[i]);
		delay(10);
	}
}



void lcd_ini(){
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);
	lcd_cmd(0x80);
}


	
int main(){
	unsigned char prv_state = 0;
	unsigned char b[] = "People entered: ", h[] = "Stabling PIR:",c[]="MAX amount 10",d[]="Close the door";
	unsigned char i=0,a=1;
	P0=0x00;
	P2=0xFF;
	P1=0xFF;
	lcd_ini();
	i=0;
	while( h[i] != '\0')
	{
		lcd_data(h[i]);
		i++;
	}
	A30_sec_counter();
	lcd_ini();
	i=0;
	while( b[i] != '\0')
	{
		lcd_data(b[i]);
		i++;
	}
	lcd_cmd(0xC0);
	lcd_data(0x30);
	while(1)
	{
		unsigned char count[]={0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
			if( pir_out==1 && prv_state==0)
			{
										if(a>=9){
											lcd_ini();
											i=0;
											while( c[i] != '\0')
											{
												lcd_data(c[i]);
												i++;
											}
											lcd_cmd(0xC0);
											i=0;
											while( d[i] != '\0')
											{
												lcd_data(d[i]);
												i++;
											}
											while(1);
											}
				lcd_cmd(0xC0);
				lcd_data(count[a]);
				a++;
				
			}
			if (pir_out == 0)
			{
				prv_state=0;
			}
			if( pir_out ==1)
			{
				prv_state=1;
			}
	}
}
	
