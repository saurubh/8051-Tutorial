#include<reg51.h>
void main()
{
	
		TMOD = 0x20;        
	TH1 = 0xFA;
	SCON = 0x50;
	 TR1 = 1;
	while(1)
	{
	
		SBUF = 'Y';
		while(TI==0);
		TI=0;
		
	}
}
  
	