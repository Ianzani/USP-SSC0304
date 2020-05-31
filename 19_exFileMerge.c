// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

int isDiff(FILE* pA, FILE* pB, int* lin, int* col){
	char aux;
	(*lin) = 0;
	(*col) = 0;

	while (!feof(pA) && !feof(pB)) {
		if(aux = fgetc(pA), aux == fgetc(pB)){
			(*col)++;
			if(aux == '\n'){
				(*col) = 0;
				(*lin)++;
			}
		} else return 1;
	}
	return 0;
}

void mergeFiles(FILE *pA, FILE *pB, FILE *pC){
	char aux;

	rewind(pA);
	rewind(pB);
	while (aux = fgetc(pA), aux != EOF)fputc(aux, pC);
	while (aux = fgetc(pB), aux != EOF)fputc(aux, pC);
}

int main(){
	int lin, col;
	FILE *pA, *pB, *pC;

	pA = fopen("arq1.txt", "r");
	pB = fopen("arq2.txt", "r");
	pC = fopen("arq3.txt", "w");

	if(isDiff(pA, pB, &lin, &col)){
		printf("Diferentes; lin: %d col: %d.\n", lin+1, col+1);
	} else printf("Iguais.\n");

	mergeFiles(pA, pB, pC);

	fclose(pA);
	fclose(pB);
	fclose(pC);
	return 0;
}
