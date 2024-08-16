//EN4
//BATCH
//QUESTION
//Generate square wave on port pin P1.0 using External Interrupt 0 and display numbers
//from 0 to 9 on CCSSD using External Interrupt 1 (both are level sensitive). Assign
//highest priority to External Interrupt 1.
//EXPECTED External Interrupt0: - square wave on P1.0 – TASK1
//External Interrupt1: - 0 to 9 on CCSSD – TASK2

#include <REG51.H>


sbit SQR = P1^0;
void delay (int t)
{
	unsigned char i;
	unsigned char j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<155;j++);
	}
}
 void ex0_isr() interrupt 0
	 {
		 SQR=~SQR;
}

 void ex1_isr() interrupt 2
{
	unsigned char i;
  unsigned char CCSSD[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0X07,0X7F,0x6F};
	for(i=0;i<10;i++)
		{
			P2=CCSSD[i];
			delay(10);
		}
   
}

int main()
{
  IE = 0x85;
	IP = 0x04;
  while(1);

} 