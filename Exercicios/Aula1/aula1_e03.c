#include <stdio.h>

int main ()
{
	char nome[50],end[50];
	int idade;
	
	printf("\nDigite seu nome: ");
	scanf("%s",&nome);
	printf("Digite sua idade: ");
	scanf("%d",&idade);
	printf("Digite seu endereco: ");
	scanf("%s",&end);
	printf("\nOla, %s. Voce tem %d anos de idade e seu endereco e: %s.\n",nome,idade,end);
	return (0);
}
