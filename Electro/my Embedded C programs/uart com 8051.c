#include <reg51.h>                  
//Function Prototype
void Serial_Init(void);
void Send_Byte(unsigned char);	
char Receive_Byte(void);
void Send_String_Serially(char String[]);

void delay(unsigned int t){
	unsigned int i,j;
	for(i=0;i<1575;i++)
	for(j=0;j<t;j++);
}


void main()
{
	P3=0x00;
	Serial_Init();	//Initialze Serial communication by calling Serial_Init() function
  EA = 1;//Enable Globle interrupt
  ES = 1;//Enable Serial interrupt
//	Send_String_Serially("AT+UART_DEF=9600,8,1,0,0\r\n");
	//delay(500);
  Send_String_Serially("AT\r\n");
	delay(300);
	Send_String_Serially("ATE0\r\n");
	delay(300);
	Send_String_Serially("ATE+GMR\r\n");
	delay(300);
	Send_String_Serially("AT+CWMODE=1\r\n");
	delay(200);
	Send_String_Serially("AT+CWJAP=\"S\",\"123456789\"\r\n");
	
	delay(12000);
	
	Send_String_Serially("CIPMUX=1\r\n");

	delay(300);
	Send_String_Serially("AT+CIPSERVER=1,80\r\n");
	
	delay(300);
	Send_String_Serially("AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80\r\n");

	delay(800);
	Send_String_Serially("AT+CIPSEND=4,45\r\n");

	delay(300);
	Send_String_Serially("GET /update?key=IK9YW4JECCXYE3QH&field1=109\r\n");

	while(1)              
  {
    
  }
}
/*---------------------------------------------------------------------------------
                   void Serial_Init()
 ----------------------------------------------------------------------------------
 I/P Arguments: none
 Return value : none
 description  : This function is used for Initialize serial communication
-----------------------------------------------------------------------------------*/ 
void Serial_Init(void)		  
{
	TMOD = 0x20;// Timer 1 in mode 2 auto reload mode for baudrate generation
	SCON = 0x50;// Serial Mode 1, 8-DATA bit 1-Start Bit, 1-Stop Bit, Receive Enable
	TH1 = 0xFD;// Load value for 9600 baudrate
	TR1 = 1;// Start Timer
}
/*---------------------------------------------------------------------------------
                   void Send_Byte(unsigned char DATA)
 ----------------------------------------------------------------------------------
 I/P Arguments: character to be transmitt
 Return value : none
 description  : This function is used for Send byte Serially
-----------------------------------------------------------------------------------*/ 
void Send_Byte(unsigned char DATA)
{
    SBUF = DATA;	  //Load data into SBUF
    while(TI == 0); //Wait untill transmission to complete
    TI = 0;				  //Clear transmitte interrupt(TI) flag 
}
/*---------------------------------------------------------------------------------
                   char Receive_Byte(void)
 ----------------------------------------------------------------------------------
 I/P Arguments: none
 Return value : ASCII Code of Received character
 description  : This function is used for Receive byte 
-----------------------------------------------------------------------------------*/ 
char Receive_Byte(void)
{
    char Receive;
    while(RI == 0); //wait for character
    Receive = SBUF; //Read received data from SBUF
    RI=0;           //Clear Receive interrupt flag
    return Receive;
} 
/*---------------------------------------------------------------------------------
                   void Send_String_Serially(char String[])
 ----------------------------------------------------------------------------------
 I/P Arguments: String to be transmitted
 Return value : none
 description  : This function is used for Transmitte string 
-----------------------------------------------------------------------------------*/ 
void Send_String_Serially(char String[])
{
  unsigned char count;
  for(count=0;String[count]!='\0';count++)//Send single byte one by one untill null character in string 
  Send_Byte(String[count]);
}
/*---------------------------------------------------------------------------------
                   void serial_ISR (void) interrupt 4
 ----------------------------------------------------------------------------------
 I/P Arguments: none
 Return value : none
 description  : This function is automatically call when data received and transmitte
-----------------------------------------------------------------------------------*/ 
void serial_ISR (void) interrupt 4 //Serial interrupt
{
    //receive character
	char Receive;
	if(RI==1)
	{
		Receive = SBUF; //Read received data from SBUF
		RI = 0;//Clear Receive interrupt flag
    Send_Byte(Receive);//echo received character
	}
  
  P1 = Receive;//Display ASCII value of receive character at P1
	RI = 0;
}   	  
