#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} tipoData;

typedef struct {
	char nome[40], cargo[40], departamento[40];
	float salario;
	tipoData dataAdmiss;
} tipoFuncionarios;

void LeDados (tipoFuncionarios funcionarios[]) {
	int i;
	
	for(i=0; i<10; i++) {
		printf("\nInforme o nome %d: ",i+1);
		scanf("%s",funcionarios[i].nome);
		getchar();
		printf("Informe o cargo %d: ",i+1);
		scanf("%s",funcionarios[i].cargo);
		getchar();
		printf("Informe o dapartamento %d: ",i+1);
		scanf("%s",funcionarios[i].departamento);
		getchar();
		printf("Informe o salario %d: ",i+1);
		scanf("%f",&funcionarios[i].salario);
		getchar();
		printf("Informe o dia de admissao %d: ",i+1);
		scanf("%d",&funcionarios[i].dataAdmiss.dia);
		getchar();
		printf("Informe o mes de admissao %d: ",i+1);
		scanf("%d",&funcionarios[i].dataAdmiss.mes);
		getchar();
		printf("Informe o ano de admissao %d: ",i+1);
		scanf("%d",&funcionarios[i].dataAdmiss.ano);
		getchar();
	}
}

float MediaSalario (tipoFuncionarios funcionarios[]) {
	float media;
	int i;
	
	media = 0;
	for(i=0; i<10; i++) {
		media += funcionarios[i].salario;
	}
	
	return(media/10);
}

void ImprimeRicos (tipoFuncionarios funcionarios[]) {
	int i;
	float mediaSalario;
	
	mediaSalario = MediaSalario(funcionarios);
	
	printf("\n** FUNCIONARIOS COM SALARIOS ACIMA DA MEDIA **\n");
	for(i=0; i<10; i++) {
		if(funcionarios[i].salario>mediaSalario) {
			printf("\n\nNome: %s",funcionarios[i].nome);
			printf("\nCargo: %s",funcionarios[i].cargo);
			printf("\nDepartamento: %s",funcionarios[i].departamento);
			printf("\nSalario %.2f",funcionarios[i].salario);
			printf("\nData de admissao: ");
			printf("%d-",funcionarios[i].dataAdmiss.dia);
			printf("%d-",funcionarios[i].dataAdmiss.mes);
			printf("%d",funcionarios[i].dataAdmiss.ano);
			getchar();
		}
	}
}

int main () {
	tipoFuncionarios funcionarios[10];
	
	LeDados(funcionarios);
	ImprimeRicos(funcionarios);	
	
	return(0);
}

