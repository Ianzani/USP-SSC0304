// Authors: LDFranck & domingues100

#include <stdio.h>
 
int main() {
 
	long long int varI, varJ, ordemM;
	long long int varP, varQ, varR, varS, varX, varY;
	long long int c1, resultado=0;
	
	scanf("%lli", &ordemM);
	scanf("%lli %lli %lli %lli %lli %lli", &varP, &varQ, &varR, &varS, &varX, &varY);
	scanf("%lli %lli", &varI, &varJ);
	
	long long int matriz[ordemM][2];
	
	for(c1=0; c1<ordemM; c1++)matriz[c1][0] = (varP*(varI)+varQ*(c1+1))%varX;
	
	for(c1=0; c1<ordemM; c1++)matriz[c1][1] = (varR*(c1+1)+varS*(varJ))%varY;
	
	for(c1=0; c1<ordemM; c1++)resultado+=matriz[c1][0]*matriz[c1][1];
	
	printf("%lli\n", resultado);
	
	return 0;
}