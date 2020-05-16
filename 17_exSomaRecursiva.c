// Author: LDFranck

#include <stdio.h>

int funcSoma(int num){
   if(num<1)return 0;
   else return funcSoma(num-1)+num;
}

int main(){

   int aux;

   printf("Digite um numero: ");
   scanf("%d", &aux);

   printf("O somatorio de 1 - %d: %d", aux, funcSoma(aux));

   return 0;
}
