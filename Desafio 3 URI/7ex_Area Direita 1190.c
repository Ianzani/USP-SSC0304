// Authors: LDFranck & domingues100

#include <stdio.h>
#define NCOL 12

int main(){

    int c1, c2;
    char operacao;
    float M[NCOL][NCOL], soma = 0;

    scanf("%c", &operacao);

    for(c1=0; c1<NCOL; c1++)
		for(c2=0; c2<NCOL; c2++)scanf("%f", &M[c1][c2]);
	
	for(c1=0; c1<NCOL; c1++)
		for(c2=(c1<6)?(NCOL-c1):(c1+1); c2<NCOL; c2++)soma += M[c1][c2];

    if(operacao == 'S') printf("%.1f\n", soma);
    else printf("%.1f\n", soma/30);

	return 0; 
}