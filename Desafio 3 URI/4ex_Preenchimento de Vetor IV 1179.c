// Authors: LDFranck & domingues100

#include <stdio.h>
 
int main(){
 
	int entrada, par[5]={0}, impar[5]={0}, cont, cP=0, cI=0;
	
	for(cont = 0; cont<15; cont++){
	
		scanf("%d", &entrada);
	
		if(entrada%2){
			impar[cI++]=entrada;
			if(cI==5){
				for(cI=0; cI<5; cI++)printf("impar[%d] = %d\n",cI, impar[cI]);
				cI=0;
			}	
		}else{
			par[cP++]=entrada;
			if(cP==5){
				for(cP=0; cP<5; cP++)printf("par[%d] = %d\n",cP, par[cP]);
				cP=0;
			}
		
		}
	}
	
	for(cont=0; cont<cI; cont++)printf("impar[%d] = %d\n",cont, impar[cont]);
	for(cont=0; cont<cP; cont++)printf("par[%d] = %d\n",cont, par[cont]);
 
    return 0;
}