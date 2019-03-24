#include <msp430f249.h>
#include "tube.h"
#define uchar unsigned char
#define uint unsigned int

uchar time[]={49,59,21};

void initialize(void)
{
  P1DIR = 0xFF;
  P1OUT = 0x00;
  P1SEL = 0X00;
  
  P3DIR = 0xFF;
  P3OUT = 0xFF;
}

void delayus(uint t)
{
  uint i;
  while(t--)
    for(i=293;i>0;i--);
}


void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initialize();
  uchar i;
  while(1)
  {
    for(;time[2]<=23;++time[2])
    {
      for(;time[1]<=59;++time[1])
      {
        for(;time[0]<=59;++time[0])
        {
          for(i=0;i<25;i++)
          {
            P3OUT &=~ BIT0;
            tube6();
            delayus(1);
            P3OUT |= BIT0;
            
            P3OUT &=~ BIT1;
            tube5();
            delayus(1);
            P3OUT |= BIT1;
            
            P3OUT &=~ BIT2;
            P1OUT = 0x40;
            delayus(1);
            P3OUT |= BIT2;
            
            P3OUT &=~ BIT3;
            tube4();
            delayus(1);
            P3OUT |= BIT3;
            
            P3OUT &=~ BIT4;
            tube3();
            delayus(1);
            P3OUT |= BIT4;

            P3OUT &=~ BIT5;
            P1OUT = 0x40;
            delayus(1);
            P3OUT |= BIT5;

            
            P3OUT &=~ BIT6;
            tube2();
            delayus(1);
            P3OUT |= BIT6;
            
            P3OUT &=~ BIT7;
            tube1();
            delayus(10);
            P3OUT |= BIT7;
          }

        }
        time[0] = 0;
      }
      time[1] = 0;
    }
  }
}
