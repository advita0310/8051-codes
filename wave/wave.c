#include <REG51.H>

sfr DAC_IN = 0xA0;

void delay(unsigned char n)
{
	unsigned char i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<1275;j++);
	}
}

int main()
{
	unsigned char i;
	unsigned char sine[]={	147	,168	,188	,206	,221	,234	,243	,249	,250	,249	,243	,234	,221	,206,	188	,168	,147	,125	,104	,83	,63	,45	,30	,17	,8	,2	,0	,2	,8	,17	,30	,45	,63,	83	,104	,125};
	while(1)
	{
	for(i=0;i<36;i++)
			{
				DAC_IN=sine[i];
				delay(0);
			}
		}
	return 0;
	}