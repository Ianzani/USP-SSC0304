// Authors: LDFranck & domingues100

#include <stdio.h>

typedef struct _alimento{
  int cal, carb;
  char nome[50];
}alimento;

void funcComparacao(alimento dieta[], int n){
   int i, j;
   alimento aux;
   for(j=0;j<n;j++)
      for(i=0;i<(n-1);i++){
         if(dieta[i].cal>dieta[i+1].cal){
            aux=dieta[i];
            dieta[i]=dieta[i+1];
            dieta[i+1]=aux;
            continue;
         }
         if(dieta[i].cal==dieta[i+1].cal)
            if(dieta[i].carb>dieta[i+1].carb){
               aux=dieta[i];
               dieta[i]=dieta[i+1];
               dieta[i+1]=aux;
            }
      }
}

int main(){

   int n, cont;

   scanf("%d", &n);
   alimento lista[n];

   for(cont=0; cont<n; cont++){
      fflush(stdin);
      gets(lista[cont].nome);
      scanf("%d", &lista[cont].cal);
      scanf("%d", &lista[cont].carb);
   }

   funcComparacao(lista, n);

   for(cont=1; cont<(n+1); cont++){
      printf("%d - %s\n",cont, lista[cont-1].nome);
   }

   return 0;
}
