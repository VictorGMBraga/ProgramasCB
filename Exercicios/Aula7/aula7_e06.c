#include <stdio.h>

void bubsrt (int vet[], int tam) {
	int flag, aux, i;
	
	do {
		flag = 0;
		for(i=0; i<tam; i++) {
			if(vet[i]>vet[i+1]) {
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				flag = 1;
			}
		}
	} while(flag);
}

int binsrch (int vet[], int fim, int num) {
	int flag = 0, inicio = 0, meio;
	
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
		return(1);
	}
	else {
		return(0);
	}
}

int main () {
    int i, vet[50], achar[10], achou[10];
	
	printf("\n");
	for(i=0; i<50; i++) {
		printf("Informe o elemento %d do vetor: ",i+1);
		scanf("%d",&vet[i]);
	}
	printf("\n");
	for(i=0; i<10; i++) {
		printf("Informe o elemento %d que deseja achar: ",i+1);
		scanf("%d",&achar[i]);
	}
	
	bubsrt(vet,50);
	for(i=0; i<10; i++) {
		achou[i] = binsrch(vet,50,achar[i]);
	}
	
	printf("\nOs numeros achados no vetor foram: ");
	for(i=0; i<10; i++) {
		if(achou[i]) {
			printf("%d ",achar[i]);
		}
	}
	
	getchar();
	getchar();
    return(0);
}
