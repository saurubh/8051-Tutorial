#include<reg51.h>
sbit sl1 = P1^0;
sbit sl2 = P1^1;
sbit sl3 = P1^2;
sbit sl4 = P1^3;
sbit sw1 = P1^5;
sbit sw2 = P1^6;
unsigned int digit1,digit2,digit3,digit4,num,test=0;
unsigned char digi_disp = 0;
unsigned char a[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
void delay(unsigned int itime)
{
	unsigned int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}

void display(int num)
{
	P2=0xff;
	sl1=sl2=sl3=sl4 = 0;
	digi_disp++;
	digi_disp = digi_disp%4;
	switch(digi_disp)
{
 
  case 0:
  P2= a[digit4];
  sl1 = 1;
	delay(1);
	sl1 = 0;
  break;

  case 1:
  P2= a[digit3];
  sl2 = 1;
	delay(1);
	sl2 = 0;
  break;

  case 2:
  P2= a[digit2];
  sl3 = 1;
	delay(1);
	sl3 = 0;
  break;
 
  case 3:
  P2= a[digit1];
  sl4 = 1;
	delay(1);
	sl4 = 0;
  break;
}
}

void main()
{
	while(1)
	{
	display(num);
		{
			if(sw1==0&&sw2==1)
			{
				test++;
       num=test;
        digit4=num%10;
      num=num/10;
        digit3=num%10;
      num=num/10;
        digit2=num%10;
      digit1=num/10;
      if(test==9999)
     test=0;
	}
		if(sw2==0&&sw1==1)
		{
			test--;
        num=test;
        digit4=num%10;
   num=num/10;
        digit3=num%10;
   num=num/10;
        digit2=num%10;
      digit1=num/10;
     if(test==0)
     test=9999;
		}
	}
}
}