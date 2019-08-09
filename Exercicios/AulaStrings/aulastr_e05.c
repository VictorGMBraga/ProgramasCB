#include <stdio.h>
#include <string.h>

int main () {
	int i = 0, i2 = 0;
	char aux, nome[50];
	
	printf("\nInforme seu nome: ");
	scanf("%[^\n]s",nome);
	getchar();
	
	i = 0;
	i2 = strlen(nome)-1;
	while(i!=i2) {
		aux = nome[i];
		nome[i] =  nome[i2];
		nome[i2] = aux;
		i++;
		i2--;
	}
	
	printf("\nSeu nome invertido e: %s",nome);	
	
	getchar();
	return(0);
}
