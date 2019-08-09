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
 *   Guarda uma serie de codigos inseridos pelo usuario, que           *
 *   representam armas, em um vetor. Mostra quais foram as armas       *
 *   utilizadas em ordem e sem repeticao e quantas vezes cada          *
 *   arma foi utilizada.                                               *
 *                                                                     *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>

int main() {

    /**
      Declaracao das variavies.
    **/
    int i, i2 = 0, i3, invalido = 0, repetiu;
    int armas[15], armas_usadas[6], armas_repetidas[6];
    char player[40];
    char armas_nomes[6][10] = {
        {'o',' ','M','a','c','h','a','d','o'},
        {'o',' ','A','r','c','o'},
        {'a',' ','A','d','a','g','a'},
        {'a',' ','M','a','c','a'},
        {'a',' ','L','a','n','c','a'},
        {'a',' ','E','s','p','a','d','a'}
        };

    /**
      Leitura de dados.
    **/
    printf("\nDigite o nome de seu personagem: ");
    scanf("%[^\n]s",player);
    getchar();
    printf("\nPara utilizar uma arma, escolha o codigo correspondente:\n1 - Machado\n2 - Arco\n3 - Adaga\n4 - Maca\n5 - Lanca\n6 - Espada");
    printf("\n\n");
    for(i = 0 ; i < 15 ; i++) {
        do {
            if(invalido) {
                printf("Codigo invalido! Apenas numeros de 1 a 6.\n");
            }
            printf("Informe o codigo da arma: ");
            scanf("%d",&armas[i]);
            invalido = 1;
        } while((armas[i] < 1)||(armas[i] > 6));
        printf("%s atacou com %s!\n\n",player,armas_nomes[(armas[i]-1)]);
        invalido = 0;
    }
    printf("%s terminou de atacar...\n",player);
    getchar();
    getchar();

    /**
      Passa o codigo das armas usadas para o vetor armas_usadas e
      a quantidade de vezes para o vetor armas_repetidas.
    **/
    for(i = 0 ; i < 15 ; i++) {
        repetiu = 0;
        for(i3 = 0 ; i3 < i2 ; i3++) {
            if(armas[i] == armas_usadas[i3]) {
                armas_repetidas[i3] += 1;
                repetiu = 1;
            }
        }
        if(!repetiu) {
            armas_usadas[i2] = armas[i];
            armas_repetidas[i2] = 1;
            i2 += 1;
        }
    }

    /**
      Saida de dados.
    **/
    for(i = 0 ; i < i2 ; i++) {
        if(armas_repetidas[i] == 1) {
            printf("\n%s utilizou %s (%d) %d vez.",player,armas_nomes[(armas_usadas[i]-1)],armas_usadas[i],armas_repetidas[i]);
        }
        else {
            printf("\n%s utilizou %s (%d) %d vezes.",player,armas_nomes[(armas_usadas[i]-1)],armas_usadas[i],armas_repetidas[i]);
        }
    }

    /**
      Fim do programa.
    **/
    printf("\n\nPressione ENTER para encerrar o programa...");
    getchar();
    return(0);
}
