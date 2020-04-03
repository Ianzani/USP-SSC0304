// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int maiorValor(int vetor[]){
	
	int aux=0;

	for(int i=0; i<TAM; i++)aux=(vetor[aux]>vetor[i])?aux:i;
	
	return vetor[aux];
}

int main(){

	int vetor[TAM] = {0};
	
	srand(time(NULL));
	
	for(int i=0; i<TAM; i++) vetor[i] = rand()%100;
	
	printf("Vetor: ");
	for(int i=0; i<TAM; i++)printf("%d ", vetor[i]);
	printf("\n");
	
	printf("Maior valor: %d\n", maiorValor(vetor));
	
	system("pause");
	
}
