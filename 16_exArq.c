// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

   FILE *pArquivo;
   char frase[5][65] = {0};
   char nArquivo[21];
   int c1, c2;

   printf("Digite o nome do arquivo (max 15 caracteres): ");
   gets(nArquivo);
   strcat(nArquivo, ".txt");

   pArquivo = fopen(nArquivo, "w");

   printf("Digite 5 frases (max 64 caracteres):\n");
   for(c1=0; c1<5; c1++)gets(frase[c1]);

   printf("Convertendo e salvando as frases...\n");
   for(c1=0; c1<5; c1++){
      for(c2=0; c2<strlen(frase[c1]); c2++)
         if(isalnum(frase[c1][c2]))frase[c1][c2] = toupper(frase[c1][c2]);
         fprintf(pArquivo, "%s\n",  frase[c1]);
   }
   fclose(pArquivo);

   printf("Frases convertidas:\n");
   pArquivo = fopen(nArquivo, "r");
   while (c1 = fgetc(pArquivo), c1 != EOF) {
      putchar(c1);
   }
   fclose(pArquivo);

   return 0;
}
