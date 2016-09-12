#define PCLK 60000000

#include <LPC214x.H>
#include <stdlib.h>
#include <stdio.h>

#include "ADC0.h"
#include "delayMethods.h"
#include "PLLConfig.h"
#include "UART0.h"
#include "LCD.h"
#include "str2int.h"


void Delay_ms(unsigned long times);

unsigned int data;
unsigned int data1;
unsigned int data2;
double adcResolution = 3.3/255;
float dataFloat;


int main()
{
		unsigned char project_topic[] = "HOME AUTOMATION";
		unsigned char temp_received[] = "TEMP ";
		unsigned char ldr_received[] = "LDR ";
		unsigned char less[] = "Value less than threshold";
		unsigned char greater[] = "Value greater than threshold";
		unsigned char string_clear[15]="               ";
		unsigned char dataDisp[]="Data :";
		unsigned char dataDisp1[]="Data1 :";
		char temp_threshold_str[15];0
		char ldr_threshold_str[15];
		unsigned int temp_threshold;
		unsigned int ldr_threshold;
		char * dataReceived;
		int val;

		PLL_Config();
		Lcd_Init();
		UART0_Init();
		ADC1_Init();
		Lcd_GotoXY(0,2);
		UART0_Write_Text(project_topic);
		Lcd_String(project_topic);
		delay_ms(15);
		temp_threshold= (1.23/adcResolution);
		ldr_threshold = (1.34/adcResolution);
		
		while(1)
		{
				UART0_Read_Text(dataReceived,9);
				//string split function
				val = myAtoi(dataReceived);
				Lcd_GotoXY(0,2);
				Lcd_String(string_clear);
				Lcd_GotoXY(0,1);
				Lcd_String(string_clear);
				Lcd_GotoXY(0,2);
				Lcd_String(dataDisp);
				Lcd_GotoXY(6,2);
				Lcd_String(dataReceived);
				UART0_Write_Text(dataDisp);
				UART0_Write_Text(dataReceived);
				sprintf(temp_threshold_str,"%d",temp_threshold);
				Lcd_GotoXY(0,1);
				Lcd_String(temp_threshold_str);
				UART0_Write(10);
				UART0_Write(13);
				UART0_Write_Text(dataDisp1);
				UART0_Write_Text(temp_threshold_str);
							
				
				//sprintf(temp_threshold_str,"%d",temp_threshold);
				//Lcd_GotoXY(0,1);
				//Lcd_String(temp_threshold_str);
				//Lcd_GotoXY(3,1);
				//sprintf(ldr_threshold_str,"%d",ldr_threshold);
				//Lcd_String(ldr_threshold_str);
				//Lcd_GotoXY(0,2);
				//delay_ms(10);
				
				/*for temperature*/
				data = ADC1_Read(3);
				sprintf(temp_threshold_str,"%d",data);
				Lcd_GotoXY(0,1);
				Lcd_String(temp_threshold_str);
				if(data <= temp_threshold)
				{
				dataFloat = (data*adcResolution)/0.01;
				sprintf(temp_threshold_str,"%f",dataFloat);
				Lcd_GotoXY(7,1);
				Lcd_String(temp_threshold_str);

				UART0_Write_Text(temp_received);
				UART0_Write_Text(less); 
				}
				else
				{
				dataFloat = (data*adcResolution)/0.01;
				sprintf(temp_threshold_str,"%f",dataFloat);
				Lcd_GotoXY(7,1);
				Lcd_String(temp_threshold_str);

				UART0_Write_Text(temp_received);
				UART0_Write_Text(greater);
				}
				UART0_Write(10);
				UART0_Write(13);
				delay_ms(10);
				
				
				/* for ldr */
				Lcd_GotoXY(0,2);
				Lcd_String(string_clear);
				data = ADC1_Read(4);
				sprintf(temp_threshold_str,"%d",data);
				Lcd_GotoXY(0,2);
				Lcd_String(temp_threshold_str);
				if(data <= ldr_threshold)
				{
				dataFloat = (data*adcResolution)/0.01;
				sprintf(ldr_threshold_str,"%f",dataFloat);
				Lcd_GotoXY(7,2);
				Lcd_String(ldr_threshold_str);

				UART0_Write_Text(ldr_received);
				UART0_Write_Text(less); 
				}
				else
				{
				dataFloat = (data*adcResolution)/0.01;
				sprintf(ldr_threshold_str,"%f",dataFloat);
				Lcd_GotoXY(7,2);
				Lcd_String(ldr_threshold_str);

				UART0_Write_Text(ldr_received);
				UART0_Write_Text(greater);
				}
				UART0_Write(10);
				UART0_Write(13);
				Delay_ms(10);
		}
			
}

void Delay_ms(unsigned long times)
{
	unsigned long i,j;
	for(j=0;j<times;j++)
		for(i=0;i<500;i++);
}

