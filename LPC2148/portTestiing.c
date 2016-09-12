#include <lpc214x.h>

void main()
{
	PINSEL0 =0;
	PINSEL1 =0;
	PINSEL2 =0;
	IO0SET=0xFFFFFFFF;
	IO1SET=0xFFFFFFFF;

}