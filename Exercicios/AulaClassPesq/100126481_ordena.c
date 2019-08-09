#include <stdio.h>

int main () {
	int i, vet[10], flag, aux;

	printf("\n");
	for(i=0;i<10;i++) {
		printf("Digite o numero %d do vetor: ",i+1);
		scanf("%d",&vet[i]);
	}
	
	do {
		flag = 0;
		for(i=0;i<10;i++) {
			if(vet[i]>vet[i+1]) {
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				flag = 1;
			}
		}
	} while(flag==1);

	
	printf("\nO vetor ordenado e: ");
	for(i=0;i<10;i++)
		printf("%d ",vet[i]);
	
	getchar();
	getchar();
	return 0;
}
