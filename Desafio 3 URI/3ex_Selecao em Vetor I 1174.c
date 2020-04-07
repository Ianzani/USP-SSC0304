// Authors: LDFranck & domingues100

#include <stdio.h>
 
int main() {
 
	float vetor[100];
	int c;
	
	for(c=0; c<100; c++)scanf("%f", &vetor[c]);
	for(c=0; c<100; c++)if(vetor[c]<=10)printf("A[%d] = %.1f\n",c,vetor[c]);
 
    return 0;
}