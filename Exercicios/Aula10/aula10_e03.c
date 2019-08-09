#include <stdio.h>

int pot (int x, int y) {
	if (y==0) {
		return(1);
	}
	else {
		return(x*pot(x,y-1));
	}
}


int main() {
	int x, y;

	printf("\nInforme x e y para calcular x^y:\n");
	scanf("%d",&x);
	getchar();
	scanf("%d",&y);
	getchar();
	
	printf("\n%d^%d vale: %d",x,y,pot(x,y));
	
	getchar();
	return(0);
}
