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

int main () {
    int vets[5][10];
	int i, i2;

	for(i=0; i<5; i++) {
		printf("\n");
		for(i2=0; i2<10; i2++) {
			printf("Informe o elemento %d do vetor %d: ",i2+1,i+1);
			scanf("%d",&vets[i][i2]);
		}
	}
		
	for(i=0; i<5; i++) {
		bubsrt(vets[i]);
	}
	
	printf("\n");
	for(i=0; i<5; i++) {
		for(i2=0; i2<10; i2++) {
			printf("%d  ",vets[i][i2]);
		}
		printf("\n");
	}
	
	getchar();
	getchar();
    return(0);
}
