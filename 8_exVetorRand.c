// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main(){

	int vetor[TAM] = {0}, iMaior = 0, iSegMaior = 0;
	
	srand(time(NULL));
	
	for(int i=0; i<TAM; i++){
		
		vetor[i] = rand()%20;
		iMaior = (vetor[iMaior]>vetor[i])?iMaior:i;
		iSegMaior = (vetor[iMaior]>vetor[iSegMaior] && vetor[iSegMaior]>vetor[i])?iSegMaior:i;
		
	}
	
	printf("Vetor: ");
	for(int i=0; i<TAM; i++)printf("%d ", vetor[i]);
	printf("\n");
	
	printf("Maior valor: %d\n", vetor[iMaior]);
	printf("Segundo maior valor: %d\n", vetor[iSegMaior]);
	
	system("pause");	
}
