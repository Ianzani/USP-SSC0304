// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int num, aux=1, cont=0;
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

	while((num/aux)){
		aux*=10; 
		cont++;
	}	
	
	printf("Esse numero tem %d digitos.\n", cont);

	system("pause");
}