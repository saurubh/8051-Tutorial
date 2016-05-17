#include<reg51.h>
sbit mybit = P2^0;
void T0delay(void);
void main()
{
	  unsigned char x;
	while(1)
	{
		 mybit = 1;
		for(x=0;x<40;x++)
		{
			T0delay();
		}
	mybit = 0;
		for(x=0;x<40;x++)
		{
			T0delay();
		}
	}
}
 void T0delay(void)
 {
	 TMOD = 0x01;
	 TL0 = 0xFE;
	 TH0 = 0xA5;
	 TR0 = 1;
	 while(TF0==0);
	 TR0 = 0;
	 TF0 = 0;
 }