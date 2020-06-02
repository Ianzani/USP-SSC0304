// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char arqNome[] = "historico.log";
	char dataHora[] = "2020-23-05 10:20";
	char arqInfo[51];
	FILE *pArquivo = fopen(arqNome, "r");

	if(!pArquivo){
		printf("Arquivo '%s' nao encontrado.\n", arqNome);
		exit(EXIT_FAILURE);
	}

	while (!feof(pArquivo)) {
		fscanf(pArquivo, "%50[^\n]", arqInfo);
		fgetc(pArquivo);
		if(!strcmp(dataHora, strtok(arqInfo, ";"))){
			printf("user: %s\n", strtok(NULL, ";"));
			printf("os: %s\n", strtok(NULL, "\n"));

			fclose(pArquivo);
			return 0;
		}
	}
	printf("Acesso nao encontrado.\n");

	fclose(pArquivo);
	return 0;
}
