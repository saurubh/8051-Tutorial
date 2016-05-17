#include<reg51.h>
sfr ldata =0xA0;  // data port P2
sbit rs=P3^0; // Register select pin
sbit rw=P3^1; // Read write pin
sbit en=P3^2; // Enable pin
void delay(unsigned int msec)    //delay function
{
int i,j;
for(i=0;i<msec;i++)
for(j=0;j<1275;j++);
}
void lcd_command(unsigned char cvalue)    // function to send command to LCD
{
ldata=cvalue;
en=1;
rs=0;
rw=0;
delay(1);
en=0;
}
void lcd_data(unsigned char dvalue)    // function to send data on LCD
{
ldata=dvalue;
en=1;
rs=1;
rw=0;
delay(1);
en=0;
}

lcd_display(unsigned char *dvalue)    // function to send string to LCD
{
int x;
for(x=0;dvalue[x]!=0;x++)
{
lcd_data(dvalue[x]);

}
}

void lcd_init()     //Function to inisialize the LCD
{
lcd_command(0x38);   
delay(1);
lcd_command(0x0c);       
delay(1);
lcd_command(0x83);
delay(1);
lcd_command(0x06);	
delay(1);	
}
void main()
{
lcd_init();
lcd_command(0x01);	
lcd_display("***WELCOME***");
delay(100);
lcd_command(0x01);	
lcd_command(0x82);
lcd_display("**HAPPY**");
lcd_command(0xc2);
lcd_display("*BIRTH DAY");	
delay(100);
}