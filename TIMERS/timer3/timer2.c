#include<reg51.h>
void t0delay(void);
sbit led = P2^0;
void main()
{
	 unsigned int x;
	while(1)
	{
		led=~led;
		for(x=0;x<2000;x++)
		t0delay();
	}
}
void t0delay(void)
{
	TMOD = 0x01;
	TH0 = 0xFE;
	TL0 = 0xA5;
	TR0 = 1;
	while(TF0==0);
	TR0 = 0;
	TF0 = 0;
}