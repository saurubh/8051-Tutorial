#include<reg51.h>
void TOdelay(void);
sbit led = P2^0;
void main()
{
	unsigned int x;
	 while(1)
	 {
		 led=~led;
		 delay();
	 }
 }
void T0delay(void)
{
	TMOD = 0x01;
	TH0 = 0xfd;
	TL0 = 0x4b;
	TR0 = 1;
	while(TF0==0);
	TR0 = 0;
	TF0 = 0;
}