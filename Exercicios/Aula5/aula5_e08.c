#include <stdio.h>

int main () {
	int i, i2, i3=0, i4=0, vet1[10], vet2[10], vetu[20], veti[10];

	printf("\n");
	for(i=0;i<10;i++) {
		printf("Digite o numero %d do vetor 1: ",i+1);
		scanf("%d",&vet1[i]);
	}
	printf("\n");
	for(i=0;i<10;i++) {
		printf("Digite o numero %d do vetor 2: ",i+1);
		scanf("%d",&vet2[i]);
	}
	
	for(i=0;i<10;i++){
		i2=0;
		while((vet2[i2]!=vet1[i])&&(i2<9)) {
			i2++;
		}
		if(vet2[i2]==vet1[i]) {
			veti[i3]=vet1[i];
			i3+=1;
			vetu[i4]=vet1[i];
			i4+=1;
		}
		else {
			vetu[i4]=vet1[i];
			i4+=1;
			vetu[i4]=vet2[i2];
			i4+=1;
		}
	}
		
	printf("\nUniao: ");
	for (i=0;i<i4;i++)
		printf("%d ",vetu[i]);	
	printf("\nInterseccao: ");
	for (i=0;i<i3;i++)
		printf("%d ",veti[i]);	
		
	getchar();
	getchar();
	return 0;
}
