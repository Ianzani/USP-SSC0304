// Authors: LDFranck & domingues100

#include <stdio.h>
#include <math.h>

int main(){
   
   int eV1, eV2, dD, aT;
   float prob, p1, p2, x, n1, n2;

   scanf("%d %d %d %d", &eV1, &eV2, &aT, &dD);

   while(eV1!=0 && eV2!=0 && dD!=0 && aT!=0){

		n1 = eV1/dD;
		if(eV1%dD)n1++;

		n2 = eV2/dD;
		if(eV2%dD)n2++;
      
		if(aT==3)prob = (float)(n1/(n1+n2));

    else{
		
		p1 = (float)(aT/6.0);
        p2 = (float)(1.0-(aT/6.0));
        x = p2/p1;
        prob = (float)((1-(pow(x,n1)))/(1-(pow(x,(n1+n2)))));
	}
		
	printf("%.1f\n", (prob*100));
    scanf("%d %d %d %d", &eV1, &eV2, &aT, &dD);
   }
   
	return 0;
}