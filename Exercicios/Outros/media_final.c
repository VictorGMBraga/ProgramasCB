/*Lê as 3 notas de um aluno e calcula a média final deste aluno. Considerando que a média é ponderada e que o peso das notas é de: 1, 3 e 4, respectivamente*/

#include <stdio.h>

int main ()
{
	float n1,n2,n3,media;
	
	printf("\nDigite a nota 1: ");
	scanf("%f",&n1);
	printf("Digite a nota 2: ");
	scanf("%f",&n2);
	printf("Digite a nota 3: ");
	scanf("%f",&n3);
	media=(n1+(n2*3)+(n3*4))/8.0;
	printf("A media final vale: %f\n",media);
	return 0;
}
