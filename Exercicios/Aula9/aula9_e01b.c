#include <stdio.h>

typedef struct {
	int matricula;
	float nota_prova[2];
	float nota_trabalho[2];
} tipoDadosAlunos;

void le_dados (tipoDadosAlunos *DadosAlunos) {
	int i, i2;
	FILE *fp;
	char nomeArquivo[] = "alunos.bin";
	
	fp = fopen(nomeArquivo, "r+b");
	if(fp == NULL) {
		fp = fopen(nomeArquivo, "wb");
	}
	for(i=0; i<2; i++) {
		printf("\nInforme a matricula do aluno %d: ", i+1);
		scanf("%d", &(DadosAlunos->matricula));
		getchar();
		for(i2=0; i2<2; i2++) {
			printf("Informe a nota da prova %d: ", i2+1);
			scanf("%f", &(DadosAlunos->nota_prova[i2]));
			getchar();
		}
		for(i2=0; i2<2; i2++) {
			printf("Informe a nota da do trabalho %d: ", i2+1);
			scanf("%f", &(DadosAlunos->nota_trabalho[i2]));
			getchar();
		}
		fwrite(&*DadosAlunos, sizeof(tipoDadosAlunos), 1, fp);
	}
	fclose(fp);
}

int mostra_dados (tipoDadosAlunos *DadosAcessados) {
	int i, i2;
	FILE *fp;
	char nomeArquivo[] = "alunos.bin";
	
	fp = fopen(nomeArquivo, "rb");
	if(fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		return(0);
	}
	for(i=0; i<2; i++) {
		fread(&*DadosAcessados, sizeof(tipoDadosAlunos), 1, fp);
		printf("\n\nA matricula do aluno %d e: %d", i+1, DadosAcessados->matricula);		
		for(i2=0; i2<2; i2++) {
			printf("\nA nota da prova %d do aluno %d e: %.2f", i2+1, i+1, DadosAcessados->nota_prova[i2]);
		}
		for(i2=0; i2<2; i2++) {
			printf("\nA nota do trabalho %d do aluno %d e: %.2f", i2+1, i+1, DadosAcessados->nota_trabalho[i2]);
		}
	}
	fclose(fp);
	
	return(1);
}

int main() {
    tipoDadosAlunos DadosAlunos;
	tipoDadosAlunos DadosAcessados;

	le_dados(&DadosAlunos);	
	mostra_dados(&DadosAcessados);
	
    getchar();
	return(0);
}
