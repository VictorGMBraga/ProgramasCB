#include <stdio.h>

int main () {
	float not1[7], not2[7], media[7];
	int i;
	char matr[7][9];

	for (i=0;i<7;i++) {
		printf("\nDigite a nota 1 do aluno %d: ",i+1);
		scanf("%f", &not1[i]);
		printf("Digite a nota 2 do aluno %d: ",i+1);
		scanf("%f", &not2[i]);
		printf("Digite a matricula do aluno %d: ",i+1);
		scanf("%s",matr[i]);
	}
	
	for (i=0;i<7;i++)
		media[i]=(not1[i]+not2[i])/2.0;
	
	for (i=0;i<7;i++)
		printf("\nAluno %d: Matricula = %s, Nota 1 = %.1f, Nota 2 = %.1f, Media = %.1f.",i+1,matr[i],not1[i],not2[i],media[i]);
	
	getchar();
	getchar();
	return 0;
}
