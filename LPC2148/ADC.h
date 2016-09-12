void ADC0_Init(void)
{
	//AD0CR |= 1<<21;								//A/D is Operational
	//AD0CR |= 0<<21;								//A/D is in Power Down Mode
	//PCONP = (PCONP &0x001817BE) | (1UL<<12);
	PINSEL1 |= 0x150000;					//P0.28,P0.29,P0.30 is Configured as Analog to Digital Converter Pin AD0.1,0.2,0.3
	AD0CR |= 0x00200E00;						//CLKDIV=14,Channel-0.0 Selected,A/D is Operational
	A/D Clock = PCLK /(CLKDIV+1);
	
}

unsigned int ADC0_Read(int channel)
{
	unsigned int adc_data;
	//int GDRreg;
	AD0CR &= ~(0x000000FF);
	AD0CR |= 1UL<<channel;
	AD0CR |= 1UL<<24;	
	while(!(AD0GDR & 0x80000000));						//Start Conversion
	//Wait untill the DONE bits Sets
	AD0CR &= ~(0x01000000);					//Stops the A/D Conversion 
	AD0GDR &= ~(0x40000000);
	switch(channel)
	{
		case 1: 	AD0DR1 &= ~(0x40000000);
							adc_data = AD0DR1 >> 6;
							break;
		case 2: 	AD0DR2 &= ~(0x40000000);
							adc_data = AD0DR2 >> 6;
		
	}
	
	adc_data = adc_data & 0x3FF;    //Clearing all other Bits
	return (adc_data);
}
