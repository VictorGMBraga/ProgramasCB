/***
Lê as seguintes informações para um número indeterminado de alunos : matrícula, nome e as notas de três provas. A leitura dos dados termina quando o usuário digita 0 para a matrícula (esse valor não é considerado na média). 
Imprime na tela, para cada aluno: matrícula, nome e média ponderada das provas, onde a 1ª prova tem peso 2, a 2ª prova tem peso 4 e a 3ª prova tem peso 4.  
***/

#include <stdio.h>

int main ()
{
	int mat,i;
	char nome[50];
	float n1,n2,n3,media;
	
	i=1;
	printf("\nInforme as matriculas, nomes e notas dos alunos.\nNas notas, deve ser utilizado o ponto para casas decimais.\nPara finalizar, informe uma matricula igual a 0.");
	do
	{
		printf("\n\nInforme a matricula do aluno %d: ",i);
		scanf("%d",&mat);
		if (mat!=0)
		{
			getchar();
			printf("Informe o nome do aluno de matricula %d: ",mat);
			scanf("%[A-Z a-z]",nome);
			printf("Informe a nota 1 de %s: ",nome);
			scanf("%f",&n1);
			while((n1<0)||(n1>10))
			{
				printf("A nota deve ser um valor de 0 a 10.\n");
				printf("Informe a nota 1 de %s: ",nome);
				scanf("%f",&n1);
			}
			printf("Informe a nota 2 de %s: ",nome);
			scanf("%f",&n2);
			while((n2<0)||(n2>10))
			{
				printf("A nota deve ser um valor de 0 a 10.\n");
				printf("Informe a nota 2 de %s: ",nome);
				scanf("%f",&n2);
			}
			printf("Informe a nota 3 de %s: ",nome);
			scanf("%f",&n3);
			while((n3<0)||(n3>10))
			{
				printf("A nota deve ser um valor de 0 a 10.\n");
				printf("Informe a nota 3 de %s: ",nome);
				scanf("%f",&n3);
			}
			media=((n1*2)+(n2*4)+(n3*4))/10;
			printf("\nO aluno de matricula %d se chama %s e tirou media %.1f.",mat,nome,media);
			i+=1;
		}
	}
	while (mat!=0);
	return 0;
}
