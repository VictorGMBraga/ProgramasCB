/***
Mostra na tela o valor de n fatorial e repete esse cáculo um número t de vezes, sendo n e t informados pelo usuário.
***/

#include <stdio.h>

int main(){
	int i,i2,t,n,fat;
	
	printf("\nInforme o valor de t: ");
	scanf("%d",&t);
	while(t<1){
		printf("\nApenas valores maiores que 0!");
		printf("\nInforme o valor de t: ");
		scanf("%d",&t);
	}
	for(i=1;i<=t;i++){
		printf("\nInforme um valor para n: ");
		scanf("%d",&n);
		while(n<0){
			printf("\nApenas valores maiores ou iguais a 0!");
			printf("\nInforme um valor para n: ");
			scanf("%d",&n);
		}
		if (n==0)
			fat=1;
		else{
			fat=1;
			for (i2=1;i2<=n;i2++)
				fat*=i2;
		}
		printf("\nO valor de %d fatorial e: %d\n\n",n,fat);
	}
	getchar();
	getchar();
	return(0);
}
