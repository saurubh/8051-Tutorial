#include<reg51.h>
void msdelay(unsigned int);
void main()
{
	unsigned int i;
	while(1)
	{
		for(i=0x01;i<=0x80;i<<=1)
		P2 =~i;
		msdelay(50);


		}
	}
     void msdelay(unsigned int itime)
		 {
			  unsigned int k,j;
			 for(k=0;k<itime;k++)
			 for(j=0;j<1275;j++);
		 }