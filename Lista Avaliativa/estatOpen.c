// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

int main(){
	float vetor[2][5];

	FILE *p = fopen("estat.bin", "rb");
	fread(vetor, sizeof(vetor), 1, p);
	fclose(p);

	printf("%.2f %.2f %.2f %.2f %.0f%%\n", vetor[0][0], vetor[0][1], vetor[0][2], vetor[0][3], vetor[0][4]);
	printf("%.2f %.2f %.2f %.2f %.0f%%\n", vetor[1][0], vetor[1][1], vetor[1][2], vetor[1][3], vetor[1][4]);

	return 0;
}
