// Authors: LDFranck & domingues100

#include <stdio.h>
#include <math.h>

int main(){
    
    
    int a, b, c;
    double r1, atri, r2, acp, acg, p;
    
	while(scanf("%d %d %d", &a, &b, &c) != EOF){   
		
		p = (a+b+c)/2.0;
		atri = sqrt(p*(p-a)*(p-b)*(p-c));
		r2 = (2*atri)/(a+b+c); 
		acp = 3.1415926535897*r2*r2;
		r1 = (a*b*c)/(4*atri);
		acg = 3.1415926535897*r1*r1;


		printf("%.4lf ", (acg-atri));
		printf("%.4lf ", (atri-acp));
		printf("%.4lf\n", acp);
	
	}    
    
	return 0;
}