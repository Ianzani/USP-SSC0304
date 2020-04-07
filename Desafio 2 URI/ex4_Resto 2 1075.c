// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int num, c;
	
	scanf("%d", &num);
	
	for(c=0; c<10000; c++)
		if((c%num)==2)printf("%d\n", c);
 
    return 0;
}