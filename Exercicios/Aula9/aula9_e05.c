#include <stdio.h>

typedef struct {
   int matricula;
   char depto[40], nome[40];
   float salario;
} tipoDadosFunc;

int main() {
    tipoDadosFunc DadosFunc;
	FILE *fp, *fp2;
	char ArquivoE[] = "func_reajustado.bin", ArquivoS[] = "func_reajustado2.bin";
	int matricula_busca;
	float salario_antigo = -1;
	
	fp = fopen(ArquivoE, "rb");
	if(fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		getchar();
		return(0);
	}
	fp2 = fopen(ArquivoS, "wb");
	
	printf("\nInforme a matricula que deseja atualizar: ");
	scanf("%d",&matricula_busca);
	getchar();
	
	while(fread(&DadosFunc, sizeof(tipoDadosFunc), 1, fp)) {
		if(DadosFunc.matricula==matricula_busca){
			salario_antigo = DadosFunc.salario;
			printf("\nInforme o novo salario: ");
			scanf("%f",&DadosFunc.salario);
			getchar();
			fwrite(&DadosFunc, sizeof(tipoDadosFunc), 1, fp2);
			fwrite(&salario_antigo, sizeof(float), 1, fp2);
		}
		else { 
			fwrite(&DadosFunc, sizeof(tipoDadosFunc), 1, fp2);
		}
	}
	
	if(salario_antigo!=-1) {
		printf("\nReajuste completo.");
	}
	else {
		printf("\nFuncionario nao encontrado.");
	}

	fclose(fp);
	fclose(fp2);
	
	getchar();
	return(0);
}
