#include<reg51.h>
sfr ldata=0x90;
sbit rs=P2^0;   // LCD reset
sbit rw=P2^1;  // read/write control
sbit en=P2^2;  // LCD r/w enable
void Tdelay(unsigned int );     // functions initializaion
void lcdcmd(unsigned char );
void lcd_data(unsigned char );
void lcd_init(void);
void lcd_display(unsigned char *c );
int main( )
{
while(1){
lcd_init( );
 lcd_display("Embedded Systems");
}
}
void Tdelay(unsigned int ms)  // providing some delay
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
lcdcmd(0x80);      // start at row-1
Tdelay(25);
lcdcmd(0x01);      // clear screen
Tdelay(10);
}
void lcdcmd(unsigned char cvalue ) // LCD in command mode opearaion
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
void lcd_data(unsigned char dvalue) // LCD in data mode operation
{
ldata=dvalue;
rs=1;
rw=0;
en=1;
Tdelay(1);
en=0;
}  