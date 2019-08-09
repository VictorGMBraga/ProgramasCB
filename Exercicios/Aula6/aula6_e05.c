#include <stdio.h>

int main ()
{
    int i, i2, invalida = 0;
    int campo[5][5], vizinhanca[5][5];

    printf("\nInforme 1 para mina ou 0 para espaco vazio: \n\n");
    for(i=0; i<5; i++)
    {
        for(i2=0; i2<5; i2++)
        {
            do
            {
                if(invalida)
                {
                    printf("Valor Invalido!\n");
                }
                printf("Posicao %d,%d: ",i+1,i2+1);
                scanf("%d",&campo[i][i2]);
                invalida = 1;
            }
            while((campo[i][i2]!=0)&&(campo[i][i2]!=1));
            invalida = 0;
        }
    }

    for(i=0; i<5; i++)
    {
        for(i2=0; i2<5; i2++)
        {
            vizinhanca[i][i2] = 0;
        }
    }

    for(i=0; i<5; i++)
    {
        for(i2=0; i2<5; i2++)
        {
            if((campo[i][i2+1]==1)&&(i2!=19))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i][i2-1]==1)&&(i2!=0))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i+1][i2]==1)&&(i!=19))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i-1][i2]==1)&&(i!=0))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i+1][i2+1]==1)&&(i!=19)&&(i2!=19))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i-1][i2+1]==1)&&(i!=0)&&(i2!=19))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i+1][i2-1]==1)&&(i!=19)&&(i2!=0))
            {
                vizinhanca[i][i2] += 1;
            }
            if((campo[i-1][i2-1]==1)&&(i!=0)&&(i2!=0))
            {
                vizinhanca[i][i2] += 1;
            }
        }
    }

    printf("\nA quantidade de minas na vizinhanca de cada posicao e:\n\n");
    for(i=0; i<5; i++)
    {
        for(i2=0; i2<5; i2++)
        {
            printf("%d  ",vizinhanca[i][i2]);
        }
        printf("\n");
    }

    getchar();
    getchar();
    return(0);
}
