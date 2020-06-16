Aluno:
Lucas Daudt Franck (LDFranck)

Exercícios:
1) O valor de y é 4.

2)O erro está no printf do valor do ponteiro para ponteiro.
O código correto seria:

#include <stdio.h>

int main() {
   int x, *p, **q;
   p = &x;
   q = &p;
   x = 10;
   
   printf("\n\%d\n", *(*q));
   
   return 0;
}

3)Apenas as expressões a) e d) são válidas.

4)A função realloc funciona apenas para realocar um espaço
dinamicamente alocado na memória. No caso do exemplo, a função
é chamada para realocar um vetor, o qual foi declarado e alocado
no inicio da execução do código. É possivel verificar erro na
execução ao ler o valor retornado pela função realloc: um 
ponteiro NULL. Além disso, seria interessante colocar um free 
ao final do código para liberar a memoria alocada (caso ocorresse).

5)
I. A função imprime uma sequencia decrescente de numeros a partir
do 'n' até 1, e então imprime fim.
Exemplo com n = 3: 3 2 1 fim

II. A função imprime fim e então uma sequencia de numeros crescente
a partir de 1 até 'n'.
Exemplo com n = 3: fim 1 2 3 

III. A função imprime uma sequencia decrescente de numeros a partir 
do 'n' até 1, imprime fim, e então imprime uma sequencia crescente
de numeros a partir de 1 até 'n'.
Exemplo com n = 3: 3 2 1 fim 1 2 3

IV. A função imprime uma saída um tanto quanto estranha.
Exemplo com n = 3: fim 1 fim 2 fim 1 fim 3 fim 1 fim 2 fim 1 fim

6)"A" é uma string, ou seja, deve ser salva em um vetor de char e
ocupa dois bytes de memória. Isso deve-se ao fato dela ser uma string
ou seja, possui um '\0' no final, logo "A\0".
'A' é um caracter e representa um valor numérico na tabela ASCII.
