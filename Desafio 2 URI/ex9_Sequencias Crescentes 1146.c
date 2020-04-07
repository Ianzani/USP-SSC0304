// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int num, c;
	
	while(1){
		
		scanf("%d", &num);
		if(!num)break;
		for(c=1; c<num; c++)printf("%d ", c);
		printf("%d\n", c);
		
	}
 
    return 0;
}