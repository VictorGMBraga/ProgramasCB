/*Lê um número e mostra seu sucessor e antecessor*/

#include <stdio.h>

int main ()
{
	int num;
	
	printf("\nDigite o numero: ");
	scanf("%d",&num);
	printf("O sucessor do numero vale: %d\n",num+1);
	printf("O antecessor do numero vale: %d\n",num-1);
	return 0;
}
