#include<reg51.h>
void Tx_char(unsigned char);
void main()
{
	  TMOD = 0x20;
	  TH1 = 0xfd;
	  SCON = 0x50;
	  TR1 = 1;
	while(1)
		{
		    Tx_char('H');
			  Tx_char('E');
			Tx_char('L');
			Tx_char('L');
			Tx_char('O');
	}
}
void Tx_char(unsigned char x)
{
  SBUF = x;
while(TI==0);
TI=0;
}	