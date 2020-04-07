// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int num, entrada, c;
	
	scanf("%d", &num);
	
	for(c=0; c<num; c++){
		
		scanf("%d", &entrada);
		
		if(!entrada){
			printf("NULL\n");
			continue;
		}
		
		printf("%s ", (entrada%2)?"ODD":"EVEN");
		printf("%s\n", (entrada>0)?"POSITIVE":"NEGATIVE");
	}
 
    return 0;
}
