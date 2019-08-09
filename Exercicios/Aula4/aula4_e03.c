/***
Imprime na tela o somatório de i, com i variando de 1 a k.
O valor de k é dado pelo usuário e o programa se repete até que um valor negativo seja fornecido.
***/

#include <stdio.h>

int main(){
	int i,k,som;
	
	printf("*Se desejar finalizar o programa a qualquer momento, informe um valor negativo*\n\n");
	do{
		printf("\nInforme um valor para k: ");
		scanf("%d",&k);
		som=0;
		for(i=1;i<=k;i++)
			som+=i;
		if(k>0)
			printf("\nO somatorio de i, com i variando de 1 a %d, vale: %d.\n\n",k,som);
	}while(k>0);
	return(0);
}
