// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int vel, horas;
	
	scanf("%d", &horas);
	scanf("%d", &vel);
	
	printf("%.3f\n", horas*vel/12.0);
 
    return 0;
}
