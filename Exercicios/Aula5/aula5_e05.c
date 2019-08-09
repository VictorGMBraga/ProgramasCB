#include <stdio.h>

int main () {
    int i, vet[9];

	printf("\n");
	for(i=0; i<9; i++) {
		printf("Digite o numero %d: ",i+1);
		scanf("%d",&vet[i]);
	}
	
	printf("\n");
	for(i=0; i<9; i++) {
		if(vet[i]<0)
			printf("O numero negativo %d esta na posicao %d.\n",vet[i],i+1);
	}

	getchar();
	getchar();
	return 0;
}
