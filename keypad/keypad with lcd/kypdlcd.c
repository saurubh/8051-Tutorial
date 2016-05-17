#include<reg51.h>
#define port P3
#define dataport P2  // Dataport for lcd
#define key P1  // Port for keypad
#define sec 100
sbit rs = port^1;
sbit rw = port^2;
sbit en = port^3;

sbit col1=key^4;
sbit col2=key^5;
sbit col3=key^6;
sbit row1=key^0;
sbit row2=key^1;
sbit row3=key^2;
sbit row4=key^3;

void delay(unsigned int msec) //Time delay function
{
int i,j ;
for(i=0;i<msec;i++)
  for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char item) //Function to send command to LCD
{
dataport = item;
rs= 0;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data(unsigned char item) //Funtion to send data on LCD
{
dataport = item;
rs= 1;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data_string(unsigned char *str) // Function to send string on LCD
{
int i=0;
while(str[i]!='\0')
{
  lcd_data(str[i]);
  i++;
  delay(10);
}
return;
}

void lcd(unsigned char str[10])  // Funtion to Initialize LCD
{
lcd_cmd(0x38);
lcd_cmd(0x0e);
//delay(sec);
lcd_cmd(0x01);
//delay(sec);
lcd_cmd(0x82);
//delay(sec);
lcd_data_string(str);
}

void display(int a) //Display functon for LCD

{
switch(a)
{
  case 1:
		lcd("one 1");
    break;
  case 2:
		lcd("two 2");
    break;
  case 3:
		lcd("three 3");
    break;
  case 4:lcd("four 4");
    break;
  case 5:
		lcd("five 5");
    break;
  case 6:
		lcd("six 6");
    break;
  case 7:
		lcd("seven 7");
    break;
  case 8:
		lcd("EIGHT 8");
    break;
  case 9:
		lcd("NINE 9");
    break;
  case 0:
		lcd("ZERO 0");
    break;
  case 11:lcd("*");
    break;
  case 12:
		lcd("#");
    break;
}
}

void check_col1() //Function for checking column one
{
row1=row2=row3=row4=1;
row1=0;
if(col1==0)
display(1);
row1=1;
row2=0;
if(col1==0)
display(4);
row2=1;
row3=0;
if(col1==0)
display(7);
row3=1;
row4=0;
if(col1==0)
display(11); 
row4=1;
}

void check_col2() //Function for checking column two
{
row1=row2=row3=row4=1;
row1=0;
if(col2==0)
display(2);
row1=1;
row2=0;
if(col2==0)
display(5);
row2=1;
row3=0;
if(col2==0)
display(8);
row3=1;
row4=0;
if(col2==0)
display(0);
row4=1;
}

void check_col3() //Function for checking column three
{
row1=row2=row3=row4=1;
row1=0;
if(col3==0)
display(3);
row1=1;
row2=0;
if(col3==0)
display(6);
row2=1;
row3=0;
if(col3==0)
display(9);
row3=1;
row4=0;
if(col3==0)
display(12);  //For #
row4=1;
}

void main()
{
col1=col2=col3=1;  //Input Port
while(1)
{
  row1=row2=row3=row4=0;
  if(col1==0)
  check_col1();
  else
   if(col2==0)
   check_col2();
   else
    if(col3==0)
    check_col3();
}
}