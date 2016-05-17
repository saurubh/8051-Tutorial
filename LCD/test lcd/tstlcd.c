#include<reg51.h>
sfr lcd_data_pin=0xA0;  // data port P2
sbit rs=P3^0; // Register select pin
sbit rw=P3^1; // Read write pin
sbit en=P3^2; // Enable pin
sbit led1 = P1^0;
sbit led2 = P1^1;
sbit sw1 = P3^6;
sbit sw2 = P3^7;
void delay(unsigned int msec)    //delay function
{
int i,j;
for(i=0;i<msec;i++)
for(j=0;j<1275;j++);
}
void lcd_command(unsigned char comm) // function to send command to LCD
{
lcd_data_pin=comm;
en=1;
rs=0;
rw=0;
delay(1);
en=0;
}
void lcd_data(unsigned char disp)    // function to send data on LCD
{
lcd_data_pin=disp;
en=1;
rs=1;
rw=0;
delay(1);
en=0;
}

lcd_dataa(unsigned char *disp)    // function to send string to LCD
{
int x;
for(x=0;disp[x]!=0;x++)
{
lcd_data(disp[x]);

}
}

void lcd_ini()     //Function to inisialize the LCD
{
lcd_command(0x38);   
delay(5);
lcd_command(0x0c);       
delay(5);
lcd_command(0x80);
delay(5);
lcd_command(0x06);
delay(5);		  

}
void main()
{
	while(1)
	{
		led1=0;
		led2=0;
lcd_ini();
lcd_command(0x01);
while(sw1==1&&sw2==1);
	if(sw1==0&&sw2==1)
	{
		led1=1;
		led2=0;
lcd_dataa("LED 1 IS GLOW");
lcd_command(0xc0);
lcd_dataa(" LED 2 IS OFF");	
while(sw1==0);
	}
	else
		led1=led2=0;
lcd_command(0x01);
	
	
	if(sw2==0&&sw1==1)
	{
		led1=0;
		led2=1;
lcd_command(0x01);
lcd_command(0x82);	
lcd_dataa("LED 2 IS GLOW");
lcd_command(0xc2);
lcd_dataa("LED 1 IS OFF");
while(sw2==0);
	}
		else
			led1=led2=0;
lcd_dataa(0x01);
	
}
	}