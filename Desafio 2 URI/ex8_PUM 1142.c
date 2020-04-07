// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int quant, c, i=1;
	
	scanf("%d", &quant);
	
	for(c=0; c<quant; c++){
		for(;i<(c*4+4);i++)printf("%d ", i);
		i++;
		printf("PUM\n");
	}
 
    return 0;
}