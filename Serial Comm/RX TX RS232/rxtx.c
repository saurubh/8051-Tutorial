#include<reg51.h>
void initialize()           // initialize for timer
{
	TMOD = 0x20;
	TH1 =  0xFD;
	SCON = 0x50;
	TR1=1;
}
void receiver()
{
	  unsigned char value;
	while(RI==0);
	value = SBUF;
	P1 = value;
	RI=0;
}
void transmit()
{
	SBUF = 'V';
	while(TI==0);
	TI=0;
	SBUF = 'K';
	while(TI==0);
	TI=0;
}

void main()
{
	while(1)
	{
		initialize();
		receive();
		transmit();
	}
}
