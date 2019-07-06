#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

int main(void)
{
    int valueIn, inc=0, valueOut=0;
    wiringPiSetup();
    pcf8591Setup(BASE,Address);

    while(1)
    {
	valueIn = analogRead(A0);
	if(inc==0)
        	analogWrite(A0,valueOut++);
	else
		analogWrite(A0,valueOut--);
	if(valueOut==255)
		inc=1;
	else if(valueOut==0)
		inc=0;
	printf("AOUT: %d\n",valueOut);
	delay(valueIn/100);	
    }
}