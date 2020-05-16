// Authors: LDFranck & domingues100

#include <stdio.h>

typedef struct _agenda{
   int dia, mes, ano;
   int hora, min, seg;
   char ativ[100];
}agenda;

void printAgenda (agenda a){
   printf("%02d/%02d/%02d - %02d:%02d:%02d\n", a.dia, a.mes, a.ano, a.hora, a.min, a.seg);
   printf("%s\n", a.ativ);
}

int main(){
   int n, cont;

   scanf("%d", &n);
   agenda lista[n];

   for(cont=0; cont<n; cont++){
      scanf("%d", &lista[cont].dia);
      scanf("%d", &lista[cont].mes);
      scanf("%d", &lista[cont].ano);
      scanf("%d", &lista[cont].hora);
      scanf("%d", &lista[cont].min);
      scanf("%d", &lista[cont].seg);
      fflush(stdin);
      gets(lista[cont].ativ);
   }

   for(cont=0; cont<n; cont++)printAgenda(lista[cont]);

   return 0;
}
