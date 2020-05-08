// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valorAcao(int **mat, int acao, int semana){

   return mat[acao-1][semana-1];
}

int* vetorDiferenca(int **mat, int semA, int semB, int nlinhas){

   int *temp = malloc(nlinhas * sizeof(int));

   for(int a1=0; a1<nlinhas; a1++)temp[a1] = mat[a1][semB-1] - mat[a1][semA-1];

   return temp;
}

int main() {

   int lin, col, auxA, auxB, c1, c2;
   int *aux;

   printf("Digite o numero de acoes: ");
   scanf("%d", &lin);
   printf("Digite o numero de semanas: ");
   scanf("%d", &col);

   srand(time(NULL));

   int **mat = malloc(lin * sizeof(int *));

   for(c1=0; c1<lin; c1++) mat[c1] = malloc(col * sizeof(int));

   for(c1=0; c1<lin; c1++){
      for(c2=0; c2<col; c2++){
         mat[c1][c2] = rand()%10;
         printf("%d ", mat[c1][c2]);
      }
      printf("\n");
   }

   printf("Digite uma acao e uma semana: ");
   scanf("%d %d", &auxA, &auxB);
   printf("O valor da acao %d era %d.\n", auxA, valorAcao(mat, auxA, auxB));

   printf("Digite duas semanas (A e B): ");
   scanf("%d %d", &auxA, &auxB);
   aux = vetorDiferenca(mat, auxA, auxB, lin);
   printf("A variacao (B - A) foi de: \n" );
   for(c1=0; c1<lin; c1++)printf("%d ", aux[c1]);
   printf("\n");

   for(c1=0; c1<lin; c1++)free(mat[c1]);
   free(mat);
   free(aux);

   return 0;
}
