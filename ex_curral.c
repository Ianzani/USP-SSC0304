// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	int nCabecas, nPes, nPatos, nCoelhos;
	
	while(1){
		
		printf("Insira o numero de Cabecas: ");
		scanf("%d", &nCabecas);
		
		if(nCabecas<=0) printf("Valor invalido...\n");
		else break;
	}
	
	while(1){
		
		printf("Insira o numero de Pes: ");
		scanf("%d", &nPes);

		if(nPes < 2*nCabecas || nPes%2 || nPes > 4*nCabecas) printf("Valor invalido...\n");
		else break;
	}
	
	nPatos = (4*nCabecas - nPes)/2.0;
	nCoelhos = (nPes - 2*nCabecas)/2.0;
	
	printf("O numero de Patos: %d.\n", nPatos);
	printf("O numero de Coelhos: %d.\n", nCoelhos);
	
	system("pause");
}