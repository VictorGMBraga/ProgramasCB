#include <stdio.h>

int mdc (int x, int y) {
	if ((x>=y)&&(x%y==0)) {
		return(y);
	}
	else if(x<y) {
		return(mdc(y,x));
	}
	else {
		return(mdc(y,x%y));
	}
}


int main() {
	int x, y;

	printf("\nInforme x e y para calcular o MDC:\n");
	scanf("%d",&x);
	getchar();
	scanf("%d",&y);
	getchar();
	
	printf("\nO MDC de %d e %d vale: %d",x,y,mdc(x,y));
	
	getchar();
	return(0);
}
