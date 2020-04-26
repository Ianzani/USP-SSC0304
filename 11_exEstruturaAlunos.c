// Author: LDFranck

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N_ALUNOS (10)

struct aluno{
   int id;
   int nota;
};

int maiorNota(struct aluno a[]){
   struct aluno aux;
   int c1, c2;

   for(c2 = 0; c2 < N_ALUNOS; c2++)
      for(c1 = 0; c1 < (N_ALUNOS-1); c1++){
         if(a[c1+1].nota > a[c1].nota){
            aux = a[c1];
            a[c1] = a[c1+1];
            a[c1+1] = aux;
         }
      }

   return a[0].nota;
}

void notaRepetida(struct aluno a[]){
   int c1 = 0, c2 = 0;

   while (c1<N_ALUNOS) {
      if (a[c1].nota == a[c1+c2].nota) c2++;
      else {
         printf("%d ocorre %d vezes\n", a[c1].nota, c2);
         c1 += c2;
         c2 = 0;
      }
   }
}

int main (){

   int c1;
   struct aluno classe[N_ALUNOS];

   srand(time(NULL));

   for (c1 = 0; c1 < N_ALUNOS; c1++) {
      classe[c1].id = rand()%1000;
      classe[c1].nota = rand()%11;
   }

   for (c1 = 0; c1 < N_ALUNOS; c1++)
      printf("%3d - nota: %2d\n", classe[c1].id, classe[c1].nota);

   printf("Maior nota: %d\n", maiorNota(classe));

   notaRepetida(classe);

   return 0;
}
