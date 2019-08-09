#include <stdio.h>

int main () {
    int i, n, par = 0, impar = 0, vet[20];

    printf("\n");
	do {
		if(n<=0)
			printf("Apenas valores maiores que 0!\n");
		if(n>20)
			printf("O valor maximo e 20!\n");
		printf("Informe a quantidade de numeros: ");
		scanf("%d",&n);
	} while((n>20)||(n<=0));
	
	printf("\n");
	for(i=0; i<n; i++) {
		printf("Digite o numero %d: ",i+1);
		scanf("%d",&vet[i]);
	}
	
	printf("\n");
	for(i=0; i<n; i++) {
		if(vet[i]%2==0)
			par+=1;
		else
			impar+=1;
	}
	
	printf("\nNumeros pares: %d\nNumeros impares: %d",par,impar);
	getchar();
	getchar();
	return 0;
}
