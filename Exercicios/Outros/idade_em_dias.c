/*Lê uma idade em dias, meses e anos e a mostra apenas em dias*/

#include <stdio.h>

int main ()
{
	int anos,meses,dias,idade_d;
	
	printf("\nDigite os anos: ");
	scanf("%d",&anos);
	printf("Digite os meses: ");
	scanf("%d",&meses);
	printf("Digite os dias: ");
	scanf("%d",&dias);
	idade_d=(anos*365)+(meses*30)+dias;
	printf("A idade em dias vale: %d\n",idade_d);
	return 0;
}
