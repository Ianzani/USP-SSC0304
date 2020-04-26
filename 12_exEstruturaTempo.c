// Author: LDFranck

#include <stdio.h>

struct horario{
   int horas;
   int minutos;
};

struct horario converteHM1 (struct horario a){
   a.horas = a.minutos / 60;
   a.minutos -= (a.horas*60);
   return a;
}

struct horario converteHM2 (struct horario a){
   a.minutos = a.minutos + a.horas * 60;
   return a;
}

int main (){

   struct horario a;

   printf("Digite o intervalo em min ");
   scanf("%d", &a.minutos);

   a = converteHM1(a);
   printf("Intervalo: %dh:%dmin\n", a.horas, a.minutos);

   printf("Digite o intervalo em hrs:min ");
   scanf("%d:%d", &a.horas, &a.minutos);

   a = converteHM2(a);
   printf("Intervalo: %dmin\n", a.minutos);

   return 0;
}
