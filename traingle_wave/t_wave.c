#include <REG51.H>
sfr DAC_IN=0xA0;
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
	 while(1)
	 {
	 
		 for(i=0;i<255;i++)
		 {
			 		 DAC_IN=i;
					delay(0);
			}
		 		 for(;i>=1;i--)
		 {
			 DAC_IN=i;
		   delay(0);
		 }
	 
		}

	 return 0;
 }