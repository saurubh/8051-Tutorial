#include<reg51.h>
sbit sl1 = P1^0;
void msdelay(unsigned int);
void main()
{
	  int i;
	unsigned char digit[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	while(1)
	{
		for(i=0;i<10;i++)
		{
			sl1 = 1;
			P2 = digit[i];
			msdelay(100);
		}
	}
}
void msdelay(unsigned int itime)
{
	 unsigned int j,k;
	for(j=0;j<itime;j++)
	for(k=0;k<1275;k++);
}