#### 1. Escreva um código em C para gerar uma onda quadrada de 1 Hz em um pino GPIO do Raspberry Pi.
**Resposta:**

```C
#include <wiringPi.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define PinOut 23
#define HPeriod (1e6/2)

int main(void){
  wiringPiSetup();
	pinMode(PinOut, OUTPUT);
  while(1){
      digitalWrite(PinOut, HIGH);
			usleep(HPeriod);
			digitalWrite(Pinout, LOW);
			usleep(HPeriod);
  }
  
}
```

#### 2. Generalize o código acima para qualquer frequência possível.

**Resposta:**

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <unistd.h>


#define PinOut 23
#define Period (1e6)



int main(int argc, char **argv)
{
  wiringPiSetup();
	pinMode(PinOut, OUTPUT);
  int freq;
  int hperiod;
  freq = atoi(argv[1]);
  hperiod = Period/(2*freq); 
  while(1){
      digitalWrite(PinOut, HIGH);
			usleep(HPeriod);
			digitalWrite(Pinout, LOW);
			usleep(HPeriod);
  }
  
}
```

#### 3. Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai lê um botão no GPIO, aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, e dobrar cada vez que o botão for pressionado. A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for pressionado novamente.

**Resposta:**

```C
#include <wiringPi.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define PinOut 23
#define PinIn 24
#define MAX_MEIO_PERIODO (1e6/2)
#define MIN_MEIO_PERIODO (1e6/64)

int meio_periodo = MAX_MEIO_PERIODO;

void muda_freq()
{
	meio_periodo /= 2;
	if(meio_periodo<MIN_MEIO_PERIODO)
		meio_periodo = MAX_MEIO_PERIODO;
}

int main(void)
{
	pid_t filho;
	wiringPiSetup();
	pinMode(PinOut, OUTPUT);
	pinMode(PinIn, INPUT);
	pullUpDnControl(PinIN, PUD_UP);
	signal(SIGUSR1, muda_freq);
	filho = fork();
	if(filho==0)
	{
		while(1)
		{
			digitalWrite(PinOut, HIGH);
			usleep(meio_periodo);
			digitalWrite(PinOut, LOW);
			usleep(meio_periodo);
		}
	}
	else
	{
		while(1)
		{
			while(digitalRead(PinIn)>0);
			kill(filho,SIGUSR1);
			while(digitalRead(PinIn)==0);
			usleep(300000);
		}
	}
}

```

