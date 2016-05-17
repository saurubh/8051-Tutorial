#include<reg51.h>
void msdelay(unsigned int);
void main()
{
     unsigned int i;
	  for(i=0;i<=255;i++)
	  {
	     P2 = i;
			msdelay(100);
		 }
	 } 
void msdelay(unsigned int itime)
{
	unsigned int j,k;
	for(j=0;j<itime;j++)
	for(k=0;k<1275;k++);
}