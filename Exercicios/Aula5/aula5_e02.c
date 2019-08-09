#include <stdio.h>

int main () {
    int i, par = 0, impar = 0, vet[6];

    printf("\n");
	for(i=0; i<6; i++) {
		printf("Digite o numero %d: ",i+1);
		scanf("%d",&vet[i]);
	}
	
	printf("\n");
	for(i=0; i<6; i++) {
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
