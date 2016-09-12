#define PCLK 60000000

#include <LPC214x.H>
#include "ADC0.h"
#include "delayMethods.h"
#include "PLLConfig.h"
#include "UART0.h"
#include "lcd1.h"


__irq void isrUartReceive(void);
void Delay_ms(unsigned long times);

unsigned int data;
unsigned int data1;
unsigned int data2;
unsigned char * dataReceived;

int main()
{
		unsigned char project_topic[] = "HOME AUTOMATION";
		unsigned char temp_received[] = "TEMP VALUE:";
		unsigned char ldr_received[] = "LDR VALUE:";
		unsigned char less[] = "Value less than threshold";
		unsigned char greater[] = "Value greater than threshold";
		unsigned char motion[] = "Motion Detected";
		unsigned char nomotion[] = "Motion not deteccted";
		unsigned char dataDispText[] = "Data Received";
	
		PLL_Config();
		UART0_Init();
		ADC0_Init();
		// Interrupt Configuration
		VICIntSelect=0x00;
		VICVectCntl0=0x26;
		VICVectAddr0=(unsigned)isrUartReceive;
		VICIntEnable=0x40;
		U0IER = 0x01;
		Delay_ms(10);
		UART0_Write(10);
		UART0_Write(13);
		UART0_Write_Text(project_topic);
		UART0_Write(10);
		UART0_Write(13);
		
		while(1)
		{
				
				unsigned int temp_threshold= ((1.23*255)/3.3);
				unsigned int ldr_threshold = ((1.34*255)/3.3);
				UART0_Write_Text(dataDispText);
				UART0_Write_Text(dataReceived);
				UART0_Write(10);
				UART0_Write(13);
				UART0_Write(temp_threshold);
				UART0_Write(10);
				UART0_Write(13);
				UART0_Write(ldr_threshold);
				UART0_Write(10);
				UART0_Write(13);
			
				
				/*for temperature*/
				UART0_Write_Text(temp_received);
				data = ADC0_Read(1);
				if(data <= temp_threshold)
				{
				UART0_Write(data);
				UART0_Write(10);
				UART0_Write(13);
				UART0_Write_Text(less); 
				}
				else
				{
				UART0_Write(data);
				UART0_Write(10);
				UART0_Write(13);
				UART0_Write_Text(greater);
				}
				UART0_Write(10);
				UART0_Write(13);
				Delay_ms(50);
				
				
				/*for ldr*/
				UART0_Write_Text(ldr_received);
				data1 = ADC0_Read(2);
				if(data1 <= ldr_threshold)
				{
				UART0_Write(data1);
				UART0_Write(10);					
				UART0_Write(13);
				UART0_Write_Text(less);

				VICSoftInt = 0x40;					
				}
				else
				{
				UART0_Write(data1);
				UART0_Write(10);
				UART0_Write(13);
				UART0_Write_Text(greater);
				}
				UART0_Write(10);
				UART0_Write(13);
				Delay_ms(50);
				
				/*for PIR*/
				IODIR0 |= 0x00000004;	//P0.2 AS OUTPUT
				IOCLR0 |= 0X00000004; // buzzer off
				//adc_data2 = ADC0_Read(3);
				if((IO0PIN & 0x40000000)==0x40000000) // check for sensor pin P0.30 using bit masking                                              // 
				{ 	
						//if sensor detects motion 
						IOSET0 |=0x00000004;               // buzzer on (buzzer connected to P0.2)
						UART0_Write_Text(motion);
				 }
				else
				{
						IOCLR0 |=0x00000004;                   // buzzer off
						UART0_Write_Text(nomotion);
				}
		}	
}

void Delay_ms(unsigned long times)
{
	unsigned long i,j;
	for(j=0;j<times;j++)
		for(i=0;i<500;i++);
}


__irq void isrUartReceive()
{
	unsigned char dataRec[11];
	VICIntEnClr = 0x40; // Disable Int
	UART0_Read_Text(dataRec,10);
	dataRec[10]='\0';
	dataReceived = dataRec;
	//T0IR =1;
	VICVectAddr=0;
	VICIntEnable = 0x40; // Enable Int
}
