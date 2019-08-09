#include <stdio.h>

int main ()
{
    int i, i2, m, n, inv = 0, vezes_repet = 0, primeiro = 1;
    int A[100][100], repet;

    printf("\n");
    do
    {
        if(inv==1)
            printf("Valor invalido!\n");
        printf("Informe o numero de linhas da matriz: ");
        scanf("%d",&m);
        inv = 1;
    }
    while((m>100)||(m<1));
    inv = 0;
    printf("\n");
    do
    {
        if(inv==1)
            printf("Valor invalido!\n");
        printf("Informe o numero de colunas da matriz: ");
        scanf("%d",&n);
        inv = 1;
    }
    while((n>100)||(n<1));
    inv = 0;
    printf("\n");
    for (i=0; i<m; i++)
    {
        for (i2=0; i2<n; i2++)
        {
            printf("Digite o elemento %d,%d da matriz: ",i+1,i2+1);
            scanf("%d",&A[i][i2]);
        }
    }

	while(vezes_repet == 0)
	{
		for (i=0; i<m; i++)
		{
			for (i2=0; i2<n; i2++)
			{
				if((!primeiro)&&(A[i][i2]==repet))
				{
					vezes_repet++;
				}
				else if (vezes_repet == 0)
				{
					repet = A[i][i2];
					primeiro = 0;
				}
			}
		}
	}
    printf("\nO elemento %d se repete %d vezes na matriz.",repet,vezes_repet);

    getchar();
    getchar();
    return(0);
}
