#include <stdio.h>

int main () {
	int i, num, vet[10], flag = 0;

	printf("\n");
	for(i=0;i<10;i++) {
		printf("Digite o numero %d do vetor: ",i+1);
		scanf("%d",&vet[i]);
	}
	printf("\nDigite o numero que deseja encontrar: ");
	scanf("%d",&num);
	
	i = 0;
	do {
		if(vet[i]==num)
			flag = 1;
		i++;
	} while((i<10)&&(flag==0));
	
	if(flag==1)
		printf("\nO numero %d foi encontrado na posicao %d do vetor.",num,i);
	else
		printf("\nO numero %d NAO foi encontrado no vetor.",num);
		
	getchar();
	getchar();
	return 0;
}
