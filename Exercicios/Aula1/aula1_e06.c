#include <stdio.h>

int main ()
{
    const float pi=3.14;
	float r,h,v;
	
	printf("\nDigite o raio do cilindro: ");
	scanf("%f",&r);
	printf("Digite a altura do cilindro: ");
	scanf("%f",&h);
	v=pi*r*r*h;
	printf("\nA volume do cilindro vale: %.2f\n",v);
	return (0);
}
