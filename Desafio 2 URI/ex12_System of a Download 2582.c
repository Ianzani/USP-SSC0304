// Author: LDFranck

#include <stdio.h>
 
int main() {
 
	int ent, num1, num2, c;
	char musicas[11][15] = 
	{"PROXYCITY", "P.Y.N.G.", "DNSUEY!",
	 "SERVERS", "HOST!", "CRIPTONIZE",
	 "OFFLINE DAY", "SALT", "ANSWER!", "RAR?", "WIFI ANTENNAS"};
	
	scanf("%d", &ent);

	for(c=0; c<ent; c++){
		
		scanf("%d %d", &num1, &num2);
		printf("%s\n", musicas[num1+num2]);
		
	}
 
    return 0;
}