#include<reg51.h> //Header file FOR 8051

//Rows connected to lower 4-Bits of P1                     
sbit R0 = P1^0;
sbit R1 = P1^1;
sbit R2 = P1^2;
sbit R3 = P1^3;
//Columns connected to higher 4-Bits of P1
sbit C0 = P1^4;
sbit C1 = P1^5;
sbit C2 = P1^6;
sbit C3 = P1^7;

#define Keypad_Port P1 //keypad connected to P1
 /* function Prototype*/
unsigned char Keypad_Scan(void);
unsigned char Get_key(void);

void main()
{
  unsigned char Key_data;
  while(1)
  {
    Key_data = Get_key();
    P2 = Key_data;
  }
}

/*---------------------------------------------------------------------------------
                   void Keypad_Scan()
 ----------------------------------------------------------------------------------
 I/P Arguments: none
 Return value : Value of key pressed
 description  : This function is used for the rows and colums scan
-----------------------------------------------------------------------------------*/                      
unsigned char Keypad_Scan()
{
/*********************Scane Row0**************************/ 
  R0 = 0;  //Make ROW0 to low(0)
  R1=R2=R3=1;//Make All other Row to high(1)
  if(C0 == 0)//If Switch in columns0 is pressed
  {
      return 1;
      //return '1'; //for LCD
  }
  if(C1 == 0)//If Switch in columns1 is pressed
  {
     return 2;
      //return '2'; //for LCD
  }
  if(C2 == 0)//If Switch in columns2 is pressed
  {
      return 3;
    //return '3'; //for LCD
  }
  if(C3 == 0)//If Switch in columns3 is pressed
  {
      return 4;
      //return '4'; //for LCD
  }
  
/*********************Scane Row1**************************/
  R1 = 0;  //Make ROW1 to low(0)
  R0=R2=R3=1;//Make All other Row to high(1)
  if(C0 == 0)//If Switch in columns0 is pressed
  {
    return 5;
      //return '5'; //for LCD
  }
  if(C1 == 0)//If Switch in columns1 is pressed
  {
    return 6;
      //return '6'; //for LCD
  }
  if(C2 == 0)//If Switch in columns2 is pressed
  {
    return 7;
      //return '7'; //for LCD
  }
  if(C3 == 0)//If Switch in columns3 is pressed
  {
    return 8;
      //return '8'; //for LCD
  }
/*********************Scane Row2**************************/ 
  R2 = 0;  //Make ROW2 to low(0)
  R0=R1=R3=1;//Make All other Row to high(1)
  if(C0 == 0)//If Switch in columns0 is pressed
  {
    return 9;
      //return '9'; //for LCD
  }
  if(C1 == 0)//If Switch in columns1 is pressed
  {
    return 0;
      //return '0'; //for LCD
  }
  if(C2 == 0)//If Switch in columns2 is pressed
  {
    return 10;
      //return 'A'; //for LCD
  }
  if(C3 == 0)//If Switch in columns3 is pressed
  {
    return 11;
      //return 'B'; //for LCD 
  }
/*********************Scane Row3**************************/   
  R3 = 0;  //Make ROW3 to low(0)
  R0=R1=R2=1;//Make All other Row to high(1)
  if(C0 == 0)//If Switch in columns0 is pressed
  {
     return 12;
      //return 'C'; //for LCD
  }
  if(C1 == 0)//If Switch in columns1 is pressed
  {
    return 13;
      //return 'D'; //for LCD
  }
  if(C2 == 0)//If Switch in columns2 is pressed
  {
    return 14;
      //return 'E'; //for LCD
  }
  if(C3 == 0)//If Switch in columns3 is pressed
  {
    return 15;
      //return 'F'; //for LCD
  }
  return '\0';
}
/*---------------------------------------------------------------------------------
                   void Keypad_Scan()
 ----------------------------------------------------------------------------------
 I/P Arguments: none
 Return value : Value of key
 description  : This function waits untill a key is pressed and retuns Value of key pressed
-----------------------------------------------------------------------------------*/   
unsigned char Get_key()
{
  unsigned char Key_data;
  
  /*WaitForKeyRelease*/
    do
      {
        Keypad_Port=0xF0;                 // Set ROW lines to low(0) and Column lines to high(1).
        Key_data=Keypad_Port & 0xF0;      // Read the Columns and check the key press.
       }
     while(Key_data!=0xF0);                    // Wait untill the Key is released,
                                          // If no Key is pressed, Column lines will be High(0xF0) untill no key pressed.
                                          
   /*WaitForKeyPress*/
   do
   {
     do
      {
        Keypad_Port=0xF0;        // Set ROW lines to low(0) and Column lines to high(1).
        Key_data=Keypad_Port & 0xF0;   // Read the Columns, to check the key press
      }
      while(Key_data==0xF0); // Wait untill the Key is pressed,If no Key is pressed
                          // if a Key is pressed the corresponding Column line go low

       //to Confirm key is pressed
       Keypad_Port=0xF0;          // After some time, perform the above action to ensure the
       Key_data=Keypad_Port & 0xF0;    // the Key press.
    }while(Key_data==0xF0);
 
   Key_data =  Keypad_Scan();//// Scan for the key pressed.
   
   return Key_data;
}

 
