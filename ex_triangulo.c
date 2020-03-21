// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>

int main (void) {
	
	int ladosTri[3], auxVar;
	char auxPos;
	
	while(1){
		
		printf("Insira o tamanho dos lados do triangulo (A,B,C): ");
		scanf("%d,%d,%d", &ladosTri[0], &ladosTri[1], &ladosTri[2]);
		
		auxPos = (ladosTri[0]>ladosTri[1])?0:1;
		auxPos = (ladosTri[auxPos]>ladosTri[2])?auxPos:2;
		
		auxVar = ladosTri[0];
		ladosTri[0] = ladosTri[auxPos];
		ladosTri[auxPos] = auxVar;
		
		if(ladosTri[0]<(ladosTri[1]+ladosTri[2]))break;
		printf("Valores invalidos...\n");
	}
	
	printf("Esse e um triangulo ");
	
	if((ladosTri[0]*ladosTri[0])==((ladosTri[1]*ladosTri[1])+(ladosTri[2]*ladosTri[2])))printf("RETANGULO ");
	else if((ladosTri[0]*ladosTri[0])>((ladosTri[1]*ladosTri[1])+(ladosTri[2]*ladosTri[2])))printf("OBTUSANGULO ");
	else printf("ACUTANGULO ");
	
	if(ladosTri[0]==ladosTri[1] && ladosTri[1]==ladosTri[2])printf("EQUILATERO\n");
	else if (ladosTri[0]!=ladosTri[1] && ladosTri[0]!=ladosTri[2] && ladosTri[1]!=ladosTri[2])printf("ESCALENO\n");
	else printf("ISOSCELES\n");
	
	system("pause");
}