#include<reg51.h>
#define dataport P2
#define sec 100
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

sbit col1=P1^4;
sbit col2=P1^5;
sbit col3=P1^6;
sbit row1=P1^0;
sbit row2=P1^1;
sbit row3=P1^2;
sbit row4=P1^3;
sbit lock_output=P1^7;

int check=0;
int digit[4]={0,0,0,0};
int dig_one = 9;
int dig_two = 6;
int dig_three = 1;
int dig_four = 2;
int i,count=0;

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

void lcd_data(unsigned char item) // Function to send data to LCD
{
dataport = item;
rs= 1;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data_string(unsigned char *str)  // Function to send string to LCD
{
int i=0;
while(str[i]!='\0')
{
  lcd_data(str[i]);
  i++;
  //delay(10);
}
return;
}

void lcd(unsigned char str[10])  // Function to send string to LCD
{
lcd_cmd(0x38);
lcd_cmd(0x0e);
lcd_cmd(0x06);	
lcd_data_string(str);
}

void ans()
{
if(check>3)
{
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd("Please wait...");
	lcd_cmd(0xc0);
	lcd("while check password");
		delay(200);
  lcd_cmd(0x01);
  lcd_cmd(0x82);
  lcd_data_string(" name - viru");
	lcd_cmd(0xc3);
	lcd("TISHITU");
  lock_output=1;
  delay(500);
}
else
{
		lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd("Please wait...");
	lcd_cmd(0xc0);
	lcd("while check password");
		delay(200);
  lcd_cmd(0x01);
  lcd_cmd(0x82);
  lcd_data_string(" WRONG PASSWORD");
  lock_output=0;
  count++;
  delay(500);
}                   
}

void code_check() // Function to check password
{
if(i<=3 )
{
  switch((i+1))
  {
   case 1: {
      if(dig_one==digit[0])
      {
       check=check+1;
      }
      break;
     }

   case 2: {
      if(dig_two==digit[1])
      {
       check=check+1;
      }
      break;
     }
    
   case 3: {
      if(dig_three==digit[2])
      {
       check=check+1;
      }
      break;
      }
    
   case 4: {
      if(dig_four==digit[3])
      {
       check=check+1;
      }
      break;
     }
  }
}
if(i==3)
{
  ans();
}
}


void display(int a) //Display function
{
switch(a)
{ 
  case 1:{
    lcd_data('*');
    delay(30);
    digit[i]=1;
    code_check();
    break;
    }
  case 2:{
    lcd_data('*');
    delay(30);
    digit[i]=2;
    code_check(); 
    break;
    }
  case 3:{
    lcd_data('*');
    delay(30);
    digit[i]=3;
    code_check();
    break; 
    }
  case 4:{
    lcd_data('*');
    delay(30);
    digit[i]=4;
    code_check();
    break;
    }
  case 5:{
    lcd_data('*');
    delay(30);
    digit[i]=5;
    code_check();
    break;
    }
  case 6:{
    lcd_data('*');
    delay(30);
    digit[i]=6;
    code_check();
    break;
    }
  case 7:{
    lcd_data('*');
    delay(30);
    digit[i]=7;
    code_check();
    break;
    }
  case 8:{
    lcd_data('*');
    delay(30);
    digit[i]=8;
    code_check();
    break;
    }
  case 9:{
    lcd_data('*');
    delay(30);
    digit[i]=9;
    code_check();
    break;
    }
  case 0:{
    lcd_data('*');
    delay(30);
    digit[i]=0;
    code_check();
    break;
    }
}
}

void check_col1()
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
{
  row4=1;
}
}

void check_col2()
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

void check_col3()
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
 row4=1;
}

void main()
{
	lock_output = 0;
col1=col2=col3=1;
while(1)
{
	lcd_cmd(0x01);
	lcd_cmd(0x83);
	lcd("WELCOME");
	lcd_cmd(0xc3);
	lcd("TO KEY LOCK");
  delay(200);
  lcd_cmd(0x01);              //Clear LCD screen
  lock_output=0;
  lcd_cmd(0x82);             // Set cursor on position first of first line
  lcd("ENTER PIN CODE"); 
  check=0;
  row1=row2=row3=row4=0;
  while(col1==1 && col2==1 && col3==1);
  for(i=0;i<4;i++)
  {
   delay(10);
   lcd_cmd(0xc4+i);
   row1=row2=row3=row4=0;
   while(col1==1 && col2==1 && col3==1);
   row1=row2=row3=row4=0;
   if(col1==0)
   check_col1();
   else
    if(col2==0)
    check_col2();
    else
     if(col3==0)
     check_col3();
   if(count==4)
   {
   lcd_cmd(0x01);
   lcd_cmd(0x86);
   lcd("SORRY");
   lcd_cmd(0xc1);
   lcd("NO MORE TRIALS");
   while(1);
   }
  }   
}
}