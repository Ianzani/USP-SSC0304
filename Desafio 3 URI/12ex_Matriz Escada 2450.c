// Authors: LDFranck & domingues100

#include <stdio.h>
 
int main() {
 
	int lin, col;
	int c1, c2, c3;
	
	scanf("%d %d", &lin, &col);
	
	int matriz[lin][col];
	
	for(c1=0; c1<lin; c1++)
		for(c2=0; c2<col; c2++)scanf("%d", &matriz[c1][c2]);
	
	c1=0; c2=0;
	while(c1<lin && c2<col){
		for(c3=c1+1;c3<lin;c3++)if(matriz[c3][c2]){printf("N\n"); return 0;}
		if(matriz[c1][c2])c1++;
		c2++;
	}
	printf("S\n");
	
    return 0;
}