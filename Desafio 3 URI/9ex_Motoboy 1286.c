// Authors: LDFranck & domingues100

#include <stdio.h>

/*******************************************************************
Capacidade: 2 
	valor  peso
n0	 10 	1    
n1	 20 	1    
n2	 30 	1    

chama funcao(2,3)
qual é maior? com o n2 ou sem? respectivamente
maior(funcao(2-1, 3-1)+30 ou funcao(2, 2))
			20+30	ou			30			= 50

	chamada funcao(1, 2)
	qual é maior? com o n1 ou sem? respectivamente
	maior(funcao(1-1,2-1)+20 ou funcao(2,1))
				0+20	ou		10			= 20
	
		chamada funcao(0,1)
		retorna 0, mochila cheia, não acrescenta valor
		
		chamada funcao(2,1)
		qual é maior? com o n0 ou sem? respectivamente
		maior(funcao(2-1,1-1)+10 ou funcao(2,0))
					0+10	ou		0			= 10
		
			chamada funcao(1,0)
			retorna 0, não tem mais itens, não acrescenta valor
			
			chamada funcao(2,0)
			retorna 0, não tem mais itens, não acrescenta valor
	
	chamada funcao(2,2)
	qual é maior? com o n1 ou sem? respectivamente
	maior(funcao(2-1,2-1)+20 ou funcao(2,1))
				10+20	ou		10			= 30
	
		chamada funcao(1,1)
		qual é maior? com o n0 ou sem? respectivamente
		maior(funcao(1-1,1-1)+10 ou funcao(2,0))
					0+10	ou		0			= 10
					
			chamada funcao(0,0)
			retorna 0, não tem mais itens, não acrescenta valor
			
			chamada funcao(2,0) 
			retorna 0, não tem mais itens, não acrescenta valor
			
		chamada funcao(2,1)
		qual é maior? com o n0 ou sem? respectivamente
		maior(funcao(2-1,1-1)+10 ou funcao(2,0))
					0+10	ou		0			= 10
					
			chamada funcao(1,0)
			retorna 0, não tem mais itens, não acrescenta valor
			
			chamada funcao(2,0)
			retorna 0, não tem mais itens, não acrescenta valor

*******************************************************************/
	
int knapsackAlg(int capPizza, int nPedidos, int matriz[][2]){
	
	if(!capPizza || !nPedidos)return 0;
	if(matriz[nPedidos-1][1]>capPizza)return knapsackAlg(capPizza, nPedidos-1 , matriz);
	
	int opcao1, opcao2;
			
	opcao1 = knapsackAlg(capPizza-matriz[nPedidos-1][1], nPedidos-1 , matriz) + matriz[nPedidos-1][0];
	opcao2 = knapsackAlg(capPizza, nPedidos-1 , matriz);
	
	return (opcao1>opcao2)?opcao1:opcao2;
}

int main (){
	
	int nPedidos, capPizza, c1;
	
	while(1){
	
		scanf("%d", &nPedidos);
		if(!nPedidos)return 0;
		scanf("%d", &capPizza);
		
		int matrizPP[nPedidos][2];
		
		for(c1=0; c1<nPedidos; c1++)scanf("%d %d", &matrizPP[c1][0], &matrizPP[c1][1]);
			
		printf("%d min.\n", knapsackAlg(capPizza, nPedidos, matrizPP));
	
	}
}
	