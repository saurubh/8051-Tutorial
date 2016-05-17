#include<reg51.h>
void msdelay(unsigned int);
void main()
{
	int i;
	int digit[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	int digit1[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	P2 = 0x00;
	while(1)
		{
			for(i=0;i<8;i++)
		{
				P2 = digit[i];
				msdelay(50);
		}
		for(i=0;i<7;i++)
		{
			  P2 = digit1[i];
			  msdelay(50);
		}
		for(i=1;i<6;i++)
		{
				P2 = digit[i];
				msdelay(50);
			 }	
	for(i=1;i<6;i++)
		{
			  P2 = digit1[i];
			  msdelay(50);
		}	
		for(i=2;i<4;i++)
		{
				P2 = digit[i];
				msdelay(50);
			 }		
	for(i=2;i<3;i++)
		{
			  P2 = digit1[i];
			  msdelay(50);
		}	
		for(i=3;i<4;i++)
		{
				P2 = digit[i];
				msdelay(50);
			 }
	for(i=3;i<2;i++)
		{
			  P2 = digit1[i];
			  msdelay(50);
		}	
    for(i=4;i<6;i++)
		{
				P2 = digit[i];
				msdelay(100);
			 }		
		
		}
	}      
void msdelay(unsigned int itime)
			{
				unsigned int i,j;
			for(i=0;i<itime;i++)
			for(j=0;j<1275;j++);
		}
		
	