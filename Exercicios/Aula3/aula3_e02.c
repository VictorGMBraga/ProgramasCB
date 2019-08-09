/***
Imprime na tela o somatorio de i, com i variando de 1 a 10.
***/

#include <stdio.h>

int main ()
{
	int i,som;

	som=0;
	for (i=1; i<=10; i++)
		som+=i;
	printf("\nO somatorio de i, com i variando de 1 a 10, vale: %d\n",som);
	getchar();
	return 0;
}
