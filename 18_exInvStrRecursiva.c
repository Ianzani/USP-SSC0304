// Author: LDFranck

#include <stdio.h>
#include <string.h>

char *recStrInv(char *str){

   static char *p = NULL;
   static int half, full, cont;
   char aux;

   if(str){
      p = str;
      full = strlen(str) - 1;
      half = full/2. + 0.5;
      cont = 0;
   }
   else if(!p) return 0;

   if(cont>half)return p;
   aux = p[full-half+cont];
   p[full-half+cont] = p[half-cont];
   p[half-cont] = aux;
   cont++;

   recStrInv(NULL);
}

int main(){

   char string[51];

   printf("Digite uma frase (max 50char):\n");
   scanf("%50[^\n]", string);
   printf("A frase invertida:\n");
   printf("%s\n", recStrInv(string));

   return 0;
}
