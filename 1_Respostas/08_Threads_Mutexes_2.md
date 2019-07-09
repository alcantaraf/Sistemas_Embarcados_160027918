### 1. Crie um programa em C que cria uma thread, e faça com que o programa principal envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para a thread, com intervalos de 1 segundo entre cada envio. Depois de o programa principal enviar o número 10, ele aguarda 1 segundo e termina a execução. A thread escreve na tela cada valor recebido, e quando ela receber o valor 10, ela termina a execução.
**Respostas:**
```C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

volatile int cnt=0;
static pthread_mutex_t mutexLock;

void *thread_function(void *arg)
{
	int i1=cnt;
	while(i1!=10)
	{
		while(i1==cnt);
		i1 = cnt;
		printf("%d\n", i1);
	}
	pthread_exit(0);
}

int main()
{
	int i;
	pthread_t a_thread;
	void *thread_result;
	pthread_create(&a_thread, NULL, thread_function, NULL);
	for(i=0; i<10; i++)
	{
		sleep(1);
		cnt++;
	}
	sleep(1);
	pthread_join(a_thread, NULL);
	return 0;
}
```
### 2. Crie um programa em C que preenche o vetor `long int v[50000]` completamente com valores aleatórios (use a função `random()`), e que procura o valor máximo do vetor por dois métodos:

#### (a) Pela busca completa no vetor `v[]`;
**Respostas:**
```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 50000
long int v[MAX];
int i;


int main() {
    int valor_max = 0;

    for(i = 0; i < MAX ; i++) {
        v[i] = random();
    }
    valor_max = v[0];
    for(i = 0; i < MAX ; i++) {
        if(v[i] > valor_max) {
            valor_max = v[i];
        }
        
 	}  

    printf("Valor valor_max: %d\n", valor_max); 	
 	return 0;
}
```
#### (b) Separando o vetor em 4 partes, e usando 4 threads para cada uma encontrar o máximo de cada parte. Ao final das threads, o programa principal compara o resultado das quatro threads para definir o máximo do vetor.
**Respostas:**
```C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

long int v[50000];
int i,k;
int  max_value = 0, max_valueFunc[4]={0};


void *find_max1(void *parameters) {
    int* v = (int *) parameters;
    for(k = 0; k < 12500 ; k++) {
        if(*(v + i) > max_valueFunc[0]) {
            max_valueFunc[0] = *(v + i);
        }
 	}
}
void *find_max2(void *parameters) {
    int* v = (int *) parameters;
    for(k = 0; k < 12500 ; k++) {
        if(*(v + i) > max_valueFunc[1]) {
            max_valueFunc[1] = *(v + i);
        }
 	}
}
void *find_max3(void *parameters) {
    int* v = (int *) parameters;
    for(k = 0; k < 12500 ; k++) {
        if(*(v + i) > max_valueFunc[2]) {
            max_valueFunc[2] = *(v + i);
        }
 	}
}
void *find_max4(void *parameters) {
    int* v = (int *) parameters;
    for(k = 0; k < 12500 ; k++) {
        if(*(v + i) > max_valueFunc[3]) {
            max_valueFunc[3] = *(v + i);
        }
 	}
}


int main() {

    pthread_t thread_1, thread_2, thread_3, thread_4;

    for(i = 0; i < 50000 ; i++)	{
        v[i] = random();
    }

    pthread_create(&thread_1,NULL, &find_max, &v[0];
 	  pthread_create(&thread_2,NULL, &find_max, &v[12500]);
 	  pthread_create(&thread_3,NULL, &find_max, &v[25000]);
 	  pthread_create(&thread_4,NULL, &find_max, &v[37500]);
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    pthread_join(thread_4,NULL);
    for(i=0;i<4;i++){
      if(max_valueFunc[i]>max_value) max_value = max_valueFunc[i];
    }
    printf("Valor max: %d\n",  max_value);

    return 0;
}

```

### 3. Repita o exercício anterior, mas calcule a média do vetor ao invés do valor máximo.
**Respostas:**
```C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

long int v[50000];
int i;
long int  soma, soma_1, soma_2, soma_3;


void *print_thread_1(void *parameters) {
    for(i = 0; i < 12500 ; i++)	{
            soma = soma + v[i];
 	}  
}

void *print_thread_2(void *parameters) {
    for(int n = 12500; n < 25000 ; n++)	{           
        soma_1 = soma_1 + v[n];
 	}  
}

void *print_thread_3(void *parameters) {
    for(int m = 25000; m < 37500 ; m++) {
        soma_2 = soma_2 + v[m];
 	}  
}

void *print_thread_4(void *parameters) {
    for(int k = 37500; k < 50000 ; k++) {
        soma_3 = soma_3 + v[k];
 	}  
}

int main() {

    pthread_t thread_1, thread_2, thread_3, thread_4;

    for(i = 0; i < 50000 ; i++)	{
        v[i] = random();
    }

    pthread_create(&thread_1,NULL, &print_thread_1, &thread_1);
 	pthread_create(&thread_2,NULL, &print_thread_2, &thread_2);
 	pthread_create(&thread_3,NULL, &print_thread_3, &thread_3);
 	pthread_create(&thread_4,NULL, &print_thread_4, &thread_4);

    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    pthread_join(thread_4,NULL);

    soma = soma + soma_1 + soma_2 + soma_3;
    printf("Media: %ld\n",  soma/50000); 	    

    return 0;
}
```
### 4. Repita o exercício anterior, mas calcule a variância do vetor ao invés da média.
**Respostas:**
```C

```
