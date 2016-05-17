#include<reg51.h>
sbit sel1 = P3^2;
sbit sel2 = P3^3;
sbit sw1 = P3^6;
sbit sw2 = P3^7;

unsigned char a[]= {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
void delay(unsigned int itime)
{
unsigned int j,k;
for(j=0;j<itime;j++)
for(k=0;k<1275;k++);
}
void display(int i)
{
P2 = a[i/10];
sel1 = 1;
delay(1);
sel1 = 0;

P2 = a[i%10];
sel2 = 1;
delay(1);
sel2 = 0;
}

void main()
{
int i=0;

while(1)
{
display(i);

if(sw1 == 0)
{
i++;
while(sw1==0)
display(i);
}
if(sw2 == 0)
{
i--;
while(sw2==0)
display(i); 
}

} 
}