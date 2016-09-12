void delay_us(int a)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=0;j<1000;j++);
}

void delay_ms(int a)
{
	int i,j,k;
	for(i=0;i<a;i++)
		for(j=0;j<1000;j++)
			for(k=0;k<1000;k++);
}
