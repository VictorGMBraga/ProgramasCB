#include <stdio.h>

int main ()
{
	const int const_i=1;
	const float const_f=1;
	const char const_c='A';
	const char const_s[]="ABC";
	int var_i;
	float var_f;
	char var_c; 
	char var_s[50];
	
	printf("\nA constante do tipo inteiro vale: %d\n", const_i);
	printf("A constante do tipo real vale: %.2f\n", const_f);
	printf("A constante do tipo caracter vale: %c\n", const_c);
	printf("A constante do tipo cadeia de caracteres vale: %s\n", const_s);	
	printf("\nDigite um numero inteiro: ");
	scanf("%d",&var_i);
	printf("Digite um numero real: ");
	scanf("%f",&var_f);
	getchar();
	printf("Digite um caracter: ");
	scanf("%c",&var_c);
	printf("Digite uma cadeia de caracteres: ");
	scanf("%s",var_s);	
	printf("\nA variavel do tipo inteiro vale: %d\n", var_i);
	printf("A variavel do tipo real vale: %.2f\n", var_f);
	printf("A variavel do tipo caracter vale: %c\n", var_c);
	printf("A variavel do tipo cadeia de caracteres vale: %s\n", var_s);
	return (0);
}
