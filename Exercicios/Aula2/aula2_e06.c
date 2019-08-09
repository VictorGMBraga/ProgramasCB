#include <stdio.h>
#include <math.h>

int main ()
{
	float l1,l2,l3;
       
	printf("\nInforme o valor 1: ");
	scanf("%f",&l1);
	printf("Informe o valor 2: ");
	scanf("%f",&l2);
	printf("Informe o valor 3: ");
	scanf("%f",&l3);
	if (l1<(l2+l3)&&l2<(l1+l3)&&l3<(l1+l2)) 
	{
		if (pow(l1,2)==pow(l2,2)+pow(l3,2) || pow(l2,2)==pow(l1,2)+pow(l3,2) || pow(l3,2)==pow(l1,2)+pow(l2,2))
			printf("\nOs valores formam um triangulo retangulo.\n");
		else
			printf("\nOs valores formam um triangulo nao retangulo.\n"); 
	}
	else
		printf("\nOs valores nao formam um triangulo.\n");
	return(0);
}
