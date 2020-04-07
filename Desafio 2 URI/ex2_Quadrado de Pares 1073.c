// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int num, c;
	
	scanf("%d", &num);
	
	for(c=1; c<=num; c++)if(!(c%2))printf("%d^2 = %d\n", c, c*c);
 
    return 0;
}