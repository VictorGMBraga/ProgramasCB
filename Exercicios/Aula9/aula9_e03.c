#include <stdio.h>

typedef struct {
   int matricula;
   char depto[40], nome[40];
   float salario;
} tipoDadosFunc;

int main() {
    tipoDadosFunc DadosFunc;
	int i;
	FILE *fp;
	char nomeArquivo[] = "func.bin";
	
	fp = fopen(nomeArquivo, "rb");
	if(fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		getchar();
		return(0);
	}
	
	i = 1;
	while(fread(&DadosFunc, sizeof(tipoDadosFunc), 1, fp)) {
		printf("\n- FUNCIONARIO %d:",i);
		printf("\nMatricula: %d",DadosFunc.matricula);
		printf("\nNome: %s",DadosFunc.nome);
		printf("\nDepartamento: %s",DadosFunc.depto);
		printf("\nSalario: %.2f",DadosFunc.salario);
		i++;
		getchar();
	}

	fclose(fp);
	
	return(0);
}
