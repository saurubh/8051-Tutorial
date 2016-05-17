#include<reg51.h>
sbit sl1 = P1^0;
sbit sl2 = P1^1;
void msdelay(unsigned int);
void main()
{
	  
	unsigned char digit[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	while(1)
	{
int k,m,t;

for(k=9;k>=0;k--)   
{
for(m=9;m>=0;m--)
	{
for(t=0;t<25;t++)
{
sl1=1;
P2=digit[k];	
msdelay(1);
sl1 = 0;
}
sl2=1;
P2=digit[m];
msdelay(1);
sl2=0;
	}
}
}
	}



void msdelay(unsigned int itime)
{
	 unsigned int j,k;
	for(j=0;j<itime;j++)
	for(k=0;k<1275;k++);
}