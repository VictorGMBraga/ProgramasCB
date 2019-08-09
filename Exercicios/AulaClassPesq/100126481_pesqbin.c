#include <stdio.h>

int main () {
	int i, num, vet[10], flag, fim = 9, meio, aux;

	printf("\n");
	for(i=0;i<10;i++) {
		printf("Digite o numero %d do vetor: ",i+1);
		scanf("%d",&vet[i]);
	}
	printf("\nDigite o numero que deseja encontrar: ");
	scanf("%d",&num);
	
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
	
	i = 0;
	do {
		meio=(fim+i)/2;
		if(vet[meio]>num)
			fim = meio-1;
		else {
			if(vet[meio]<num)
				i = meio+1;
			else
				flag = 1;
		}
	} while((flag==0)&&(i<=fim));
	
	if(flag==1)
		printf("\nO numero %d foi encontrado na posicao %d do vetor ordenado.",num,meio+1);
	else
		printf("\nO numero %d NAO foi encontrado no vetor.",num);
		
	getchar();
	getchar();
	return 0;
}
