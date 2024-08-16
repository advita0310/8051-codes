//Generate square wave on port pin P1.0 using Timer 0 interrupt (On time =5ms) and Toggle pin P!.1 usinng External interrupt 0(falling edge sensitivity ).
//Apply P1.0 signal as an external interrupt 0 signal.
//What will be frequency of waveform generated at P1.1.
//Expected external interrupt 0:-Toggle P1.1-TASK2
//timer 0 interruupt :- Toggle P1.0- TASK 1

#include <REG51.H>
sbit LED = P1^0;
sbit LED1 = P1^1;

void ex0_isr() interrupt 0
{
	LED1 = ~LED1;
}

void t0_isr() interrupt 1
{
  LED= ~LED;
	TH0 = 0xEC;
	TL0 = 0x77;
}


int main()
{
	TMOD = 0x01;
	TCON = 0x01;
	TH0 = 0xEC;
	TL0 = 0x77;
	IE = 0x83;
	TR0 = 1;
	while(1);
}