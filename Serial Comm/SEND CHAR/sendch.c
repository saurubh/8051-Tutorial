#include<reg51.h>
void sertx(unsigned char);
void main()
{
	 TMOD = 0x20;
	 TH1 = 0xFD;
	 SCON = 0x50;
	TR1 = 1;
	while(1)
	{
		sertx('y');
		sertx('e');
		sertx('s');
	}
}
void sertx(unsigned char x)
{
	 SBUF = x;
		while(TI==0);
		TI=0;
	}