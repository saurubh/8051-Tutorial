    #include<regx51.h>
    #include<stdio.h>
    sbit rs=P3^5;
    sbit rw=P3^6;
    sbit en=P3^7;
    void lcd(char a,int b);                       //subroutine for lcd display
    unsigned char msg[]="Count";
    char ch[4];
    void delay();                                   //sub routine for delay
    void counter();                              //subroutine for counters
    int k;
    unsigned int val;
    void main()
     {
       lcd(0x38,0);
       lcd(0x0c,0);
       lcd(0x80,0);
       TMOD=0x05;                              //selecting counter mode 
       counter();                                
     }
    void delay()
     {
       int i;
       for(i=0;i<=2000;i++);               //software delay
     } 
    void counter()
     {
       TL0=0;                                 //lodaing initial value
       TR0=1;                               //starting timer
       for(k=0;k<5;k++)
         {
           lcd(msg[k],1);
         }
       while(1)
        {
          lcd(0x86,0);                          //setting fixed position
          val=TL0|TH0<<8;                 //shifting the values from TL0 to TH0
          sprintf(ch,"%u",val);            //conversion of integer to character 
          for(k=0;k<5;k++)
            {
              lcd(ch[k],1);
            }
        }
      }
     void lcd(char a,int b)
       {
         P1=a;
         rs=b;
         rw=0;
         en=1;
         delay();
         en=0;
         delay();
       }
