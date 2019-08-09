#include <stdio.h>

int fibon (int n) {
	if (n==0) {
		return(0);
	}
	else if (n==1) {
		return(1);
	}
	else {
		return(fibon(n-1)+fibon(n-2));
	}
}


int main() {
	int n;

	printf("\nInforme n para calcular a serie de Fibonacci: ");
	scanf("%d",&n);
	getchar();
	
	printf("\nA serie de Fibonacci para %d vale: %d",n,fibon(n));
	
	getchar();
	return(0);
}
