// Authors: LDFranck & domingues100

#include <stdio.h>

#define COLUNAS 12

int main(){

    int linha, c1, c2;
    char operacao;
    float M[COLUNAS][COLUNAS], soma = 0;

    scanf("%d %c", &linha, &operacao);

    for(c1=0; c1<COLUNAS; c1++)
       for(c2=0; c2<COLUNAS; c2++)scanf("%f", &M[c1][c2]);
    
	for(c1=0; c1<COLUNAS; c1++)soma += M[linha][c1];

    if(operacao == 'S')printf("%.1f\n", soma);
    else printf("%.1f\n", soma/COLUNAS);

	return 0; 
}