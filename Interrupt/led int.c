#include<reg51.h>
sbit led = P2^0;
void timer(void) interrupt 1
{
	unsigned char x;
	led=~led;
	for(x=0;x<40;x++)
{
	TH0 = 0xA5;              // initialize timer loader value
	TL0 = 0xFE;          
}
}
void main()
{
	TMOD = 0x01;
	TH0 = 0xA5;
	TL0 = 0xFE;
	IE = 0x82;
	TR0 = 1;
	while(1);
}
		