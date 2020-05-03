// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocaVog(char *frase){
   int tam = strlen(frase);
   for(int c1 = 0; c1 < tam; c1++)
      switch (frase[c1]) {
         case 'a':
            frase[c1] = 'u';
            break;
         case 'e':
            frase[c1] = 'o';
            break;
         case 'i':
            frase[c1] = 'u';
            break;
         case 'o':
            frase[c1] = 'a';
            break;
         case 'u':
            frase[c1] = 'e';
            break;
      }
}


int main(){

   char frase[100];

   printf("Digite a frase:\n");
   fgets(frase, 100, stdin);
   trocaVog(frase);
   puts(frase);

   return 0;
}
