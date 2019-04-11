#### Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

#### 1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.
**Repostas:**
```C
#include <stdio.h>	// Para a funcao printf()
#include <string.h>
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int main(int argc, const char * argv[])
{
	int fp;
	char string[]="Ola mundo!";
	fp = open("ola.txt", O_RDWR | O_CREAT);
		if(fp==-1)
		{
			printf("Erro na abertura do arquivo.\n");
			exit(-1);
		}
	write(fp, string, strlen(string));
	printf("Ola mundo! Escrito.\n");
	write(fp, "\n", 1);
	close(fp);

	return 0;
}

``` 

#### 2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

**Repostas:**
```C
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char * argv[])
{
	int fp;
	char nome[20], idade[4],txt[5] =".txt",arq[100]="";
	printf("Digite o seu nome: ");
	scanf("%s", nome);
	printf("Digite a sua idade: ");
	scanf("%s", idade );
  strcat(arq,nome);
  strcat(arq,txt);
	fp = open(arq, O_RDWR | O_CREAT, S_IRWXU | S_IRUSR);
		if(fp==-1)
		{
			printf("Erro na abertura do arquivo.\n");
			exit(-1);
		}
	printf("Escrevendo nome: %s\n",nome);
	write(fp, "Nome: ", strlen("Nome: "));
	write(fp,  nome, strlen(nome));
	write(fp, "\n", 1);
	printf("Escrevendo nome: %s\n",idade);
	write(fp,"Idade: ", strlen("Idade: "));
	write(fp,idade, strlen(idade));
	write(fp," anos\n", strlen(" anos\n"));
	close(fp);

	return 0;
}

``` 

#### 3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

**Repostas:**
```C
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char * argv[])
{
	int fp;
	char nome[20], idade[4],txt[5] =".txt",arq[100]="";
  strcat(arq,argv[1]);
  strcat(arq,txt);
	fp = open(arq, O_RDWR | O_CREAT, S_IRWXU | S_IRUSR);
		if(fp==-1)
		{
			printf("Erro na abertura do arquivo.\n");
			exit(-1);
		}
	printf("Escrevendo nome: %s\n",argv[1]);
	write(fp,"Nome: ", strlen("Nome: "));
	write(fp, argv[1], strlen(argv[1]));
	write(fp,"\n", 1);
	printf("Escrevendo nome: %s\n",argv[2]);
	write(fp,"Idade: ", strlen("Idade: "));
	write(fp,argv[2], strlen(argv[2]));
	write(fp," anos\n", strlen(" anos\n"));
	close(fp);

	return 0;
}

``` 


#### 4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

**Repostas:**
```C
// bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo){
  int fp;
  int i;
  char c;
  fp = open(nome_arquivo, O_RDONLY );
  if(fp == -1){
    printf("Erro ao abrir o arquivo. Saindo do programa.\n");
    exit(-1);
  }
  while((read(fp,&c,1)) != 0){
    i++;
  }
  close(fp);
return i;
}
// bib_arqs.h
int tam_arq_texto(char *nome_arquivo);

``` 

#### 5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

**Repostas:**
```C
//bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo){
  int fp;
  int i;
  char c;
  fp = open(nome_arquivo, O_RDONLY );
  if(fp == -1){
    printf("Erro ao abrir o arquivo. Saindo do programa.\n");
    exit(-1);
  }
  while((read(fp,&c,1)) != 0){
    i++;
  }
  close(fp);
return i;
}

char* le_arq_texto(char *nome_arquivo){
  int fp;
  int tamanho = tam_arq_texto(nome_arquivo);
  char *string = malloc(sizeof(char)*tamanho);

  fp = open(nome_arquivo, O_RDONLY);
  if(fp == -1){
    printf("Erro ao abrir o arquivo. Saindo do programa.\n");
    exit(1);
  }
  read(fp, string, tamanho);

  close(fp);
  return string;
}
//bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
char* le_arq_texto(char *nome_arquivo);
``` 

#### 6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

**Repostas:**
```C
// Makefile
bib_arqs: main.o bib_arqs.o
	gcc $(CFLAGS) -o cat_falsificado main.o bib_arqs.o
main.o: main.c bib_arqs.h
	gcc $(CFLAGS) -c main.c
bib_arqs.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS) -c bib_arqs.c
clean:
	rm -f *.o cat_falsificado
//main.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int main(int argc, char **argv)
{
	int tamanho = tam_arq_texto(argv[1]);
	char *texto = malloc(sizeof(char)*tamanho);
	texto = le_arq_texto(argv[1]);
	printf("%s", texto);
	free(texto);
	return 0;
}

``` 

#### 7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```

**Repostas:**
```C

``` 
