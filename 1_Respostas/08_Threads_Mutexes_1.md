### 1. Quais são as vantagens e desvantagens em utilizar:

#### (a) fork?
**Respostas:**
Cada processo criado executa suas proprias tarefas e tem seu espaço protegido em memoria, porém a comunicação entre processos tem maior dificuldade para ser realizada.
#### (b) threads?
**Respostas:**
As threads ocupam o mesmo espaço de memoria, isso é ruim, pois uma pode afetar as variaveis de outra. A comunicação entre threads é mais simples por ocuparem o mesmo espaço de memoria. 
### 2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

#### (a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
**Respostas:**
Foram criadas 2 thereads, coexistirão as 2 criadas. Pois elas são finalizadas após as duas serem criadas.
#### (b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
**Respostas:**
Foram criadas 2, não coexistiram, pois antes da segunda ser colocada a primeira foi finalizada.
### 3. Apresente as características e utilidades das seguintes funções:
***(DICA: elas são relacionadas à função pthread_cancel().)***
#### (a) `pthread_setcancelstate()`
**Respostas:**
O estado de cancelamento pode ser ativado ou desativado. Caso esteja desativado, o cancelamento fica na fila até que o cancelamento estava em ativado. Caso estaja ativado, então o tipo de cancelamento determina quando o cancelamento vai ocorrer.
#### (b) `pthread_setcanceltype()`
**Respostas:**
O tipo de cancelamento pode ser tanto assincrono quanto adiado. Quando está em assíncrono, o cancelamento pode ocorrer a qualquer momento. Quando está em adiado, o cancelamento sofrerá um atraso até a thread em seguida chame uma função que seja o ponto de cancelamento.
