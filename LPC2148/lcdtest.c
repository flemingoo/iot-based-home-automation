					 #define PCLK 60000000

#include <LPC214x.H>
#include "ADC0.h"
#include "delayMethods.h"
#include "PLLConfig.h"
#include "UART0.h"


void Delay_ms(unsigned long times);

unsigned int data;
unsigned int data1;
unsigned int data2;

int main()
{
		unsigned char project_topic[] = "HOME AUTOMATION";
		unsigned char temp_received[] = "TEMP VALUE:";
		unsigned char ldr_received[] = "LDR VALUE:";
		unsigned char less[] = "Value less than threshold";
		unsigned char greater[] = "Value greater than threshold";
	
		PLL_Config();
		UART0_Init();
		ADC0_Init();
		UART0_Write_Text(project_topic);
		UART0_Write(10);
		UART0_Write(13);
		
		while(1)
		{
				
				unsigned int temp_threshold= ((1.23*255)/3.3);
				unsigned int ldr_threshold = ((1.34*255)/3.3);
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
		}	
}

void Delay_ms(unsigned long times)
{
	unsigned long i,j;
	for(j=0;j<times;j++)
		for(i=0;i<500;i++);
}
