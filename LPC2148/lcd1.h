#include <LPC214X.H>

/**********LCD Pin Configuration**********/
#define RS 16
#define RW 17
#define EN 18
//These all are connected on Port-0 of Controller, so make sure before using IOSET and IOCLR Functions
/*****************************************/

/***********FUNCTION PROTOTYPE***********/
void Delay(unsigned long value);
void Write_Cmd(unsigned int value);
void Write_Data(unsigned int value);
void Lcd_Init(void);                        //Initialize Lcd Module
void Lcd_Data(unsigned int value);			//Send Data to LCD
void Lcd_Cmd(unsigned int value);			//Send Command to LCD
void Lcd_String(unsigned char*);		 	//Display String
void Lcd_Write_Int(int,int);				//Display Integer in specified field length
void Lcd_GotoXY(int,int);					//Cursor Goto XY
/****************************************/


/***********FUNCTION DEFINITION************/

void Delay(unsigned long value)
{
     while(value>0)
    {
        value--;
    }
}
void Lcd_Init(void)
{    
    IO0DIR |= 0x07F0000;
    //Pins P0.16 to P0.22 as Output Pin
    Delay(200000);
    Write_Cmd(0x30<<15);
    Delay(100000);
    Write_Cmd(0x30<<15);
    Delay(100000);
    Write_Cmd(0x30<<15);
    Delay(100000);
    Write_Cmd(0x20<<15);
    //These are the Commands for LCD Initialization in 4-Bit Mode
    /*Lcd_Cmd(0x01);
    Lcd_Cmd(0x06);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x80);*/
	Lcd_Cmd(0x28);
    Lcd_Cmd(0x08);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x06);
}

void Write_Cmd(unsigned int value)
{
    //First of all Clear the LCD Data Pins
    IO0CLR |= 0x00780000;
    //To Write RW = 0
    IO0CLR |= (1<<RW);
    //Write to Command Register RS = 0
    IO0CLR |= (1<<RS);
    //Write to Pins
    IO0SET |= 0x00780000 & value;
    IO0SET |= (1<<EN);
    Delay(40000);
    IO0CLR |= (1<<EN);
}

void Write_Data(unsigned int value)
{
       //First of all Clear the LCD Data Pins
    IO0CLR |= 0x00780000;
    //To Write RW = 0
    IO0CLR |= (1<<RW);
    //Write to Data Register RS = 1
    IO0SET |= (1<<RS);
    //Write to Pins
    IO0SET |= 0x00780000 & value;
    IO0SET |= (1<<EN);
    Delay(30000);
    IO0CLR |= (1<<EN);
}
void Lcd_Cmd(unsigned int value)
{
    Write_Cmd(value<<15);
    Write_Cmd(value<<19);
}
void Lcd_Data(unsigned int value)
{
    Write_Data(value<<15);
    Write_Data(value<<19);
}
void Lcd_String(unsigned char *data)
{
    while(*data != '\0')
    {
        Lcd_Data(*data);
        data++;
        Delay(10000);
    }
}

void Lcd_Write_Int(int val,int field_length)
{
	char str[5]={0,0,0,0,0};
	int i=4,j=0;

        //Handle negative integers
        if(val<0)
        {
            Lcd_Data('-');   //Write Negative sign
            val=val*-1;     //convert to positive
        }

	while(val)
	{
            str[i]=val%10;
            val=val/10;
            i--;
	}
	if(field_length==-1)
		while(str[j]==0) j++;
	else
		j=5-field_length;

	
	for(i=j;i<5;i++)
	{
	Lcd_Data(48+str[i]);
	}
}

void Lcd_GotoXY(int x,int y)
{
	switch(y)
	{
		case 0:
			break;
		case 1:
			x|=0x40;
			break;
	}

	x|=0x80;
  	Lcd_Cmd(x);
}  
