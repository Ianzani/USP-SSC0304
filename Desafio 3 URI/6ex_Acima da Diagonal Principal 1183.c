// Authors: LDFranck & domingues100

#include <stdio.h>
#define COLUNAS 12

int main(){

    int c1, c2;
    char operacao;
    float M[COLUNAS][COLUNAS], soma = 0;

    scanf("%c", &operacao);

    for(c1=0; c1<COLUNAS; c1++)
		for(c2=0; c2<COLUNAS; c2++)scanf("%f", &M[c1][c2]);
	
    for(c1=0; c1<COLUNAS; c1++)
		for(c2=c1+1; c2<COLUNAS; c2++)soma += M[c1][c2];

    if(operacao == 'S')printf("%.1f\n", soma);
    else printf("%.1f\n", soma/66);
	
	return 0; 
}