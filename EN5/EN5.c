//EN5
//BATCH
//QUESTION
//Generate square wave on port pin P1.0 using Timer0 (mode 2) Interrupt (ON time =
//200us) and transmit your full name on serial port upon the occurrence of an External
//Interrupt1. Give highest priority to External Interrupt 1.
//EXPECTED Timer 0 Interrupt: - Toggle P1.0 – TASK1
//External Interrupt1: - Transmit name – TASK2
//200us=NOC*1.0852us
//255-184
//72

#include <REG51.H>
sbit SQR=P1^0;
void t0_isr() interrupt 1
{
		
  SQR=~SQR;
	TH0=0x48;
	
}

void ex1_isr() interrupt 2
{
	unsigned char i;
   unsigned char name[]={"advita"};
	 for(i=0;i<7;i++)
	 { 
		 SBUF = name[i];
		 while(TI==0);
		 TI=0;
	 }

}

int main()
{
	 
   SCON=0x02;
   TMOD = 0x22;
	 TH1=0xFD;
   IE= 0x86;
   TR0=1;
	TR1=1;
   while(1);

} 