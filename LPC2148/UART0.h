void UART0_Init(void);
void UART0_Write(unsigned char value);
void UART0_Write_Text(unsigned char msg[]);
unsigned char UART0_Read(void);
 
void UART0_Init(void)
{
	PINSEL0 |= 0x00000005;				
	U0LCR = 0x83;								
	U0DLM = 0x00;
	U0DLL = 0x42;//62
	U0FDR = 0xF7;
	U0LCR = 0x03;									
}

void UART0_Write(unsigned char value)
{
	while(!(U0LSR&0x20));						
	U0THR = value;
}

void UART0_Write_Text(unsigned char msgT[])
{
	while(*msgT)
	{
		UART0_Write(*msgT);
		msgT++;
	}
}

unsigned char UART0_Read(void)
{
	while(!(U0LSR & 0x01));				
	return (U0RBR);
}

void UART0_Read_Text(unsigned char * msgR, int n)
{
	int i=0;
	for(;i < n ; i++)
	{
		*msgR = UART0_Read();
		msgR++;
	}
	*msgR = '\0';
}
