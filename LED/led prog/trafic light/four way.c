#include<reg51.h>
sbit ledrn = P2^0;
sbit ledyn = P2^1;
sbit ledgn = P2^2;
sbit ledrs = P2^3;
sbit ledys = P2^4;
sbit ledgs = P2^5;
sbit ledre = P1^0;
sbit ledye = P1^1;
sbit ledge = P1^2;
sbit ledrw = P1^3;
sbit ledyw = P1^4;
sbit ledgw = P1^5;
sbit sl1 = P2^6;
sbit sl2 = P2^7;
void route();
void msdelay(unsigned int);
void main()
{
	int k,t;
	unsigned char digit[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	for(k=9;k>0;k--)
		{
			for(t=0;t<25;t++)
			{
	  while(1)
		{
			P3 = digit[k];
			msdelay(t);
			ledgn = ledgs = ledre = ledrw = 1;
			ledyn=ledys=ledye=ledyw = 0;
			ledge=ledgw=ledrn=ledrs = 0;
			msdelay(5000);
			ledye=ledyw = 1;
			ledyn=ledys = 0;
			ledgn=ledgs = 1;
			ledrn=ledrw = 0;
			ledre=ledrw = 0;
			ledge=ledgw = 0;
			msdelay(1500);
			ledge=ledgw = 1;
			ledrn = ledrs = 1;
			ledgn = ledgs  = 0;
			ledyn=ledys=ledye=ledyw = 0;
			msdelay(5000);
			ledye=ledyw = 0;
			ledyn=ledys = 1;
			ledgn=ledgs = 0;
			ledrn=ledrs = 0;
			ledre=ledrw = 0;
			ledge=ledgw = 1;
			msdelay(1500);
			
		}
	}
}
	}
		 void msdelay(unsigned int itime)
		 {
			  unsigned int i,j;
			 for(i=0;i<itime;i++)
			 for(j=0;j<1275;j++);
		 }