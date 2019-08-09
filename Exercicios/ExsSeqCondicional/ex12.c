#include <stdio.h>

#define d_di (hor_f-hor_i)
#define d_dd ((24-hor_i)+hor_f)

int main ()
{
	int hor_i,hor_f;
	printf("\nInforme a hora de inicio do jogo: ");
	scanf("%d",&hor_i);
	printf("Informe a hora de fim do jogo: ");
	scanf("%d",&hor_f);
	if (hor_i<hor_f)
	{
		printf("\nA duracao do jogo e de %d horas.\n\n",d_di);
	}
	else
	{
		printf("\nA duracao do jogo e de %d horas.\n\n",d_dd);
	}
	return(0);
}
