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
 *   Le um conjunto v de n numeros distintos e um numero k.            *
 *   Descobre, caso exista, o menor subconjunto de v que tenha como    *
 *   soma um valor maior ou igual a k.                                 *
 *                                                                     *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>

int main() {

    /**
      Declaracao de variaveis.
    **/
    int i, i2, n, k, flag, aux, soma = 0, v[999];

    /**
      Leitura de dados.
    **/
    printf("\nInforme o numero de elementos do conjunto v: ");
    scanf("%d",&n);
    printf("\n");
    for(i = 0 ; i < n ; i++) {
        printf("Digite o elemento %d do conjunto: ",i+1);
        scanf("%d",&v[i]);
    }
    printf("\nInforme o numero k: ");
    scanf("%d",&k);

    /**
      Ordenacao do vetor em ordem decrescente.
    **/
    do {
        flag = 0;
        for(i = 0 ; i < n ; i++) {
            if(v[i] < v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                flag = 1;
            }
        }
    } while(flag);

    /**
      Soma os valores do vetor em ordem crescente
      ate atingir um numero maior ou igual a k ou
      somar todo o vetor.
    **/
    i = 0;
    while((soma < k)&&(i < n)) {
        soma += v[i];
        i++;
    }

    /**
      Saida de Dados.
      Mostra os numeros somados caso a soma seja maior
      ou igual a k ou informa caso a soma nao chegue ao
      valor de k.
    **/
    if(soma >= k) {
        i2 = i;
        printf("\nSim, existe subconjunto de v cuja soma e maior ou igual a k:\n");
        for(i = 0 ; i < i2 ; i++) {
            printf("\n%d",v[i]);
        }
    }
    else {
        printf("\nNao existe subconjunto de v cuja soma seja maior ou igual a k.");
    }

    /**
      Fim do programa.
    **/
    printf("\n\nPressione ENTER para encerrar o programa...");
    getchar();
    getchar();
    return(0);
}
