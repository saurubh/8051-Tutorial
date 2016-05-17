#include<reg51.h>
void t1m1delay(void);
sbit led = P2^0;
void main()
{
	 unsigned int z;
	while(1)
	{
		 led=~led;
		for(z=0;z<=40;z++)
		t1m1delay();
	}
}
void t1m1delay(void)
{
	TMOD = 0x10;
	TL1 = 0x00;
	TH1 = 0xD3;
	TR1 = 1;
	while(TF1==0);
	TR1 = 0;
	TF1 = 0;
}