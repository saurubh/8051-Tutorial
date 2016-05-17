#include<reg51.h>
void T0delay(void);
sbit Mybit=P2^0;      // output PWM port
void main(void)
{
unsigned char x;
while(1)
{
Mybit=1;
for(x=0;x<10;x++)     // generating 250ms delay for ON time
{
T0delay();
}
Mybit=0;
for(x=0;x<10;x++)  // generating 250ms delay for OFF time
{
T0delay();
}
Mybit=1;
for(x=0;x<5;x++)  // generating 125ms delay for ON time
{
T0delay();
}
Mybit=0;
for(x=0;x<5;x++)  // generating 125ms delay for OFF time
{
T0delay();
}
Mybit=1;
for(x=0;x<2;x++)  // generating 50ms delay for ON time
{
T0delay();
}
Mybit=0;
for(x=0;x<2;x++)  // generating 50ms delay for OFF time
{
T0delay();
}
}
}
// 25ms delay function
void T0delay(void)
{
TMOD=0X01; // timer-0 mode-1
TL0=0xFE;
TH0=0xA5;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
}