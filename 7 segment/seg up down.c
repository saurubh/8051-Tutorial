#include<reg51.h>
sbit  up = P1^0;
sbit down = P1^1;
void main()
{
	 
	int i=0;
	int j=0;
	unsigned char arra1[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	unsigned char arra2[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	while(1)
	{
		if(up==0)
		{
			i++;
			if(i>9)
			{
				i=0;
			}
			P2 = arra1[i];
			while(up==0);
			 }
		if(down==0)
		{
			j--;
			if(j>9)
			{
				j=i;
			}
			P2 = arra2[j];
			while(down==0);
		 }
	 }
 }
