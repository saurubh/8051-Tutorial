# include<reg51.h>
unsigned char col[]= {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}, 

 row[] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
          0x03,0xed,0xee,0xee,0xee,0xed,0x03,0xff,
          0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
          0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};        // 1

void delay(unsigned int itime)
{
unsigned int n,m;
	for(n=0;n<itime;n++)
	for(m=0;m<125;m++);
}

void main()
{
int i,j,k;
while(1)
{
for(j=0;j<16;j++)
for(k=0;k<30;k++)
for(i=0;i<8;i++)
{
P3 = col[i];
P2 = row[j+i];
delay(1);
	P3 = 0x00;
//delay(5);	
}
}
}