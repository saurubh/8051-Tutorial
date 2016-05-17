#include<reg51.h>
void main()
{
	 unsigned char mynum[] = {+1,-1,+2,-2,+3,-3,+4,-4};
	 unsigned char z;
	 for(z=0;z<=8;z++)
	 {
		 while(1)
		 {
			 P2 = mynum[z];
		 }
	 }
 }