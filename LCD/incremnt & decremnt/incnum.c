#include< reg51.h >

sfr lcddata=0x90; //LCD DATA PINS
sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^4;
sbit g=P2^6;
sbit h=P2^7;

int m=0;
int a,b;
unsigned char n[10]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};

void delay(unsigned char b)
{
unsigned char a;
for(b=0;b<245;b++)
{
for(a=0;a<1275;a++);
}
}

void command(unsigned char dost)
{
lcddata=dost;
en=1;
rs=0;
rw=0;
delay(5);
en=0;
}

void lcddisplaydata(unsigned char n)
{
lcddata=n;
en=1;
rs=1;
rw=0;
delay(50);
en=0;
}

void main()
{
P1=0xFF;
command(0x38);
command(0x0C);
while(1)
{
if(g==0)
{
if(m==99)
{
command(0x80);
lcddisplaydata(n[9]);
command(0x81);
lcddisplaydata(n[9]);
}
else
{
m=m+1;
a=m/10;
{
command(0x80);
lcddisplaydata(n[a]);
}
b=m%10;
{
command(0x81);
lcddisplaydata(n[b]);
}
while(g==0);
}
}

if(h==0)
{
if(m==0)
{
command(0x80);
lcddisplaydata(n[0]);
command(0x81);
lcddisplaydata(n[0]);
}
else
{
m=m-1;
a=m/10;
{
command(0x80);
lcddisplaydata(n[a]);
}
b=m%10;
{
command(0x81);
lcddisplaydata(n[b]);
}
while(h==0);
}
}
}
}