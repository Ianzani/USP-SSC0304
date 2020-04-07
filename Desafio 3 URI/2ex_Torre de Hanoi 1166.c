// Authors: LDFranck & domingues100

#include <stdio.h>
#include <math.h>

char isPerfSq(float num){
	
	float aux1;
	int aux2;
	
	aux1=sqrt(num);
	aux2=aux1;
	
	return (aux1-aux2)?0:1;
}

int main(){
	
	int nEntradas, contBola, nVaretas, c1;
	
	scanf("%d", &nEntradas);
	
	while(nEntradas>0){
		
		scanf("%d", &nVaretas);
		
		int mat[nVaretas];
		contBola=1;
		
		for(c1=0; c1<nVaretas; c1++)mat[c1]=0;
		
		c1=0;
		while(c1<nVaretas){
			
			if(!mat[c1]){mat[c1]=contBola++; c1=0;}
			else{
				if(isPerfSq(mat[c1]+contBola)){mat[c1]=contBola++; c1=0;}
				else c1++;
			}
		}
		printf("%d\n", contBola-1);
		
		nEntradas--;
	}		
}