#include<reg51.h>
sbit sl1 = P1^0;
sbit sl2 = P1^2;
unsigned char a[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
unsigned int i,z,j,k;
void display();
void init_timer();
void main()
	{
		display();
	}
void display()
{
	for(i=0;i<=9;i++)
	{
		sl1 = 1;
  P2 = a[i];
  init_timer();
		sl1 = 0;
	}
	for(z=0;z<=9;z++)
	{
		sl2 = 1;
		P2 = a[z];
		init_timer();
		sl2 = 0;
	}
}
void init_timer()
{
	TMOD=0x01;
	TL0=0xfd;
	TH0=0x4b;
	for(j=0;j<200;j++)
	for(k=0;k<500;k++);
	TR0 = 1;
  while(TF0==0);
	TF0=0;
}