#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} tipoData;

typedef struct {
	char nome[40], endereco[40];
	int telefone;
	tipoData aniversario;
} tipoAgenda;

void LeDados (tipoAgenda agenda[]) {
	int i;
	
	for(i=0; i<10; i++) {
		printf("\nInforme o nome %d: ",i+1);
		scanf("%s",agenda[i].nome);
		getchar();
		printf("Informe o endereco %d: ",i+1);
		scanf("%s",agenda[i].endereco);
		getchar();
		printf("Informe o telefone %d: ",i+1);
		scanf("%d",&agenda[i].telefone);
		getchar();
		printf("Informe o dia de aniversario %d: ",i+1);
		scanf("%d",&agenda[i].aniversario.dia);
		getchar();
		printf("Informe o mes de aniversario %d: ",i+1);
		scanf("%d",&agenda[i].aniversario.mes);
		getchar();
		printf("Informe o ano de aniversario %d: ",i+1);
		scanf("%d",&agenda[i].aniversario.ano);
		getchar();
	}
}

void ImprimeAniversariantes (tipoAgenda agenda[]) {
	int i;
	
	printf("\n** ANIVERSARIANTES DO MES DE DEZEMBRO **\n");
	for(i=0; i<10; i++) {
		if(agenda[i].aniversario.mes==12) {
			printf("\n\nNome: %s",agenda[i].nome);
			printf("\nEndereco: %s",agenda[i].endereco);
			printf("\nTelefone: %d",agenda[i].telefone);
			printf("\nAniversario: ");
			printf("%d-",agenda[i].aniversario.dia);
			printf("%d-",agenda[i].aniversario.mes);
			printf("%d",agenda[i].aniversario.ano);
			getchar();
		}
	}
}

int main () {
	tipoAgenda agenda[10];
	
	LeDados(agenda);
	ImprimeAniversariantes(agenda);	
	
	return(0);
}

