#include <stdio.h>
#include <string.h>

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
	
	for(i=0; i<4; i++) {
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

void OrdenaAlfabet (tipoAgenda agenda[]) {
	int i, i2, flag, flag2;
	tipoAgenda aux;
	
	do {
		flag = 0;
		for(i=0; i<3; i++) {
			if(strlen(agenda[i].nome)>strlen(agenda[i+1].nome)) {
				i2 = 0;
				while((i2<(strlen(agenda[i+1].nome)-1))&&(!flag2)) {	
					if(agenda[i].nome[i2]>agenda[i+1].nome[i2]) {
						aux = agenda[i];
						agenda[i] = agenda[i+1];
						agenda[i+1] = aux;
						flag = 1;
					}
					i2++;
				}
			}
			else {
				i2 = 0;
				while((i2<(strlen(agenda[i].nome)-1))&&(!flag2)) {
					if(agenda[i].nome[i2]>agenda[i+1].nome[i2]) {
						aux = agenda[i];
						agenda[i] = agenda[i+1];
						agenda[i+1] = aux;
						flag = 1;
					}
					i2++;
				}
			}
		}
	} while(!flag);
}

void ImprimeAniversariantes (tipoAgenda agenda[]) {
	int i;
	
	printf("\n** ANIVERSARIANTES DO MES DE DEZEMBRO **\n");
	for(i=0; i<4; i++) {
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
	OrdenaAlfabet (agenda);
	ImprimeAniversariantes(agenda);	
	
	return(0);
}

