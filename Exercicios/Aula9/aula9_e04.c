#include <stdio.h>

typedef struct {
   int matricula;
   char depto[40], nome[40];
   float salario;
} tipoDadosFunc;

int main() {
    tipoDadosFunc DadosFunc;
	FILE *fp, *fp2;
	char ArquivoE[] = "func.bin", ArquivoS[] = "func_reajustado.bin";
	
	fp = fopen(ArquivoE, "rb");
	if(fp == NULL) {
		printf("Arquivo nao encontrado.\n");
		getchar();
		return(0);
	}
	fp2 = fopen(ArquivoS, "wb");
	
	while(fread(&DadosFunc, sizeof(tipoDadosFunc), 1, fp)) {
		if(DadosFunc.salario<500.00) {
			DadosFunc.salario *= 1.3;
		}
		else if(DadosFunc.salario<1000.00) {
			DadosFunc.salario *= 1.2;
		}
		else {
			DadosFunc.salario *= 1.1;
		}
		fwrite(&DadosFunc, sizeof(tipoDadosFunc), 1, fp2);
	}
	
	printf("Reajuste completo.");
	getchar();

	fclose(fp);
	fclose(fp2);
	
	return(0);
}
