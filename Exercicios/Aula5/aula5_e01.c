#include <stdio.h>

int main () {
    int i, W[5];

    printf("\n");
	for (i=0; i<5; i++) {
		printf("Digite o numero %d: ",i+1);
		scanf("%d",&W[i]);
	}
	
	printf("\n");
	for  (i=0; i<5; i++) {
	printf("O valor armazenado em W[%d] e: %d \n",i+1,W[i]);
	}
	
	getchar();
	getchar();
	return 0;
}
