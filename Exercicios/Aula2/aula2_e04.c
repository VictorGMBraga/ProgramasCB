#include <stdio.h>
#include <math.h>

int main ()
{
	int op,num;
	
	printf("\nDigite um numero: ");
	scanf("%d",&num);
	printf("\nEscolha uma das opcoes abaixo:\n\n 1. Verificar se o numero e par.\n 2. Verificar se o numero e impar.\n 3. Verificar se o numero e multiplo de 3.\n 4. Verificar se o numero e multiplo de 5.\n 5. Verificar se o numero e multiplo de 7.\n 6. Realizar TODOS os testes acima.\n\n -> ");
	scanf("%d",&op);
	if (op==1)
	{
		if ((num%2)==0)
			printf("\nO numero e par.\n");
		else
			printf("\nO numero nao e par.\n");
	}
	else
	{
		if (op==2)
		{
			if ((num%2)!=0)
				printf("\nO numero e impar.\n");
			else
				printf("\nO numero nao e impar.\n");
		}
		else
		{
			if (op==3)
			{
				if ((num%3)==0)
					printf("\nO numero e multiplo de 3.\n");
				else
					printf("\nO numero nao e multiplo de 3.\n");
			}
			else
			{
				if (op==4)
				{
					if ((num%5)==0)
						printf("\nO numero e multiplo de 5.\n");
					else
						printf("\nO numero nao e multiplo de 5.\n");
				}
				else
				{
					if (op==5)
					{
						if ((num%7)==0)
							printf("\nO numero e multiplo de 7.\n");
						else
							printf("\nO numero nao e multiplo de 7.\n");
					}
					else
					{
						if (op==6)
						{
							if ((num%2)==0)
								printf("\nO numero e par.");
							if ((num%2)!=0)
								printf("\nO numero e impar.");
							if ((num%3)==0)
								printf("\nO numero e multiplo de 3.");
							if ((num%5)==0)
								printf("\nO numero e multiplo de 5.");
							if ((num%7)==0)
								printf("\nO numero e multiplo de 7.");
							printf("\n");
						}
						else
							printf("\nOpcao nao existente.\n");
					}
				}
			}
		}
	}
	return(0);
}
