// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

#define QUANT (5)

int main (){

	int numeros[QUANT], aux;
	
	printf("Escreva %d numeros:\n", QUANT);
	
	for(int cont=0; cont<QUANT; cont++)scanf("%d", &numeros[cont]);
	
	for(int cont1=0; cont1<(QUANT-1); cont1++){
		for(int cont2=0; cont2<(QUANT-1); cont2++){
		
			aux = numeros[cont2];
			
			if(numeros[cont2+1]>numeros[cont2]){
				numeros[cont2]=numeros[cont2+1];
				numeros[cont2+1] = aux;
			}
		}
	}
	
	printf("A sequencia ficou: ");
	for(int cont=(QUANT-1); cont>=0; cont--)printf("%d ", numeros[cont]);
	printf("\n");
	
	system("pause");
}