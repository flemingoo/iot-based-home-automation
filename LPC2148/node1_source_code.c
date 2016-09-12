#define NODE 1
#define PCLK 60000000


#include <LPC214x.H>
#include <stdlib.h>
#include <stdio.h>

#include "ADC1.h"
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
float dataFloat,RLDR,LUX;


int main()
{
		unsigned char project_topic[] = "HOME AUTOMATION";
		//unsigned char temp_received[] = "TEMP ";
		//unsigned char ldr_received[] =  "LIGHT ";
		//unsigned char less[] = "Value less than threshold";
		//unsigned char greater[] = "Value greater than threshold";
		unsigned char string_clear[]="                ";
		//unsigned char dataDisp1[]="Data1 :";
		//unsigned char dataDisp2[]="Data2 :";
		char temp_data_str[15];
		char ldr_data_str[15];
		unsigned int temp_threshold;
		unsigned int ldr_threshold;
		unsigned int temp_threshold_10;
		unsigned int ldr_threshold_10;
		unsigned char dataReceived[8];
		unsigned char node[2];
		unsigned char nParam[2];
		unsigned char val[5];
		int i_node,i_val;
		int i_val_4;
		//unsigned char c_nParam;

		PLL_Config();
		Lcd_Init();
		UART0_Init();
		ADC1_Init();
		PINSEL0 &= 0xFFFFFFF3;
		IO0DIR |= 0x0C;
		Lcd_GotoXY(0,1);
		Lcd_String(string_clear);
		Lcd_GotoXY(0,2);
		Lcd_String(string_clear);
		//UART0_Write_Text(project_topic);
		Lcd_GotoXY(0,2);
		Lcd_String(project_topic);
		delay_ms(15);
		Lcd_GotoXY(0,2);
		Lcd_String(string_clear);
		//temp_threshold= (1.23/adcResolution);
		//ldr_threshold = (2.20/adcResolution);
		
		while(1)
		{
					StringSplitRead(node,nParam,val);
					/*Lcd_GotoXY(0,2);
					Lcd_String(string_clear);
					Lcd_GotoXY(0,2);
					Lcd_String(dataReceived);
					*/
					///debugg///
					/*UART0_Write_Text("Received:::");
					UART0_Write_Text(dataReceived);
					UART0_Write_Text("Node=");
					UART0_Write_Text(node);							
					UART0_Write_Text("Field=");
					UART0_Write_Text(nParam);
					UART0_Write_Text("Value=");
					UART0_Write_Text(val);
					delay_ms(10);
					strSplit(dataReceived, node,nParam,val);	 */
					///debugg///
					
					i_node = str2int(node);
					if(NODE == i_node)
					{
							i_val = str2int(val);
							i_val_4 = i_val >> 2; 

							///debugg///
							/*UART0_Write_Text(" Node:");
							UART0_Write_Text(node);
							UART0_Write(10);
							UART0_Write(13);
							UART0_Write_Text(" Parameter:");
							UART0_Write_Text(nParam);
							UART0_Write(10);
							UART0_Write(13);
							UART0_Write_Text("Value:");
							UART0_Write_Text(val);
							UART0_Write(10);
							UART0_Write(13); */
							///debugg///
			
							if(nParam[0] == 'T')
							{
								temp_threshold = i_val_4;
								temp_threshold_10 = i_val_4;
								//UART0_Write_Text("*** T SET ***");
							}
							else if(nParam[0] == 'L')
							{
								ldr_threshold = i_val_4;
								ldr_threshold_10 = i_val_4;
								//UART0_Write_Text("*** L SET ***");
							}

							UART0_Write(10);
							UART0_Write(13);
							UART0_Write_Text(" Temp Threshold:");
							sprintf(temp_data_str,"%d",temp_threshold_10);
							UART0_Write_Text(temp_data_str);
							UART0_Write(10);
							UART0_Write(13);
							UART0_Write_Text(" Ldr Threshold:");
							sprintf(temp_data_str,"%d",ldr_threshold_10);
							UART0_Write_Text(temp_data_str);
							UART0_Write(10);
							UART0_Write(13);

							/***************for temperature********************/

							data = ADC1_Read(3);  //P0.12
							
							
							sprintf(temp_data_str,"%d",data);
							Lcd_GotoXY(0,2);
							Lcd_String("Temp:");
							///debug///
							UART0_Write_Text(" Temp Data:");
							UART0_Write_Text(temp_data_str);
							///debug///

							if(data <= temp_threshold)
							{
							IO0SET |= 1<<2;
							dataFloat = (data*adcResolution)/0.01;
							sprintf(temp_data_str,"%f",dataFloat);
							Lcd_GotoXY(5,2);
							Lcd_String(temp_data_str);
							Lcd_GotoXY(13,2);
							Lcd_String("deg  ");
							
							///debugg///	
							UART0_Write_Text("FAN OFF");							
							///debugg///
							
							}
							else
							{
							IO0CLR |= 1<<2;
							dataFloat = (data*adcResolution)/0.01;
							sprintf(temp_data_str,"%f",dataFloat);
							Lcd_GotoXY(5,2);
							Lcd_String(temp_data_str);
							Lcd_GotoXY(13,2);
							Lcd_String("deg");
							
							///debugg///	
							UART0_Write_Text("FAN ON");						
							///debugg///
								
							}
							
							UART0_Write(10);
							UART0_Write(13);
							//delay_ms(10);
							
							
							/******************* for ldr *******************/

							data = ADC1_Read(4); //P0.13
							sprintf(ldr_data_str,"%d",data);
							Lcd_GotoXY(0,1);
							Lcd_String("Light:");
							///debug///
							UART0_Write_Text(" Ldr Data:");
							UART0_Write_Text(ldr_data_str);
							///debug///

							if(data <= ldr_threshold)
							{
							IO0CLR |= 1<<3;
							dataFloat = (data*adcResolution);
							RLDR = (2.1*dataFloat)/(3.3-dataFloat);
							LUX=500/RLDR;
							sprintf(ldr_data_str,"%f",LUX);
							Lcd_GotoXY(6,1);
							Lcd_String(ldr_data_str);
							Lcd_GotoXY(14,1);
							Lcd_String("lx");
							
							
							///debugg///	
							UART0_Write_Text("LIGHT OFF");							
							///debugg///
							
							}
							else
							{
							IO0SET |= 1<<3;
							dataFloat = (data*adcResolution);
							RLDR = (2.1*dataFloat)/(3.3-dataFloat);
							LUX=500/RLDR;
							sprintf(ldr_data_str,"%f",LUX);
							Lcd_GotoXY(6,1);
							Lcd_String(ldr_data_str);
							Lcd_GotoXY(14,1);
							Lcd_String("lx");
						
							///debugg///	
							UART0_Write_Text("LIGHT ON");						
							///debugg///
							}
							UART0_Write(10);
							UART0_Write(13);
							//delay_ms(10);
				}			
		}
}
