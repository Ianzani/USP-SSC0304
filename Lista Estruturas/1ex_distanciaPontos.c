// Authors: LDFranck & domingues100

#include <stdio.h>
#include <math.h>

typedef struct _ponto{
	float x;
	float y;
}ponto;

float distancia(ponto a, ponto b){
	return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
}

int main(){
	ponto a, b;

	scanf("%f %f", &a.x, &a.y);
	scanf("%f %f", &b.x, &b.y);

	printf("%.2f\n", distancia(a,b));

	return 0;
}
