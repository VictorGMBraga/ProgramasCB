#include <stdio.h>

typedef struct {
   int matric;
   char depto, nome[30];
   float sal;
} tipoDadosFunc;

void le_dados (tipoDadosFunc *DadosFunc) {
	int i, i2;
	FILE *fp;
	char nomeArquivo[] = "func.bin";
	
	fp = fopen(nomeArquivo, "r+b");
	if(fp == NULL) {
		fp = fopen(nomeArquivo, "wb");
	}
	for(i=0; i<2; i++) {
		printf("\nInforme a matricula do funcionario %d: ", i+1);
		scanf("%d", &(DadosAlunos->matricula));
		getchar();
		fwrite(&*DadosAlunos, sizeof(tipoDadosAlunos), 1, fp);
	}
	fclose(fp);
}

int gera_log (tipoDadosAlunos *DadosAcessados) {
	int i;
	FILE *fp;
	FILE *fp2;
	float media;
	char nomeArquivo[] = "alunos.bin";
	char nomeArquivo2[] = "media.txt";
	
	fp = fopen(nomeArquivo, "rb");
	if(fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		return(0);
	}
	fp2 = fopen(nomeArquivo2, "r+");
	if(fp2 == NULL) {
		fp2 = fopen(nomeArquivo2, "w");
	}
	for(i=0; i<2; i++) {
		fread(&*DadosAcessados, sizeof(tipoDadosAlunos), 1, fp);
		media = (((((DadosAcessados->nota_prova[0]*2)+(DadosAcessados->nota_prova[1]*3)+(DadosAcessados->nota_prova[2]*3))/8)*8)
			+ (((DadosAcessados->nota_trabalho[0]+DadosAcessados->nota_trabalho[1])/2)*2))/10;
		fprintf(fp2, "%d - %.2f \n", DadosAcessados->matricula, media);	
	}
	fclose(fp);
	fclose(fp2);
	
	return(1);
}

int main() {
    tipoDadosAlunos DadosAlunos;
	tipoDadosAlunos DadosAcessados;

	le_dados(&DadosAlunos);	
	gera_log(&DadosAcessados);
	
    getchar();
	return(0);
}
