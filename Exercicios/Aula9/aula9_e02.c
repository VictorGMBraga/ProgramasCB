#include <stdio.h>

typedef struct {
   int matricula;
   char depto[40], nome[40];
   float salario;
} tipoDadosFunc;

int main() {
    tipoDadosFunc DadosFunc;
	FILE *fp;
	char recadastra, nomeArquivo[] = "func.bin";
	
	fp = fopen(nomeArquivo, "r+b");
	if(fp == NULL) {
		fp = fopen(nomeArquivo, "wb");
	}
	
	do {
		printf("\nInforme a matricula do funcionario: ");
		scanf("%d", &DadosFunc.matricula);
		getchar();
		printf("Informe o nome do funcionario: ");
		scanf("%s", DadosFunc.nome);
		getchar();
		printf("Informe departamento do funcionario: ");
		scanf("%s", DadosFunc.depto);
		getchar();
		printf("Informe o salario do funcionario: ");
		scanf("%f", &DadosFunc.salario);
		getchar();
		printf("\nCadastrar outro funcionario(int) (S/N) ");
		scanf("%c",&recadastra);
		fwrite(&DadosFunc, sizeof(tipoDadosFunc), 1, fp);
	} while((recadastra=='s')||(recadastra=='S'));
	
	fclose(fp);
	
    getchar();
	return(0);
}
