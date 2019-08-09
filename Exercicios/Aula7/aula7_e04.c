#include <stdio.h>

void bubsrt (int vet[]) {
	int flag, aux, i;
	
	do {
		flag = 0;
		for(i=0; i<10; i++) {
			if(vet[i]>vet[i+1]) {
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				flag = 1;
			}
		}
	} while(flag);
}

int binsrch (int vet[], int num) {
	int flag = 0, inicio = 0, meio, fim = 9;
	
	do {
		meio=(fim+inicio)/2;
		if(vet[meio]>num) {
			fim = meio-1;
		}
		else {
			if(vet[meio]<num) {
				inicio = meio+1;
			}
			else {
				flag = 1;
			}
		}
	} while((flag==0)&&(inicio<=fim));
		
	if(flag==1) {
		return(meio+1);
	}
	else {
		return(-1);
	}		
}

void printvet (int vet[]) {
	int i;
	
	for(i=0; i<10; i++) {
		printf("%d ",vet[i]);
	}
}

int main () {
    int vets[3][10], procura[3];
	int i, i2;

	for(i=0; i<3; i++) {
		printf("\n");
		for(i2=0; i2<10; i2++) {
			printf("Informe o elemento %d do vetor %d: ",i2+1,i+1);
			scanf("%d",&vets[i][i2]);
		}
	}
	
	printf("\n");
	for(i=0; i<3; i++) {
		printf("Informe o numero que deseja encontrar no vetor %d: ",i+1);
		scanf("%d",&procura[i]);
	}

	for(i=0; i<3; i++) {
		bubsrt(vets[i]);
		printf("\nO vetor %d ordenado e:\n",i+1);
		printvet(vets[i]);
	}
	
	printf("\n");
	for(i=0; i<3; i++) {
		if(binsrch(vets[i],procura[i])!=-1) {
			printf("\nO numero %d foi encontrado no vetor %d ordenado na posicao %d.",procura[i],i+1,binsrch(vets[i],procura[i]));
		}
		else {
			printf("\nO numero %d nao foi encontrado no vetor %d.",procura[i],i+1);
		}
	}
	
	getchar();
	getchar();
    return(0);
}
