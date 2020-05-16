// Authors: LDFranck & domingues100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pessoa{
   char nome[50];
   char cpf[50];
   int idade;
}pessoa;

pessoa* criaRegistro(char *nome, char *cpf, int idade){
   pessoa* aux = malloc(sizeof(pessoa));
   if (aux == NULL) {
      printf ("ERRO MALLOC\n");
      exit (1);
   }
   strcpy(aux->nome, nome);
   strcpy(aux->cpf, cpf);
   aux->idade = idade;
   return aux;
}

int main(){

   int ncad, ninfo, cont;
   int cadeira, idade;
   char nome[50], cpf[50];
   scanf("%d %d", &ncad, &ninfo);

   pessoa* lista[ncad];
   for(cont=0; cont<ncad; cont++)lista[cont] = NULL;

   for(cont=0; cont<ninfo; cont++){
      scanf("%d %s %s %d", &cadeira, nome, cpf, &idade);
      if(lista[cadeira]==NULL)lista[cadeira] = criaRegistro(nome, cpf, idade);
      else printf("Cadeira %d ja comprada.\n", cadeira);
   }

   for(cont=0; cont<ncad; cont++){
      if(lista[cont]==NULL)printf("%d - NULL\n", cont);
      else printf("%d - %s %s %d\n", cont, lista[cont]->nome, lista[cont]->cpf, lista[cont]->idade);
   }

   for(cont=0; cont<ncad; cont++)free(lista[cont]);

   return 0;
}
