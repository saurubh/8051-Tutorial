#include<reg51.h>
void msdelay(unsigned int);
void main()
{
	  int i;
	unsigned char digit[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	while(1)
	{
		for(i=9;i>=0;i--)
		{
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