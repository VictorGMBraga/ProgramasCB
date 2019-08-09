/*Lê o custo de fábrica de um carro e mostra o custo ao consumidor, incluindo a porcentagem do distribuidor de 28% e os impostos de 45%*/

#include <stdio.h>

int main ()
{
	float custofab,custocons;
	
	printf("\nDigite o custo de fabrica: ");
	scanf("%f",&custofab);
	custocons=custofab*1.73;
	printf("Custo ao consumidor: %.2f\n",custocons);
	return 0;
}
