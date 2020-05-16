// Authors: LDFranck & domingues100

#include <stdio.h>

typedef struct _paciente{
	char nome[50];
   float altura;
   float peso;
   char genero;
   unsigned int id;
}paciente;

void printPaciente(paciente a){
   printf("nome: %s\n", a.nome);
   printf("altura: %.2f\n", a.altura);
   printf("peso: %.2f\n", a.peso);
   printf("genero: %c\n", a.genero);
   printf("id: %d\n\n", a.id);
}

int main(){
   int num, c1;
   scanf("%d", &num);

   paciente lista[num];

   for(c1=0; c1<num; c1++){
      fflush(stdin);
      gets(lista[c1].nome);
      scanf("%f", &lista[c1].altura);
      scanf("%f", &lista[c1].peso);
      scanf("\n%c", &lista[c1].genero);
      scanf("%d", &lista[c1].id);
   }

   while(scanf("%d", &num), num!=-1){
      for(c1=0; c1<num; c1++) if(lista[c1].id==num){
         printPaciente(lista[c1]);
         break;
      }
   }

	return 0;
}
