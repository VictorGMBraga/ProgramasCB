#include <stdio.h>

typedef struct {
	int matricula;
	float nota_prova[2];
	float nota_trabalho[2];
} tipoDadosAlunos;

void le_dados (tipoDadosAlunos DadosAlunos[]) {
	int i, i2;

	for(i=0; i<2; i++) {
		printf("\nInforme a matricula do aluno %d: ", i+1);
		scanf("%d", &DadosAlunos[i].matricula);
		getchar();
		
		for(i2=0; i2<2; i2++) {
			printf("Informe a nota da prova %d: ", i2+1);
			scanf("%f", &DadosAlunos[i].nota_prova[i2]);
			getchar();
		}

		for(i2=0; i2<2; i2++) {
			printf("Informe a nota da do trabalho %d: ", i2+1);
			scanf("%f", &DadosAlunos[i].nota_trabalho[i2]);
			getchar();
		}
	}
}

void salva_dados (tipoDadosAlunos DadosAlunos[]) {
	FILE *fp;
	char nomeArquivo[] = "alunos.bin";
	
	fp = fopen(nomeArquivo, "r+b");
	if(fp == NULL) {
		fp = fopen(nomeArquivo, "wb");
	}
	fwrite(DadosAlunos, sizeof(tipoDadosAlunos), 2, fp);
	fclose(fp);
}

int acessa_dados (tipoDadosAlunos DadosAcessados[]) {
	FILE *fp;
	char nomeArquivo[] = "alunos.bin";
	
	fp = fopen(nomeArquivo, "rb");
	if(fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		return(0);
	}
	fread(DadosAcessados, sizeof(tipoDadosAlunos), 2, fp);
	fclose(fp);
	return(1);
}

void mostra_dados (tipoDadosAlunos DadosAcessados[]) {
	int i, i2;
	
	for(i=0; i<2; i++) {
		printf("\n\nA matricula do aluno %d e: %d", i+1, DadosAcessados[i].matricula);		
		for(i2=0; i2<2; i2++) {
			printf("\nA nota da prova %d do aluno %d e: %.2f", i2+1, i+1, DadosAcessados[i].nota_prova[i2]);
		}
		for(i2=0; i2<2; i2++) {
			printf("\nA nota do trabalho %d do aluno %d e: %.2f", i2+1, i+1, DadosAcessados[i].nota_trabalho[i2]);
		}
	}
}

int main() {
    tipoDadosAlunos DadosAlunos[2];
	tipoDadosAlunos DadosAcessados[2];

	le_dados(DadosAlunos);
	
	
	salva_dados(DadosAlunos);
	if(acessa_dados(DadosAcessados)) {
		mostra_dados(DadosAcessados);
	}
	
    getchar();
	return(0);
}
