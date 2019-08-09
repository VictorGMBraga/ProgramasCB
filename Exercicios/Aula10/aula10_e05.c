#include <stdio.h>

int soma (int n) {
	if (n==1) {
		return(1);
	}
	else {
		return(n+soma(n-1));
	}
}


int main() {
	int n;

	printf("\nInforme n para calcular a soma de todos os numeros ate n: ");
	scanf("%d",&n);
	getchar();
	
	printf("\nA soma ate %d vale: %d",n,soma(n));
	
	getchar();
	return(0);
}
