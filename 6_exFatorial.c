#include <stdio.h>
#include <stdlib.h>

int fatorial(int var){
	return (var<=1)?1:var*(fatorial(var-1));
}

int main(){
	
	int num;

	printf("Digite um numero inteiro: ");
	scanf("%d", &num);
	
	printf("%d! = %d\n", num, fatorial(num));
	
	system("pause");
}