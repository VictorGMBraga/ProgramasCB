#include <stdio.h>

typedef struct {
	char nome[40];
	int codigo;
} tipoProfissoes;

void ledados (tipoProfissoes Profissoes[], int nroprof) {
	int i;
	
	for(i=0; i<nroprof; i++) {
		printf("\nInforme o nome da profissao %d: ",i+1);
		scanf("%s",Profissoes[i].nome);
		printf("Informe o codigo da profissao %d: ",i+1);
		scanf("%d",&Profissoes[i].codigo);
	}
}

void procuraprof (tipoProfissoes Profissoes[], int nroprof) {
	int codigo, achou, i;
	
	printf("\n\nInforme o codigo que deseja achar: ");
	scanf("%d",&codigo);
	
	i = 0;
	achou = 0;
	while((i<nroprof)&&(!achou)) {
		if(Profissoes[i].codigo==codigo) {
			achou = 1;
		}
		i++;
	}
	
	if(achou) {
		printf("\nProfissao: %s.",Profissoes[i-1].nome);
	}
	else {
		printf("\nCodigo nao encontrado.");
	}
}

int main () {
	tipoProfissoes Profissoes[999];
	int nroprof;
	char repete;

	printf("Informe o numero de profissoes: ");
	scanf("%d",&nroprof);
	
	ledados(Profissoes, nroprof);
	
	do {
		procuraprof(Profissoes, nroprof);
		printf("\nProcurar por outro codigo? (S/N) ");
		getchar();
		scanf("%c",&repete);
	} while((repete=='s')||(repete=='S'));
	
    getchar();
    getchar();
	return(0);
}

