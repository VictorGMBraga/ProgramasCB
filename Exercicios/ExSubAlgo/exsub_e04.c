#include <stdio.h>

float pow (float a, float b) {
	int i, result;
	
	if(b==0) {
		return(1);
	}
	else {
		result = a;
		for(i=1; i<b; i++) {
			result *= a;
		}
		return(result);
	}
}

int main () {
	float n, n2;
	
	printf("\nInforme X: ");
	scanf("%f",&n);
	printf("Informe Y: ");
	scanf("%f",&n2);
	
	printf("\nX elevado a Y e: %.2f",pow(n,n2));
	
	getchar();
	return(0);
}
