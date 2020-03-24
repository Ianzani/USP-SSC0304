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

	if(!(--cont)) printf("O numero tem apenas um digito: %d\n", num);
	else printf("A soma do primeiro e ultimo digito: %d\n", (num%10)+(num/(aux/10)));

	system("pause");
}