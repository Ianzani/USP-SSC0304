// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int quant, num1, num2, c;
	
	scanf("%d", &quant);
	
	for(c=0; c<quant; c++){
	
		scanf("%d %d", &num1, &num2);
		
		if(!num2)printf("divisao impossivel\n");
		else printf("%.1f\n", (float)num1/num2);
		
	}
 
    return 0;
}
