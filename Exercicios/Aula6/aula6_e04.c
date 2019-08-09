#include <stdio.h>

int main ()
{
    int i, i2, prods, qtd_prod2 = 0, mais_prod2, cust_armaz;
    int estoque[3][3], custo[3];

    printf("\n");
    for(i=0; i<3; i++)
    {
        printf("Informe o preco do produto %d: ",i+1);
        scanf("%d",&custo[i]);
    }

    for(i=0; i<3; i++)
    {
        printf("\n");
        for(i2=0; i2<3; i2++)
        {
            printf("Informe a quantidade do produto %d no armazem %d: ",i2+1,i+1);
            scanf("%d",&estoque[i][i2]);
        }
    }
    getchar();

    for(i=0; i<3; i++)
    {
        prods = 0;
        for(i2=0; i2<3; i2++)
        {
            prods += estoque[i][i2];
        }
        printf("\nNo armazem %d existem %d produtos.",i+1,prods);
    }
    getchar();

    i2 = 1;
    for(i=0; i<3; i++)
    {
        if(estoque[i][i2] > qtd_prod2)
        {
            qtd_prod2 = estoque[i][i2];
            mais_prod2 = i;
        }
    }

    for(i=0; i<3; i++)
    {
        printf("\nO custo do produto %d e RS %d.",i+1,custo[i]);
    }
    getchar();

    for(i=0; i<3; i++)
    {
        cust_armaz = 0;
        for(i2=0; i2<3; i2++)
        {
            cust_armaz += (estoque[i][i2])*(custo[i2]);
        }
        printf("\nO custo total no armazem %d e RS %d.",i+1,cust_armaz);
    }

    getchar();
    return(0);
}
