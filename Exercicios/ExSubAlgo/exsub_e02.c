#include <stdio.h>
#include <math.h>

float delta (float *a, float *b, float *c) {
	return(((*b)*(*b))-(4*(*a)*(*c)));
}

void r2grau (float *a, float *b, float *c, float *r1, float *r2) {
	*r1 = (-*b+sqrt(delta(&*a,&*b,&*c)))/2*(*a);
	*r2 = (-*b-sqrt(delta(&*a,&*b,&*c)))/2*(*a);
}

int main () {
	float a, b, c;
	float r1, r2;
	
	printf("\nInforme a: ");
	scanf("%f",&a);
	printf("Informe b: ");
	scanf("%f",&b);
	printf("Informe c: ");
	scanf("%f",&c);
	
	if((delta(&a,&b,&c)>0)||(delta(&a,&b,&c)==0)) {
		r2grau(&a,&b,&c,&r1,&r2);
		if(r1==r2) {
			printf("\nRaiz: %f",r1);
		}
		else {
			printf("\nRaizes: %.1f, %.1f",r1,r2);
		}
	}
	else {
		printf("\nNao existem raizes reais.");
	}
	
	getchar();
	getchar();
	return(0);
}
