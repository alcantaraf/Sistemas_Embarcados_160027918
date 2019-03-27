Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.
**Resposta:**
```C
#include<stdio.h>
#include <stdlib.h>
int main()
{
  FILE *fp;
  char str[] = "Ola mundo!\n";
  fp = fopen("ola_mundo.txt","w");
  if(!fp){
    printf( "Erro na abertura do arquivo");
    exit(0); }
  fwrite(str, sizeof(str), 1, fp);


  fclose(fp);
  return (0);
}
```
2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
**Resposta:**
```C
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
  FILE *fp;
  int i;
  char nome[20], idade[5],dest[20] =".txt",arq[100]="";
  char frase_1[100] = "Nome:", frase_2[100]= "Idade: ";
  printf("Digite o seu nome: ");
  scanf("%s", nome);
  printf("Digite o sua idade: ");
  scanf("%s", idade );
  strcat(arq,nome);
  strcat(arq,dest);
  fp = fopen(arq,"w");
  if(!fp){
    printf( "Erro na abertura do arquivo\n");
    exit(1); }
    strcat(frase_1, nome);
    strcat(frase_2, idade);
    strcat(frase_2, "\banos");
  for(i=0; frase_1[i]; i++){
    putc(frase_1[i],fp);
  }
  putc('\n', fp);
  for(i=0; frase_2[i]; i++){
    putc(frase_2[i],fp);
  }
  putc('\n', fp);

  fclose(fp);
  return (0);
}

```
3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

**Resposta:**
```C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    FILE *fp;
    char nome[20], idade[5],dest[20] =".txt",arq[100]="";
    char frase_1[100] = "Nome:", frase_2[100]= "Idade: ";
    int i = 1;
    strcpy(nome,argv[1]);
    strcpy(idade,argv[2])
    strcat(arq,nome);
    strcat(arq,dest);
    fp = fopen(arq,"w");
    if(!fp){
      printf( "Erro na abertura do arquivo\n");
      exit(1); }
      strcat(frase_1, nome);
      strcat(frase_2, idade);
      strcat(frase_2, "\banos");
    for(i=0; frase_1[i]; i++){
      putc(frase_1[i],fp);
    }
    putc('\n', fp);
    for(i=0; frase_2[i]; i++){
      putc(frase_2[i],fp);
    }
    putc('\n', fp);
    fclose(p);              /* Fecha o arquivo */
    return(0);
}

}

```


4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
