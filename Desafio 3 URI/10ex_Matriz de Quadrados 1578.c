// Authors: LDFranck & domingues100

#include <stdio.h>
 
void quadradoMat();
 
int main(){
 
	char num;

	scanf("%d", &num);
	
	for(; num>0; num--){
		quadradoMat();
		if(num>1)printf("\n");
	}
	
    return 0;
}

void quadradoMat(){
	
	static char nMat = 4;
	char ordem, c1, c2;
	
	scanf("%d", &ordem);
	
	unsigned long long int aux;
	unsigned long long int matriz[ordem][ordem];
	char indexMaior[ordem];
		
	for(c1=0; c1<ordem; c1++)
		for(c2=0; c2<ordem; c2++){
			scanf("%llu", &matriz[c1][c2]);
			matriz[c1][c2] *= matriz[c1][c2];
		}
	
	for(c1=0; c1<ordem; c1++)indexMaior[c1]=0; 

	for(c2=0; c2<ordem; c2++)
		for(c1=0; c1<ordem; c1++)indexMaior[c2]=(matriz[indexMaior[c2]][c2]>matriz[c1][c2])?indexMaior[c2]:c1;

	for(c2=0; c2<ordem; c2++){
		aux = matriz[indexMaior[c2]][c2];
		c1=0;
		while(aux){aux/=10; c1++;}
		indexMaior[c2] = c1;
	}
	
	printf("Quadrado da matriz #%d:\n", nMat++);
	
	for(c1=0; c1<ordem; c1++)
		for(c2=0; c2<ordem; c2++)printf("%*llu%c", indexMaior[c2], matriz[c1][c2], (c2<ordem-1)?' ':'\n'); 
}