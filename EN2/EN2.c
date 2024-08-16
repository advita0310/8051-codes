////EN2
////BATCH
////QUESTION
////Generate rectangular wave on port pin P1.0 using External Interrupt 1 and perform
////Echo operation using Serial Communication Interrupt. Configure both interrupts as
////low level sensitive interrupts and assign highest priority to Serial Communication
////Interrupt. Also toggle P1.1 for Reception Interrupt and toggle P1.2 for Transmission
////Interrupt.
////EXPECTED External Interrupt1: - Rectangular wave on P1.0 – TASK1
////Serial Interrupt : - echo – TASK2 

//#include <REG51.H>
//unsigned char value;
//sbit TP = P1^0;
//sbit LED1= P1^2;
//sbit LED2= P1^1;
//void ex1_isr() interrupt 2
//{
//  TP = ~TP;
//}


//void scon_isr()interrupt 4
//{
//	if(RI==1)
//	{
//		LED2=~LED2;
//		value=SBUF;
//		SBUF=value;
//		RI=0;
//	}
//	if(TI==1)
//	{
//		LED1=~LED1;
//		TI=0;
//	}
//		
//}
// void timer_init()
// {
//	 TMOD=0x20;
//	TH1=0XFD;
// }
// void scon_init()
// {
//	 SCON= 0x50;
// }
// void interr_init()
// {
//	IP = 0x10;
//  IE = 0x94;
// }
//	 
//int main()
//{
//  timer_init();
//	scon_init();
//	interr_init();
//	TR1=1;
//  while(1)
//{
// TP = 0;
//}

//} 





#include <REG51.H>
sbit LED = P1^0;
sbit LED1=P1^1;
sbit LED2=P1^2;
unsigned char value;
void msdelay(unsigned int time)
{
	unsigned char i,j;
	for(i=0;i<255;i++)
	{
		for(j = 0;j<time;j++);
	}
}

void ex1_isr() interrupt 2
{
	LED = 0;
	msdelay(10);
	LED = 1;
	msdelay(40);
}
void scom_isr()interrupt 4
{
	if(RI==1)
	{
		LED2=~LED2;
		value=SBUF;
		SBUF=value;
		RI=0;
	}
	if(TI==1)
	{
		LED1=~LED1;
		TI=0;
	}
		
}
	
void init_timer()
{
	TMOD=0x20;
	TH1=0xFD;
}
void init_scom()
{
	SCON=0x50;
}
void init_interrupt()
{
	IP = 0x10;
	IE=0x94;
}
int main()
{
	LED = 0;
	LED1=0;
	LED2=1;
	init_timer();
	init_scom();
	init_interrupt();
	TR1=1;
	while(1)
	{
		LED = 0;
	}
}