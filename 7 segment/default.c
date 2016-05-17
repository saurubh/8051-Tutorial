#include"REGx52.h"
#define seg_data P2
sbit seg1=P1^1;
sbit seg2=P1^2;
sbit seg3=P1^3;
int ones=0,tens=0,hundreds=0,l;
void display_digit(int );
void delay();

void main()
{
seg1=seg2=seg3=1;
while(l<=999)
{
ones=l%10;
tens=(l/10)%10;
hundreds=(l/100);
display_digit(ones);
seg1=0;
delay();
seg1=1;

display_digit(tens);
seg2=0;
delay();
seg2=1;

display_digit(hundreds);
seg3=0;
delay();
seg3=1;
l++;
}
}

void delay()
{
long int k;
for(k=0;k<1000;k++);
}
void display_digit(int c)
{
switch(c)
{
case 0:
seg_data=0xbf;
break;
case 1:
seg_data=0x06;
break;
case 2:
seg_data=0x5b;
break;
case 3:
seg_data=0x4f;
break;
case 4:
seg_data=0x66;
break;
case 5:
seg_data=0x6d;
break;
case 6:
seg_data=0x7d;
break;
case 7:
seg_data=0x07;
break;
case 8:
seg_data=0x7f;
break;
case 9:
seg_data=0x6f;
break;
}
}