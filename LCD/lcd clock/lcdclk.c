#include<reg51.h>
#define cont_port P3
#define port P1  
#define dataport P2  // Data port for LCD
#define m_sec 10
sbit rs = cont_port^0;
sbit rw = cont_port^1;
sbit en = cont_port^2;
sbit dig_hr1=port^0;
sbit dig_min1=port^1;
sbit start=port^2;
sbit am_pm=port^3;
int hr ,hr1=0;
int min,min1=0;
int sec,sec1=0,dig_am_pm=0;

void delay(unsigned int msec)   // Time delay funtion
{
int i,j ;
for(i=0;i<msec;i++)
  for(j=0;j<1275;j++);
}

                
void lcd_cmd(unsigned char item)   // Function to send command on LCD
{
dataport = item;
rs= 0;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data(unsigned char item)  // Function to send data on LCD
{
dataport = item;
rs= 1;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data_string(unsigned char *str)  // Function to send string on LCD
{
  int i=0;
  while(str[i]!='\0')
{
    lcd_data(str[i]);
    i++;
    delay(1);
}
return;
}

lcd_data_int(int time_val)   // Function to send number on LCD
{
int int_amt;
int_amt=time_val/10;
lcd_data(int_amt+48);
int_amt=time_val%10; 
lcd_data(int_amt+48);
}

void lcd(unsigned char str1[10])  // Function to initialize LCD
{
lcd_cmd(0x38);  //2 LINE, 5X7 MATRIX
lcd_cmd(0x0e);  //DISPLAY ON, CURSOR BLINKING
delay(m_sec);
lcd_data_string(str1);
}

void set_hr1()  // Function to set hour
{
hr1++;
if(hr1>11)
hr1=0;
lcd_cmd(0xc3);
lcd_data_int(hr1);
lcd_data(':');
}

void set_min1()  // Function to set minute
{
min1++;
if(min1>59)
min1=0;
lcd_cmd(0xc6);
lcd_data_int(min1);
}

void main()
{
int k;
start=1;
dig_hr1=1;
dig_min1=1;
lcd_cmd(0x01);
lcd_cmd(0x83);
lcd("SET TIMING");
lcd_cmd(0xc3);
lcd_data_int(hr1);
lcd_data(':');
lcd_data_int(min1);
while(start==0)
{
  delay(10);
  if(dig_hr1==0)
  set_hr1();
  if(dig_min1==0)
  set_min1(); 
}

if(am_pm==0)
{
  lcd_cmd(0xc8);
  lcd_data_string("am");
  dig_am_pm=0;
}

if(am_pm==1)
{
  lcd_cmd(0xc8);
  lcd_data_string("pm");
  dig_am_pm=1;
}
delay(200);
lcd_cmd(0x01);
while(1)
{
  for(k=0;k<2;k++)
  {
   for(hr=hr1;hr<12;hr++)
   {
    for(min=min1;min<60;min++)
     {
      for(sec=0;sec<60;sec++)
      {
       lcd_cmd(0x82);
       delay(1);
       lcd_data_int(hr);
       lcd_data(':');
       lcd_data_int(min);
       lcd_data(':');
       lcd_data_int(sec);
       if(dig_am_pm==0)
       {
        lcd("am");
       }
       else
       {
        lcd("pm");
       }
       lcd_data_string("    ");
       delay(100);
      }
     }
    min1=0;
    }
  if(dig_am_pm==0)
  dig_am_pm=1;
  else
  dig_am_pm=0;
  hr1=0;
  }
}
}
