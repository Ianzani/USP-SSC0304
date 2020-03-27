// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int tam;
	char flag = 0;
	
	printf("Digite o tamanho da seta: ");
	scanf("%d", &tam);
	
	for(int c=1; (c<=tam)&(c>0); c+=(flag)?-1:1){
		for(int i=0; i<c; i++)printf("*");
		printf("\n");
		flag = (c==tam)|flag;
	}
	system("pause");
}