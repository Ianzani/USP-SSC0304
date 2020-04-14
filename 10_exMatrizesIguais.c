// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 2

int isMatrizIgual(int matriz[2][TAM][TAM]){

	int c1, c2;
	
	for(c1=0; c1<TAM; c1++)
		for(c2=0; c2<TAM; c2++)if(matriz[0][c1][c2]!=matriz[1][c1][c2])return 0;

	return 1;
}

int main(){

	int c0, c1, c2;
	int matriz[2][TAM][TAM] = {0};
	
	srand(time(NULL));
	
	for(c0=0; c0<2; c0++)
		for(c1=0; c1<TAM; c1++)
			for(c2=0; c2<TAM; c2++)matriz[c0][c1][c2] = rand()%2;
	
	for(c0=0; c0<2; c0++){
		printf("Matriz %d:\n", c0+1);
		for(c1=0; c1<TAM; c1++){
			for(c2=0; c2<TAM; c2++)printf("%d ", matriz[c0][c1][c2]);
			printf("\n");
		}
	}

	printf("As matrizes sao %s.\n", (isMatrizIgual(matriz))?"iguais":"diferentes");
	
	system("pause");
}