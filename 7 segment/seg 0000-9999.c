#include<reg51.h>
 sbit dig_ctrl_4=P1^0; // Control pins for the seven segments
 sbit dig_ctrl_3=P1^1;
 sbit dig_ctrl_2=P1^2;
 sbit dig_ctrl_1=P1^3;
 sbit dig_ctrl_5=P1^6;
 sbit dig_ctrl_6=P1^7;
 unsigned char dig_disp=0;
 int hrs2;
 int hrs1;	 
 int min2;
 int min1;
 int sec2;
 int sec1;
 char digi_val[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};

void delay()        // Function to provide time delay using Timer 1.
    {
    int i;
    for(i=0;i<20;i++)
    {
        TL1=0xFD;
         TH1=0x4B;
         TR1=1;
         while(TF1==0);
         TR1=0;
         TF1=0;
    }
}
   

void display() interrupt 1        // Function to display the four digit number using multiplexing on seven segment. It uses Timer 0 interrupt to display the four digits one by one after a time delay of 2.5 milli second
{
    TL0=0x36;
    TH0=0xf6;
    P2=0xFF;
    dig_ctrl_1 = dig_ctrl_3 = dig_ctrl_2 = dig_ctrl_4 = 0;
    dig_disp++;
    dig_disp=dig_disp%6;
    switch(dig_disp)
    {
        case 0:
        P2=digi_val[sec1];
        dig_ctrl_1 = 1;
        break;

        case 1:
        P2=    digi_val[sec2];
        dig_ctrl_2 = 1;
        break;
   
        case 2:
        P2=    digi_val[min1];
        dig_ctrl_3 = 1;
        break;
   
        case 3:
        P2=    digi_val[min2];
        dig_ctrl_4 = 1;
        break;
				
				case 4:
        P2=    digi_val[hrs1];
        dig_ctrl_5 = 1;
        break;
				
				case 5:
        P2=    digi_val[hrs2];
        dig_ctrl_6 = 1;
        break;
					
    }
}

  
 

void main()
{

    TMOD=0x01;        // Intialize Timer 0
    TL0=0x36;
    TH0=0xF6;
    IE=0x82;
    TR0=1;        //Start timer0
    while(1)        // Forward counting
     {
      hrs2=hrs1=min2=min1=sec2=sec1=0;
			 for(hrs2=0;hrs2<=1;hrs2++)
			 {
				 for(hrs1=0;hrs1<=2;hrs1++)
				 {
          for(min2=0;min2<=5;min2++)
          {
               for(min1=0;min1<10;min1++)
               {
                for(sec2=0;sec2<=5;sec2++)
                {
                     for(sec1=0;sec1<10;sec1++)
                     {
                    delay();
                    }
                }
               }
            }
         }
      }
    }
 }
	