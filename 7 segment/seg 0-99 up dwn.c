#include<reg51.h>
sbit up=P1^0;
sbit down = P1^1;
void main()
{
	unsigned int i=0;
	int j=0;
	unsigned char arra1[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	unsigned char arra2[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	while(1)
	{
		start:
		if(up==0)
		{
			j++;
			if((i<=9)&&(j>9))
			{
				i++;
				j=0;
			}
			if(i>9)
			{
				i=9;
				j=9;
			}
			P3 = arra1[i];
			P2 = arra1[j];
			while(up==0);
		}
		if(down==0)
		{
			if((i==0)&&(j==0))
			{
				goto start;
				j--;
				if((i>=0)&&(j<0))
				{
					j=9;
					i--;
				}
				if((i<0)&&(j<0))
				{
					j=0;
					i=0;
				}
				P3 = arra1[i];
				P2 = arra1[j];
				while(down==0);
			}
		}
	}
}
				