void ADC1_Init(void)
{
	PINSEL0 |= 0xCF333005;					
	AD1CR |= 0x00200300;					
}


unsigned int ADC1_Read(int channel)
{
	unsigned int adc_data;
	AD1CR &= ~(0x000000FF);
	AD1CR |= 1UL<<channel;
	AD1CR |= 1UL<<24;				 
	while(!(AD1GDR & 0x80000000));	
	AD1CR &= ~(0x01000000);			 		
	AD1GDR &= ~(0x40000000);
	adc_data = AD1GDR >> 8;
	adc_data = adc_data & 0xFF;    	 
	return (adc_data);
}


