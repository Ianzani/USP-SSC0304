// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

#define COL (4)
#define LIN (3)

int main() {

   int **mat = malloc(LIN * sizeof(int *));
   int contador = 0;

   for(int c1=0; c1<LIN; c1++) mat[c1] = malloc(COL * sizeof(int));

   for(int c1=0; c1<LIN; c1++){
      for(int c2=0; c2<COL; c2++){
         mat[c1][c2] = contador++;
         printf("%d ", mat[c1][c2]);
      }
      printf("\n");
   }
   
   for(int c1; c1<LIN; c1++)free(mat[c1]);
   free(mat);

   return 0;
}
