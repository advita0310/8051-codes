//EN1
//BATCH
//QUESTION
//Operate DC Motor in any direction when External Interrupt 1 occurs and display
//“HELP” on CCSSD Multiplexed Display when External Interrupt 0 Occurs. Configure
//both interrupts as level sensitive interrupts and assign highest priority to External
//Interrupt 1.
//EXPECTED External Interrupt 0: - DC motor should be ON – TASK1
//External Interrupt 1: - HELP should be display – TASK2

#include <REG51.H>
sbit DCM = P3^0;
void delay(int t)
{
	unsigned char i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<255;j++);
	}
}
	void ex0_isr() interrupt 0
 {
  DCM = 1;
 }

void ex1_isr() interrupt 2
{
	unsigned char i;
unsigned char HELP[] =  {0X76, 0X79, 0X38, 0X73};
unsigned char DATA[] = {0X0E,0X0D,0X0B,0X07};
while(1)
{
	for(i=0;i<4;i++)
	{
		P1=DATA[i];
		P2=HELP[i];
		delay(10);
	}
}
}

int main()
{

	IP=0x04;
	IE=0x86;
  while(1);

} 
