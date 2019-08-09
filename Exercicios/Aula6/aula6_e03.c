#include <stdio.h>

int main ()
{
    int i, i2, i3, linhas_nulas = 0, colunas_nulas = 0;
    int m[4][4];

    for (i=0; i<4; i++)
    {
        for (i2=0; i2<4; i2++)
        {
            printf("Digite o elemento %d,%d da matriz: ",i+1,i2+1);
            scanf("%d",&m[i][i2]);
        }
    }

    for(i=0; i<4; i++)
    {
        for(i2=0; i2<4; i2++)
        {
            i3 = 0;
            while(m[i][i3]==0)
            {
                i3++;
            }
            if(i3==4)
            {
                linhas_nulas += 1;
            }
            i3 = 0;
            while(m[i3][i]==0)
            {
                i3++;
            }
            if(i3==4)
            {
                colunas_nulas += 1;
            }
        }
    }

    printf("\n\nLinhas Nulas: %d Colunas Nulas: %d.",linhas_nulas/4,colunas_nulas/4);

    getchar();
    getchar();
    return(0);
}
