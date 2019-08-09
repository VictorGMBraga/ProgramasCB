#include <stdio.h>
#include <math.h>

int main ()
{
	float cat1,cat2,hipot;
	
	printf("\nDigite o cateto 1: ");
	scanf("%f",&cat1);
	printf("Digite o cateto 2: ");
	scanf("%f",&cat2);
	hipot=sqrt((cat1*cat1)+(cat2*cat2));
	printf("\nA hipotenusa vale: %.2f\n",hipot);
	return (0);
}
