#include<reg51.h>
void msdelay(unsigned int);
void main()
{
   while(1)
   {
      
       P2 = 0x55;
		 msdelay(100);
		   P2 = 0xAA;
		 msdelay(100);
	  }
}	 
   void msdelay(unsigned int itime)
	 {
		 unsigned int i,j;
		 for(i=0;i<itime;i++)
		 for(j=0;j<1275;j++);
	 }
	   