#include<reg51.h>
void delay(void);       
void count1(void);    
void count2(void);
sbit NR=P0^0; sbit NY=P0^1; sbit NG=P0^2; sbit NGL=P0^3;        //Setting bit for LED's north
sbit SR=P0^4; sbit SY=P0^5; sbit SG=P0^6; sbit SGL=P0^7;       //Setting Bit for LED's South
sbit ER=P1^0; sbit EY=P1^1; sbit EG=P1^2; sbit EGL=P1^3;      //Setting Bit for LED's East
sbit WER=P1^4; sbit WEY=P1^5; sbit WEG=P1^6; sbit WEGL=P1^7;        //Setting Bit for LED's West
unsigned char a[10]={0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x3f};         //Array for displaying digits on segment 1,2.......9,0
unsigned char b[7]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d};             //Array for displaying 0 to 6
unsigned int i,j,s,k;                 //Assigning Integers
void main()                            //Main program
  {
     NR=1; NY=1; NG=0; NGL=1;           // I phase forward green for north lights
     SR=1; SY=1; SG=0; SGL=1;         // forward green for south lights
     ER=0; EY=1; EG=1; EGL=1;        //Red signal for east
     WER=0; WEY=1; WEG=1; WEGL=1;       //Red signal for west lights
    {
       count1();
	}                  		           //Calling out subroutine to display digits in 7 segment
     NR=1; NY=1; NG=0; NGL=1;     //I phase yellow signal
     SR=1; SY=1; SG=0; SGL=1;     
     ER=1; EY=0; EG=1; EGL=1;    
     WER=1; WEY=0; WEG=1; WEGL=1;
      {
       count2();                         //Calling out sub routine for displaying counts for yellow
      }
     NR=0; NY=1; NG=1; NGL=1;      //II phase red signal for north lights
     SR=0; SY=1; SG=1; SGL=1;      
     ER=1; EY=1; EG=0; EGL=1;    
     WER=1; WEY=1; WEG=0; WEGL=1;
      {
       count1();
      }
     NR=1; NY=0; NG=1; NGL=1;     //II phase yellow lights for North and south
     SR=1; SY=0; SG=1; SGL=1;
     ER=1; EY=1; EG=0; EGL=1;     
     WER=1; WEY=1; WEG=0; WEGL=1;
       {
       count2();
       }
     NR=1; NY=1; NG=1; NGL=0;     //III phase Green left for north and south
     SR=1; SY=1; SG=1; SGL=0;
     ER=0; EY=1; EG=1; EGL=1;     
     WER=0; WEY=1; WEG=1; WEGL=1;
       {
       count1();
       }
     NR=1; NY=1; NG=1; NGL=0;    //III phase yellow lights
     SR=1; SY=1; SG=1; SGL=0;
     ER=1; EY=0; EG=1; EGL=1;     
     WER=1; WEY=0; WEG=1; WEGL=1;
     {
       count2();
       }
     NR=0; NY=1; NG=1; NGL=1;     //IV phase Red signal for North and south
     SR=0; SY=1; SG=1; SGL=1;
     ER=1; EY=1; EG=1; EGL=0;     
     WER=1; WEY=1; WEG=1; WEGL=0;
     {
       count1();
       }
     NR=1; NY=0; NG=1; NGL=1;      //IV phase Yellow signal for north and south
     SR=1; SY=0; SG=1; SGL=1;
     ER=1; EY=1; EG=1; EGL=0;      
     WER=1; WEY=1; WEG=1; WEGL=0;
     {
       count2();
       }
     }
  void count1(void)     //Sub routine for displaying numbers in segments for red signal
    {
   P2=0x3f;
    for(j=0;j<=4;)
      {
       for(i=0;i<=8;)
       {
        P3=a[i];
        i++;
        delay();
        }
       j++;
       P2=b[j];
       P3=0x3f;
       delay();
      }
    }
  void count2(void)           //Sub routine for displaying numbers in segments for yellow signal
    {
      P2=0x3f;
      for(i=0;i<=8;)  
        {
         P3=a[i];
         i++;              
         delay();
        }
       P2=0x06;         
       P3=0x3f;
       delay();          
  }
  void delay(void)      //Sub routine for creating delay
    {
      for(s=0;s<=230;s++)     //Creating delay using number count
       {
         for(k=0;k<238;k++);
       }
    }