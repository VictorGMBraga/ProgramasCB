#include <stdio.h>

int main ()
{
    int i, i2;
    int MAT[3][3];

    printf("\n");
    for (i=0; i<3; i++)
    {
        for (i2=0; i2<3; i2++)
        {
            printf("Digite o elemento %d,%d da matriz: ",i+1,i2+1);
            scanf("%d",&MAT[i][i2]);
        }
    }

    printf("\n");
    for (i=0; i<3; i++)
    {
        for (i2=0; i2<3; i2++)
        {
            printf("%d\t",MAT[i][i2]);
        }
        printf("\n");
    }

    getchar();
    getchar();
    return(0);
}
