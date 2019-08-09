#include <stdio.h>

/*********************************************************
* Descricao : ler e imprimir os dados de DEZ registros.
* Entrada: nome, idade, salario
* Saida:   nome, idade, salario
**********************************************************/

typedef struct {
    int idade;
    float salario;
    char nome[30];
} tipoDadosFunc;

int main() {
    tipoDadosFunc dadosfunc[10];
    int i;

    for (i=0; i<10; i++) {
        printf("\nInforme o nome %d: ",i+1);
        scanf("%s", dadosfunc[i].nome);
        printf("Informe a idade %d: ",i+1);
        scanf("%d", &dadosfunc[i].idade);
        printf("Informe o salario %d: ",i+1);
        scanf("%f", &dadosfunc[i].salario);
    }
	
    printf("\n\n** DADOS INFORMADOS **");
    for (i=0; i<10; i++) {
        printf("\n\nNome %d: %s",i+1,dadosfunc[i].nome);
        printf("\nIdade %d: %d",i+1,dadosfunc[i].idade);
        printf("\nSalario %d: %.2f",i+1,dadosfunc[i].salario);
    }
	
    getchar();
    getchar();
	return(0);
}
