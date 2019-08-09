#include <stdio.h>

int fat (int n) {
	if (n==0) {
		return(1);
	}
	else {
		return(n*fat(n-1));
	}
}


int main() {
	int n;

	printf("\nInforme n para calcular n fatorial: ");
	scanf("%d",&n);
	getchar();
	
	printf("\n%d fatorial vale: %d",n,fat(n));
	
	getchar();
	return(0);
}
