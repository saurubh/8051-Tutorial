#include<reg51.h>
sbit sw = P2^0;
void main()
{
	unsigned char z;
	unsigned char fname[] = "ALI";
	unsigned char lname[] = "SMITH";
TMOD = 0X20;
TH1 = 0xfd;
SCON = 0x50;
TR1 = 1;
if(sw==0)
{
  for(z=0;z<3;z++)
{
 SBUF = fname[z];
while(TI==0);
TI=0;
}
}
else
{
	for(z=0;z<5;z++)
	{
		SBUF = lname[z];
		while(TI==0);
		TI=0;
	}
}
}