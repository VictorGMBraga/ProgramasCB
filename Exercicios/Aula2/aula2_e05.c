#include <stdio.h>

int main ()
{
	float indpol;
	
	printf("\nInforme o indice de poluicao (nao utilize virgulas, apenas pontos): ");
	scanf("%f",&indpol);
	if (indpol<0.05)
		printf("\nIndice abaixo do normal.\n");
	else
	{
		if (indpol<0.25)
			printf("\nIndice normal.\n");
		else
		{
			if (indpol<0.30)
			printf("\nSituacao de alerta.\n");
			else
			{
				if (indpol<0.40)
					printf("\nSituacao de alerta. Empresas da lista A devem suspender suas atividades.\n");
				else
				{
					if (indpol<0.50)
						printf("\nSituacao de alerta. Empresas da lista B devem suspender suas atividades.\n");
					else
						printf("\nSituacao de alerta. Todas as empresas listadas devem suspender suas atividades.\n");
				}
			}
		}
	}
	return(0);
}
