/*Lê uma idade apenas em dias e a mostra em anos, meses e dias*/

#include <stdio.h>

int main ()
{
	int idade_d,anos,meses,dias;
	
	printf("\nDigite a idade em dias: ");
	scanf("%d",&idade_d);
	anos=idade_d/365;
	meses=(idade_d%365)/30;
	dias=(idade_d%365)%30;
	printf("A idade e de: %d anos, %d meses e %d dias.\n",anos,meses,dias);
	return 0;
}
