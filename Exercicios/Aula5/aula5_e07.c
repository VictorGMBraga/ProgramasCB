#include <stdio.h>

int main () {
	int i, i2, vet[10];

	printf("\n");
	for (i = 0;i < 10;i++) {
		printf("Digite o numero %d: ",i+1);
		scanf("%d", &vet[i]);
	}
	
	for(i=0;i<10;i++) {
		if(((vet[i]==0)||(vet[i]==-1))&&(i<9)) {
			i2=i+1;
			while(((vet[i2]==0)||(vet[i2]==-1))&&(i2<9))
				i2+=1;
			vet[i]=vet[i2];
			vet[i2]=-1;
		}
	}
	
	printf("\n");
	for(i=0;i<10;i++) {
		if(vet[i]!=-1)
			printf("%d ",vet[i]);
	}
	
	getchar();
	getchar();
	return 0;
}
