#include <stdio.h>

int somapares (int num) {
	int i, result = 0;
	
	if(num%2!=0) {
		num -= 1;
	}
	for(i=2; i<=num; i += 2) {
		result += i;
	}
	return(result);
}

int main () {
    int num, inv = 0;
	
	printf("\n");
	do {
		if(inv)
			printf("Numero negativo!\n");
		printf("Informe o numero: ");
		scanf("%d",&num);
	} while(num<=0);
	
	printf("\nA soma dos pares menores ou iguais a %d e %d.",num,somapares(num));
	
	getchar();
	getchar();
    return(0);
}
