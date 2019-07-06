#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3
#define POT 10.62

int main(void)
{
    float value;
    wiringPiSetup();
    pcf8591Setup(BASE,Address);
    float pot=POT;

    while(1)
    {
	value = analogRead(A0);
	pot = ((-value*(POT)/255)+POT);	
	
	printf("\nValue: %f (de 255)\n", value);
	printf("Value: %f Volts\n", value*3.3/255);
        printf("Potenciometer: %f KOhms\n", pot);
        delay(1000);
    }
}