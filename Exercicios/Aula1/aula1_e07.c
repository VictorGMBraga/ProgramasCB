#include <stdio.h>
#include <math.h>

int main ()
{
	float a,b,c,x1,x2,d;
	
	printf("\nDigite um valor para a: ");
	scanf("%f",&a);
	printf("Digite um valor para b: ");
	scanf("%f",&b);
	printf("Digite um valor para c: ");
	scanf("%f",&c);
	d=(b*b)-(4*a*c);
	x1=((-b)+sqrt(d))/(2*a);
	x2=((-b)-sqrt(d))/(2*a);
	printf("\nA raiz x1 vale: %.2f\n",x1);
	printf("A raiz x2 vale: %.2f\n",x2);
	return (0);
}
