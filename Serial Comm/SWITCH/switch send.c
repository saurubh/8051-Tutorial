#include<reg51.h>
sbit sw1=P2^0;                         // switchs connecting port-2 lower pins 0,1,2
sbit sw2=P2^1;
sbit sw3=P2^2;
void Transmit(unsigned char );              // function initialization
void main()
{
unsigned char x;
unsigned char name1[ ]="Embedded systems";
unsigned char name2[ ]="Embedded programming";
unsigned char name3[ ]="Assembly programming";
TMOD=0x20;                                        // timer-1 mode-2
TH1=0xFD;                                        // preset value FD
SCON=0x50;                                      //Serial control 9600 baud rate selection
TR1=1;                                           // run timer-1
while(1)
{
if(sw1==0)                                    // check if switch 1 is pressed
{
for(x=0;x<=16;x++)                            // transmitting 17 characters to serial port
{
Transmit(name1[x]);
}
}
if(sw2==0)                                     // check if switch 2 is pressed
{
for(x=0;x<=20;x++)                              // transmitting 21 characters to the serial port
{
Transmit(name2[x]);
}
}
if(sw3==0)                                       // check if switch 3 is pressed
{
for(x=0;x<=20;x++)                                   // transmitting 21 characters to the serial port
{
Transmit(name3[x]);
}
}
}
}
// serial port declaration
void Transmit(unsigned char i)
{
SBUF=i;
while(TI==0);                                       // wait until serial Transmit interrupt flag  overflow
TI=0;
}