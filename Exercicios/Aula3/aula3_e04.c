/***
Imprime na tela o somatório de 1/i, com i variando de 1 a 200.
***/

#include <stdio.h>

int main ()
{
	int i;
	float som;

	som=0;
	for (i=1; i<=200; i++)
		som+=(1.0/i);
	printf("\nO somatorio de 1/i, com i variando de 1 a 200, vale: %.2f\n",som);
	getchar();
	return 0;
}
