#include<reg51.h>
sbit sw1 = P1^0;
sbit sw2 = P1^1;
sbit sw3 = P1^2;
sbit sw4 = P1^3;
sbit sw5 = P1^4;
sbit sw6 = P1^5;
sbit sw7 = P1^6;
sbit sw8 = P1^7;
void msdelay(unsigned int);
void main()
{
	  int z;
	unsigned char a[] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	while(1)
	{
 if(sw1==0)
 {
	 P2 = a[0];
	 msdelay(1);
 }
 if(sw2==0)
 {
	 P2 = a[1];
	 msdelay(1);
 }
 if(sw3==0)
 {
	 P2 = a[2];
	 msdelay(1);
 }
 if(sw4==0)
 {
	 P2 = a[3];
	 msdelay(1);
 }
 if(sw5==0)
 {
	 P2 = a[4];
	 msdelay(1);
 }
 if(sw6==0)
 {
	 P2 = a[5];
	 msdelay(1);
 }
 if(sw7==0)
 {
	 P2 = a[6];
	 msdelay(1);
 }
 if(sw8==0)
 {
	 P2 = a[7];
	 msdelay(1);
 }
 }
	}
void msdelay(unsigned int itime)
{
	unsigned int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}