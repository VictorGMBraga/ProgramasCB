#include <stdio.h>

int main ()
{
	float n1,n2,n3,p1,p2,p3,media;
	
	printf("\nDigite a nota 1: ");
	scanf("%f",&n1);
	printf("Digite o peso da nota 1: ");
	scanf("%f",&p1);
	printf("Digite a nota 2: ");
	scanf("%f",&n2);
	printf("Digite o peso da nota 2: ");
	scanf("%f",&p2);
	printf("Digite a nota 3: ");
	scanf("%f",&n3);
	printf("Digite o peso da nota 3: ");
	scanf("%f",&p3);
	media=((n1*p1)+(n2*p2)+(n3*p3))/(p1+p2+p3);
	printf("\nA media final vale: %.1f\n",media);
	return (0);
}
