#include <stdio.h>

int str2int(unsigned char *str)
{
	int res = 0,i; // Initialize result

	// Iterate through all characters of input string and
	// update result
	for (i = 0; str[i] != '\0'; ++i)
		res = res*10 + str[i] - '0';

	// return result.
	return res;
}


void strSplit(unsigned char * data, unsigned char * node, unsigned char * field, unsigned char * val)
{
	int j=0,k;
	for(;data[j] != '$';j++);
	if(data[j]=='$')
	{
		for(++j; data[j] != '*'; ++j);
		for(k=0,++j; data[j] != '*'; ++j,++k)
		{
				node[k]=data[j];
		}
		node[k] = '\0';
		for(k=0,++j; data[j] != '*'; ++j,++k)
		{
				field[k]=data[j];
		}
		field[k] = '\0';
		for(k=0,++j; data[j] != '*'; ++j,++k)
		{
				val[k]=data[j];
		}
		val[k] = '\0';
	}
}	

void strSplit1(unsigned char * data, unsigned char * node, unsigned char * field, unsigned char * val)
{
	if(data[0] == '$')
	{
		node[0]=data[2];
		node[1]=0;
		field[0]=data[4];
		field[1]=0;
		val[0]=data[6];
		val[1]=data[7];
		val[2]=data[8];
		val[3]=data[9];
		val[4]=0;		
	}
}

void StringSplitRead(unsigned char * node, unsigned char * field, unsigned char * val)
{
	unsigned char p;
	int g=0;
	int i;
	while(g==0)
	{
		p=UART0_Read();
		while(p!='$')
        {
            p=UART0_Read();
        }
		p=UART0_Read();
		if(p=='D');
        else
            continue;
        p=UART0_Read();
        if(p=='A');
        else
            continue;
        p=UART0_Read();
        if(p=='T');
        else
        continue;
            p=UART0_Read();
        if(p=='A');
        else
            continue;
            p=UART0_Read();
        if(p==':')
        {
            while(p!='*')
            {
                p=UART0_Read();
            }
            p=UART0_Read();
            while(p!='*')
            {
                p=UART0_Read();

            }
            for(i=0;i<1;i++)
            {
                node[i]=UART0_Read();
            }
            p=UART0_Read();
            while(p!='*')
            {
                p=UART0_Read();
            }
			for(i=0;i<1;i++)
            {
                field[i]=UART0_Read();
            }
            p=UART0_Read();
            while(p!='*')
            {
                p=UART0_Read();
            }
            for(i=0;i<4;i++)
            {
                val[i]=UART0_Read();
            }
            node[1]='\0';
            field[1]='\0';
            val[4]='\0';
            g=1;
        }
        else
            continue;
	}
}