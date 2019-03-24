#include <msp430f249.h>
#define uchar unsigned char
#define uint unsigned int

uchar const LED_Lib[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

extern uchar time[];

void tube1(void)
{
  P1OUT = LED_Lib[time[0] % 10];
}

void tube2(void)
{ 
  P1OUT = LED_Lib[(time[0] / 10) % 10];
}

void tube3(void)
{
  P1OUT = LED_Lib[time[1] % 10];
}

void tube4(void)
{ 
  P1OUT = LED_Lib[(time[1] / 10) % 10];
}

void tube5(void)
{
  P1OUT = LED_Lib[time[2] % 10];
}

void tube6(void)
{ 
  P1OUT = LED_Lib[(time[2] / 10) % 10];
}