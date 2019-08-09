/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                     *
 *  Universidade de Brasilia                                           *
 *  Instituto de Ciencias Exatas                                       *
 *  Departamento de Ciencia da Computacao                              *
 *                                                                     *
 *  Computacao Basica - 02/2010                                        *
 *  Aluno: Victor Gueresi de Mello Braga                               *
 *  Matricula: 100126481                                               *
 *  Turma: A                                                           *
 *  Versao do compilador: GCC(3.4.4)/Cygwin (Windows)                  *
 *                                                                     *
 *  Descricao:                                                         *
 *   Programa que mostra todos os numeros primos menores que um numero *
 *   fornecido pelo usuario, utilizando-se de um vetor para isso.      *
 *                                                                     *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include <stdio.h>

int main() {

    /**
      Declaracao de variaveis.
    **/
    int i, i2, n, primos = 0, invalido = 0, v[99999];

    /**
      Leitura de dados.
    **/
    printf("\n");
    do {
        if(invalido) {
            printf("Numero invalido! Apenas numeros de 1 a 99999.\n");
        }
        printf("Informe o numero: ");
        scanf("%d",&n);
        invalido = 1;
    } while((n < 0)||(n > 99999));
    
    /**
      Inicializa os valores do vetor.
    **/
    v[0] = -1;
    v[1] = -1;
    for(i = 2 ; i < n ; i++) {
        v[i] = 0;
    }
    
    /**
      Preenche a posicao do vetor com 1 quando acha o valor 0
      e os multiplos desse indice com -1.
    **/
    i = 2;
    while(i < n) {
        if(v[i] == 0) {
            v[i] = 1;
            primos++;
            i2 = 2;
            while((i*i2) < n) {
                v[i*i2] = -1;
                i2++;
            }
            if(i*i >= n) {
                while(i < n) {
                    if(v[i] == 0) {
                        v[i] = 1;
                        primos++;
                    }
                    i++;
                }
            }
        }
        i++;
    }
    
    /**
      Saida de dados. Mostra apenas as poiscoes do
      vetor marcadas com 1 (numeros primos).
    **/
    i2 = 0;
    getchar();
    printf("\nExistem %d numeros primos menores que %d:\n",primos,n);
    for(i = 0 ; i < n ; i++) {
        if(v[i] == 1) {
            printf("\n%d",i);
            i2++;
            if(i2%21 == 0) {
                printf("\nPressione ENTER para exibir mais...");
                getchar();
            }
        }
    }
    
    /**
      Fim do programa.
    **/
    printf("\n\nPressione ENTER para encerrar o programa...");
    getchar();
    return(0);
}
