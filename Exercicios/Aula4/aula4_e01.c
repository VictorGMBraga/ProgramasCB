/***
Lê do usuário ano e sexo e mostra na tela esses dois valores.
O sexo só é coisiderado válido se for igual a M ou m ou F ou f.
***/

#include <stdio.h>

int main(){
	int ano;
    char sexo;
	
    printf("\nInforme o sexo: ");
    scanf("%c",&sexo);
    while((sexo!='f')&&(sexo!='F')&&(sexo!='m')&&(sexo!='M')){
		printf("Sexo invalido!");
		printf("\nInforme o sexo novamente: ");
		getchar();
		scanf("%c",&sexo);
    }
    printf("Informe o ano: ");
    scanf("%d",&ano);
    printf("\nO ano e %d e o sexo e %c.",ano,sexo);
    getchar();
    getchar();
    return(0);
}
