#include < reg51.h >

sbit switch1=P1^0;
sbit switch2=P1^1;
sbit switch3=P1^2;
sbit switch4=P1^3;
sbit switch5=P1^4;
void delay(int);

int i,j,l;
int n=7;
int arr[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

void main()
{
P2=0x00;
P1=0xFF;

if(switch1==0)
{
for(l=0;l<8;l++)
{
P2=arr[l];
delay(100);
}
}

if(switch2==0)
{
P2=0x7E;
delay(100);
P2=0xBD;
delay(100);
P2=0xDB;
delay(100);
P2=0xE7;
delay(100);
}

if(switch3==0)
{
P2=0xE7;
delay(100);
P2=0xDB;
delay(100);
P2=0xBD;
delay(100);
P2=0x7E;
delay(100);
}

if(switch4==0)
{
P2=0xAA;
delay(50);
P2=0x55;
delay(50);
}

if(switch5==0)
{
P2=0x00;
delay(50);
P2=0xFF;
delay(50);
}
}
void delay(int itime) 
{
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}