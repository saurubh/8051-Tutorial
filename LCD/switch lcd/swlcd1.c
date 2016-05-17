#include<reg51.h>
sfr ldata=0x90;
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2;
void Tdelay(unsigned int );
void lcdcmd(unsigned char );
void lcd_data(unsigned char );
void lcd_init(void);
void lcd_display(unsigned char *c );
int main( )
{
while(1){
lcd_init( );
if (sw1==0)
lcd_display("Embedded Systems");
if (sw2==0)
lcd_display("Electronics");
if(sw3==0)
lcd_display("Embedded programming");
}
}
void Tdelay(unsigned int ms)
{
unsigned int i,j;
for(i=0;i<ms;i++)
for(j=0;j<1275;j++);
}
void lcd_init( void)
{
lcdcmd(0x38);
Tdelay(25);
lcdcmd(0x0F);      //display on , cursor blinking
Tdelay(25);
lcdcmd(0x06);       //  cursor increment
Tdelay(25);
lcdcmd(0x80);        // start at row-1
Tdelay(25);
lcdcmd(0x01);        // clear screen
Tdelay(10);
}
void lcdcmd(unsigned char cvalue )   // lcd in command mode
{
ldata=cvalue;
rs=0;
rw=0;
en=1;
Tdelay(1);
en=0;
}
void lcd_display(unsigned char *dvalue)
{
unsigned int x;
for(x=0;dvalue[x]!=0;x++)
{
lcd_data(dvalue[x]);
Tdelay(10);
}
}
void lcd_data(unsigned char dvalue)       // lcd in data mode
{
ldata=dvalue;
rs=1;
rw=0;
en=1;
Tdelay(1);
en=0;
}