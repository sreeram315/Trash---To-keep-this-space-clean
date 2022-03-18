
#include<reg51.h>
#define LCD_Data_Bus	P1 //	LCD data pin connected to PORT1


#define FirstLine  0x80
#define SecondLine 0xC0
sbit _RS= P2^2;		 // Register select pin connected to P2.2
sbit _RW= P2^1;		 // Read/Write pin connected to P2.1
sbit _EN= P2^0;		 // Enable pin connected to P2.0



void Delay_ms(unsigned int ms);
void LCD_Init(void);
void LCD_Clear(void);
void LCD_Cmd(char cmd);
void LCD_Data(char Data);
void LCD_DisplayString(char String[]);



 void main()
 {
    LCD_Init();//Initilize the lcd before displaying any thing on the lcd 
    LCD_Clear();//Clear LCD Screen
    LCD_DisplayString("    SILICON     ");//Display on first line
    LCD_Cmd(SecondLine);//Goto Second Line
    LCD_DisplayString("   TECHNOLABS   ");//Display on Second Line
    while(1);  
 }
/*----------------------------------------------------------------------------------
                         void Delay_ms(unsigned int ms)
 -----------------------------------------------------------------------------------
 I/P Arguments: unsigned int.
 Return value	: none
 description  : This function is used generate delay in ms.
                if ms = 1000 then it generates delay of apprx 1sec
-----------------------------------------------------------------------------------*/
void Delay_ms(unsigned int ms)
 {
  unsigned int i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<127;j++);
 }
/*----------------------------------------------------------------------------------
                         void LCD_Init()
 ----------------------------------------------------------------------------------
 Function name:  LCD_Init()
 I/P Arguments: none.
 Return value	: none
 description  :This function is used to initialize the lcd in 8-bit mode

----------------------------------------------------------------------------------*/
void LCD_Init()
{
   Delay_ms(5);
   LCD_Cmd(0x38);	//Initilize the LCD in 8bit Mode
   LCD_Cmd(0x0E);	// Display ON cursor ON
   LCD_Cmd(0x01);	// Clear the LCD
   LCD_Cmd(0x80);	// Move the Cursor to First line First Position

}
/*---------------------------------------------------------------------------------
                         void LCD_Clear()
 ----------------------------------------------------------------------------------
 I/P Arguments: none.
 Return value	: none
 description  :This function clears the LCD and moves the cursor to first Position

-----------------------------------------------------------------------------------*/
void LCD_Clear()
{
   LCD_Cmd(0x01);	// Clear the LCD and go to First line First Position
}
/*----------------------------------------------------------------------------------
                       void LCD_Cmd( char cmd)
------------------------------------------------------------------------------------
 I/P Arguments: 8-bit command supported by LCD.
 Return value	: none
 description  : This function sends a command to LCD in the following steps.
                Set RS low for Command.
                Set RW low for Write.
                Send the 8bit of the I/P command to LCD.
                Send a High-to-Low pulse on Enable PIN with some delay_us.
----------------------------------------------------------------------------------*/
void LCD_Cmd( char cmd)
{
   _RS=0;						// RS = 0 for Command.
   _RW=0;						// RW = 0 for write.
   LCD_Data_Bus=cmd; // 8bit command to LCD.
   _EN=1;						// Send a High-to-Low Pusle at Enable Pin.
	 Delay_ms(2);
   _EN=0;
   Delay_ms(2);
}
/*---------------------------------------------------------------------------------
                       void LCD_Data( char Data)
 ----------------------------------------------------------------------------------
 Function name: LCD_Data()
 I/P Arguments: ASCII value of the char to be displayed.
 Return value	: none
 description  : This function sends a DATA to LCD in the following steps.
                Set RS high for Data.
                Set RW low for Write.
                Send the 8bit Data to LCD.
                Send a High-to-Low Pusle at Enable Pin.
----------------------------------------------------------------------------------*/
void LCD_Data( char Data)
{
   _RS=1;						// RS = 1 for Data.
   _RW=0;						// RW = 0 for write.
   LCD_Data_Bus=Data; // 8bit command to LCD.
   _EN=1;						// Send a High-to-Low Pusle at Enable Pin.
	 Delay_ms(2);
   _EN=0;
   Delay_ms(2);
}
/*---------------------------------------------------------------------------------
                       void LCD_DisplayString(char String[])
 ----------------------------------------------------------------------------------
 Function name:  LCD_DisplayString()
 I/P Arguments:  String to be displayed.
 Return value	:  none
 description  :  This function is used to display the ASCII string on the lcd.                           
-----------------------------------------------------------------------------------*/
void LCD_DisplayString(char String[])
{
   unsigned char i;
   for(i=0;String[i]!='\0';i++)
    LCD_Data(String[i]);
}
