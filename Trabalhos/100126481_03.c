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
 *   Jogo de domino, com 2 jogadores comandados pelo usuario.          *
 *                                                                     *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***
    Declaracao das funcoes.
***/
void enter ();
void compacta_vetor (int vet[]);
void troca (int *n1, int *n2);
void title_screen ();
void inicializa (int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int pedras_jogA[], int pedras_jogB[], int *mesa_inicio, int *mesa_fim, char *prox_jogador, int *prim_turno, char mesa[][136]);
int qtd_pedras (int pedras_jog[]);
int pode_jogar (int pedras_jog[], int pedras_mesa[], int mesa_inicio, int mesa_fim, int pedras_ladoA[], int pedras_ladoB[]);
int inverteu (char escolha_lado, char escolha_posicao);
int valida_escolha_num (int escolha_pedra, int pedras_jog[], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim);
int valida_escolha_pos (char escolha_posicao, int escolha_pedra, int pedras_jog[], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim);
int valida_escolha_lado (char escolha_lado, char escolha_posicao, int escolha_pedra, int pedras_jog[], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim);
void imprime_mao (int pedras_jog[], int pedras_ladoA[], int pedras_ladoB[]);
void atualiza_vet_mesa (char escolha_posicao, int escolha_pedra, int *mesa_inicio, int *mesa_fim, int pedras_mesa[], int pedras_jog[]);
void primeiro_turno (int pedras_ladoA[], int pedras_ladoB[], int pedras_jog[], int pedras_mesa[], int mesa_inicio, int *prim_jogador, char jogador);
void turno (int pedras_jog[], int pedras_ladoA[], int pedras_ladoB[], int pedras_mesa[], int *mesa_inicio, int *mesa_fim, int *prim_jogador, int *passou, char jogador, char mesa[][136]);
void le_escolhas (int *escolha_pedra, char *escolha_posicao, char *escolha_lado, int pedras_jog[], int pedras_ladoA[], int pedras_ladoB[], int pedras_mesa[], int *mesa_inicio, int *mesa_fim);
void preenche_mesa (char mesa[][136], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim);
void imprime_mesa (int pedras_mesa[], int mesa_inicio, int mesa_fim, int pedras_ladoA[], int pedras_ladoB[], char mesa[][136]);
char* nome_pedras (char pedras_nomes[], int pedra_lado);
int terminou (int pedras_jogA[], int pedras_jogB[], int passou);
void vitoria();

/***
    Inicio do programa.
***/

int main () {

    /*
        Os vetores pedras_ladoA e pedras_ladoB guardam os valores correspondentes
        aos lados de uma pedra acordo com seu indice.
        
        Os vetores pedras_jogA e pedras_jogB guardam os indices das pedras nas maos
        dos jogadores.
        
        O vetor pedras_mesa guarda os indices das pedras na mesa.

        As variaveis mesa_inicio e mesa_fim indicam o inicio e o fim da mesa (as pedras
        comecam a ser jogadas a partir do centro da mesa).
        
        Para os vetores pedras_jogA, pedras_jogB e pedras_mesa; o valor -1 corresponde
        a uma posicao vazia (sem pedra).
    */    
    int prim_turno, passou;
    int pedras_ladoA[10], pedras_ladoB[10];
    int pedras_jogA[5], pedras_jogB[5];
    int pedras_mesa[19];
    int mesa_inicio, mesa_fim;
    char prox_jogador;
    char mesa[19][136];
    
    inicializa(pedras_mesa, pedras_ladoA, pedras_ladoB, pedras_jogA, pedras_jogB, &mesa_inicio, &mesa_fim, &prox_jogador, &prim_turno, mesa);
    title_screen();
    
    do {
        if(prox_jogador=='A') {
            turno(pedras_jogA, pedras_ladoA, pedras_ladoB, pedras_mesa, &mesa_inicio, &mesa_fim, &prim_turno, &passou, prox_jogador, mesa);
            prox_jogador = 'B';
        }
        else {
            turno(pedras_jogB, pedras_ladoA, pedras_ladoB, pedras_mesa, &mesa_inicio, &mesa_fim, &prim_turno, &passou, prox_jogador, mesa);
            prox_jogador = 'A';
        }
    } while(!terminou(pedras_jogA, pedras_jogB, passou));
    
    vitoria(pedras_jogA, pedras_jogB);
    
    getchar();
    return(0);
}

void enter () {

    printf("\nPressione ENTER para continuar...\n");
    getchar();
}

void troca (int *n1, int *n2) {
    /**
        Troca os valores de duas variaveis.
    **/

    int aux;
    
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void compacta_vetor (int vet[]) {
    /**
        Compacta um vetor, colocando todos os valores -1 desse
        vetor nas posicoes finais.
    **/

    int i, i2;
    
    for(i=0;i<4;i++) {
        if(vet[i]==-1) {
            i2=i+1;
            while((vet[i2]==-1)&&(i2<4)) {
                i2+=1;
            }
            vet[i]=vet[i2];
            vet[i2]=-1;
        }
    }
}

void title_screen () {

    printf("\n");
    printf("d8888b.  .d88b.  .88b  d88. d888888b d8b   db  .d88b.     .o88b. d8888b. \n");
    printf("88  `8D .8P  Y8. 88'YbdP`88   `88'   888o  88 .8P  Y8.   d8P  Y8 88  `8D \n");
    printf("88   88 88    88 88  88  88    88    88V8o 88 88    88   8P      88oooY' \n");
    printf("88   88 88    88 88  88  88    88    88 V8o88 88    88   8b      88~~~b. \n");
    printf("88  .8D `8b  d8' 88  88  88   .88.   88  V888 `8b  d8'   Y8b  d8 88   8D \n");
    printf("Y8888D'  `Y88P'  YP  YP  YP Y888888P VP   V8P  `Y88P'     `Y88P' Y8888P' \n");
    printf("\n\n");
    printf("                           PRESSIONE ENTER                             \n\n");
    getchar();
}

void inicializa (int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int pedras_jogA[], int pedras_jogB[], int *mesa_inicio, int *mesa_fim, char *prox_jogador, int *prim_turno, char mesa[][136]) {
    /**
        Funcao para inicializar as variaveis do programa.
    **/

    int i, i2, repetiu;
    int pedras_sorteio[10];
    
    /*
        Pedras na mesa (nenhuma).
    */    
    for(i=0; i<19; i++) {
        pedras_mesa[i] = -1;
    }
    
    /*
        Vetores que representam os lados das pedras.
    */
    pedras_ladoA[0] = 0;
    pedras_ladoB[0] = 0;
    pedras_ladoA[1] = 0;
    pedras_ladoB[1] = 1;
    pedras_ladoA[2] = 0;
    pedras_ladoB[2] = 2;
    pedras_ladoA[3] = 0;
    pedras_ladoB[3] = 3;
    pedras_ladoA[4] = 1;
    pedras_ladoB[4] = 1;
    pedras_ladoA[5] = 1;
    pedras_ladoB[5] = 2;
    pedras_ladoA[6] = 1;
    pedras_ladoB[6] = 3;
    pedras_ladoA[7] = 2;
    pedras_ladoB[7] = 2;
    pedras_ladoA[8] = 2;
    pedras_ladoB[8] = 3;
    pedras_ladoA[9] = 3;
    pedras_ladoB[9] = 3;
    
    /*
        Sorteio dos indices das pedras em um vetor auxiliar e
        passagem para as maos dos jogadores.
    */
    srand(time(NULL));
    for(i=0; i<10; i++) {
        pedras_sorteio[i] = rand()%10;
        do {
            repetiu = 0;
            for(i2=0; i2<i; i2++) {
                if(pedras_sorteio[i]==pedras_sorteio[i2]) {
                    repetiu = 1;
                    pedras_sorteio[i] = rand()%10;
                }
            }
        } while(repetiu);
    }
    
    for(i=0; i<5; i++) {
        pedras_jogA[i] = pedras_sorteio[i];
        if((pedras_ladoA[pedras_jogA[i]]==0)&&(pedras_ladoB[pedras_jogA[i]]==0)) {
            *prox_jogador = 'A';
        }
    }
    for(i=5; i<10; i++) {
        pedras_jogB[i-5] = pedras_sorteio[i];
        if((pedras_ladoA[pedras_jogB[i-5]]==0)&&(pedras_ladoB[pedras_jogB[i-5]]==0)) {
            *prox_jogador = 'B';
        }
    }
    
    /*
        Definicao do inicio e do fim da mesa.
    */
    *mesa_inicio = 9;
    *mesa_fim = 9;
    
    /*
        Preenchimento da mesa com espacos vazios (' ') e a pedra
        PELADO e PELADO.
    */
    for(i=0; i<19; i++) {
        for(i2=0; i2<136; i2++) {
            mesa[i][i2] = ' ';
        }
    }
    for(i=6; i<13; i++) {
        mesa[i][0] = '|';
        mesa[i][8] = '|';
    }
    for(i=1; i<8; i++) {
        mesa[5][i] = '-';
        mesa[9][i] = '-';
        mesa[13][i] = '-';
    }
    
    /*
        Indicador do primeiro turno.
    */
    *prim_turno = 1;
}

int qtd_pedras (int pedras_jog[]) {
    /**
        Retorna a quantidade de pedras na mao de um jogador.
    **/

    int i, qtd = 0;
    
    for(i=0; i<5; i++) {
        if(pedras_jog[i]!=-1) {
            qtd += 1;
        }
    }
    
    return(qtd);
}

void turno (int pedras_jog[], int pedras_ladoA[], int pedras_ladoB[], int pedras_mesa[], int *mesa_inicio, int *mesa_fim, int *prim_turno, int *passou, char jogador, char mesa[][136]) {
    
    /*
        pedras_nomesA e pedras_nomesB sao strings que serao modificadas
        pela funcao nome_pedras para exibir o nome das pedras.
    */
    int escolha_pedra;
    char escolha_posicao, escolha_lado;
    char pedras_nomesA[7], pedras_nomesB[7];
    
    /*
        Carrega a funcao primeiro turno, caso esse seja o caso.
    */    
    if(*prim_turno) {
        *passou = 0;
        primeiro_turno(pedras_ladoA, pedras_ladoB, pedras_jog, pedras_mesa, *mesa_inicio, &*prim_turno, jogador);
        imprime_mesa(pedras_mesa, *mesa_inicio, *mesa_fim, pedras_ladoA, pedras_ladoB, mesa);
    }
    
    /*
        Executa as funcoes de um turno normal se o jogador puder jogar.
    */
    else if(pode_jogar(pedras_jog, pedras_mesa, *mesa_inicio, *mesa_fim, pedras_ladoA, pedras_ladoB)) {
        *passou = 0;
        printf("\nVez do jogador %c.",jogador);
        enter();
        
        imprime_mao(pedras_jog, pedras_ladoA, pedras_ladoB);
        le_escolhas(&escolha_pedra, &escolha_posicao, &escolha_lado, pedras_jog, pedras_ladoA, pedras_ladoB, pedras_mesa, &*mesa_inicio, &*mesa_fim);
        atualiza_vet_mesa(escolha_posicao, escolha_pedra, &*mesa_inicio, &*mesa_fim, pedras_mesa, pedras_jog);
        
        printf("\n\nO jogador %c jogou a pedra %s e %s\n", jogador, nome_pedras(pedras_nomesA, pedras_ladoA[pedras_jog[escolha_pedra-1]]),nome_pedras(pedras_nomesB, pedras_ladoB[pedras_jog[escolha_pedra-1]]));

        if(inverteu(escolha_lado, escolha_posicao)) {
            troca(&pedras_ladoA[pedras_jog[escolha_pedra-1]], &pedras_ladoB[pedras_jog[escolha_pedra-1]]);
        }
        
        pedras_jog[escolha_pedra-1] = -1;
        compacta_vetor(pedras_jog);
        
        imprime_mesa(pedras_mesa, *mesa_inicio, *mesa_fim, pedras_ladoA, pedras_ladoB, mesa);
    }
    
    /*
        Passa a vez caso o jogador nao possa jogar.
    */
    else {
        *passou += 1;
        printf("\nO jogador %c passou a vez.",jogador);
        enter();        
    }
}

void primeiro_turno (int pedras_ladoA[], int pedras_ladoB[], int pedras_jog[], int pedras_mesa[], int mesa_inicio, int *prim_turno, char jogador) {
    /**
        Primeiro turno do jogo, onde o jogador que tirou a pedra
        PELADO e PELADO joga automaticamente essa pedra no centro da mesa.
    **/
    
    int i;

    printf("\nO jogador %c tirou a pedra PELADO e PELADO, entao o jogador %c comeca.",jogador,jogador);
    enter();
    printf("\nO jogador %c jogou a pedra PELADO e PELADO.\n",jogador);

    i = 0;
    while(((pedras_ladoA[pedras_jog[i]]!=0)||(pedras_ladoB[pedras_jog[i]]!=0))&&(i<5)) {
        i++;
    }

    pedras_mesa[mesa_inicio] = pedras_jog[i];
    pedras_jog[i] = -1;
    compacta_vetor(pedras_jog);
    
    *prim_turno = 0;
}

int pode_jogar (int pedras_jog[], int pedras_mesa[], int mesa_inicio, int mesa_fim, int pedras_ladoA[], int pedras_ladoB[]) {
    /**
        A funcao retorna 1 (pode jogar) se qualquer lado de uma pedra do jogador
        for igual a algum dos lados livres nas pontas da mesa.
    **/
    
    int i;
    
    for(i=0; i<qtd_pedras(pedras_jog); i++) {
        if(pedras_ladoA[pedras_jog[i]]==pedras_ladoA[pedras_mesa[mesa_inicio]]) {
            return(1);
        }
        else if(pedras_ladoB[pedras_jog[i]]==pedras_ladoA[pedras_mesa[mesa_inicio]]) {
            return(1);
        }
        else if(pedras_ladoA[pedras_jog[i]]==pedras_ladoB[pedras_mesa[mesa_fim]]) {
            return(1);
        }
        else if(pedras_ladoB[pedras_jog[i]]==pedras_ladoB[pedras_mesa[mesa_fim]]) {
            return(1);
        }
    }
    
    return(0);
}

void imprime_mao (int pedras_jog[], int pedras_ladoA[], int pedras_ladoB[]) {
    /**
        Preenche e imprime a matriz que representa a mao graficamente.
    **/
    
    int i, i2, i3;
    char mao[10][45];
    
    i = 0;
    while((pedras_jog[i]!=-1)&&(i<5)) {
    
        for(i2=0; i2<10; i2++) {
            for(i3=(9*i); i3<(9*(i+1)); i3++) {
                mao[i2][i3] = ' ';
            }
        }
        for(i2=0; i2<9; i2+=4) {
            for(i3=(1+(9*i)); i3<(8+(9*i)); i3++) {
                mao[i2][i3] = '-';
            }
        }
        for(i2=1; i2<8; i2++) {
            mao[i2][9*i] = '|';
            mao[i2][(9*i)+8] = '|';
        }
        
        mao[9][4+(9*i)] = (i+1) + '0';
        mao[9][3+(9*i)] = '(';
        mao[9][5+(9*i)] = ')';
        
        if(pedras_ladoA[pedras_jog[i]]==1) {
            mao[2][i*9+4] = '*';
        }
        else if(pedras_ladoA[pedras_jog[i]]==2) {
            mao[1][i*9+2] = '*';
            mao[3][i*9+6] = '*';
        }
        else if(pedras_ladoA[pedras_jog[i]]==3) {
            mao[2][i*9+4] = '*';
            mao[1][i*9+2] = '*';
            mao[3][i*9+6] = '*';
        }
        if(pedras_ladoB[pedras_jog[i]]==1) {
            mao[6][i*9+4] = '*';
        }
        else if(pedras_ladoB[pedras_jog[i]]==2) {
            mao[5][i*9+2] = '*';
            mao[7][i*9+6] = '*';
        }
        else if(pedras_ladoB[pedras_jog[i]]==3) {
            mao[6][i*9+4] = '*';
            mao[5][i*9+2] = '*';
            mao[7][i*9+6] = '*';
        }
        
        i++;
    }
    
    i3=(9*i);
    printf("\n");
    for(i=0; i<10; i++) {
        for(i2=0; i2<i3; i2++) {
            printf("%c",mao[i][i2]);
        }
        printf("\n");
    }
    printf("\n");
}

void le_escolhas (int *escolha_pedra, char *escolha_posicao, char *escolha_lado, int pedras_jog[], int pedras_ladoA[], int pedras_ladoB[], int pedras_mesa[], int *mesa_inicio, int *mesa_fim) {
    /**
        Le do usuario as escolhas de: pedra, posicao na mesa e lado da pedra.
        Checa a consitencia dos dados e verifica se cada escolha e valida para
        ser jogada na mesa.
    **/

    int op_invalida;
    char confirma;
    
    do {
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("ESCOLHA INVALIDA!");
            }
            printf("\nEscolha o numero da pedra que deseja jogar: ");
            scanf("%d",&*escolha_pedra);
            getchar();
            op_invalida = 1;
        } while(valida_escolha_num(*escolha_pedra, pedras_jog, pedras_mesa, pedras_ladoA, pedras_ladoB, *mesa_inicio, *mesa_fim));
        
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("ESCOLHA INVALIDA!");
            }
            printf("\nJogar no Inicio (cima) ou Fim (baixo) da mesa? (I/F) ");
            scanf("%c",&*escolha_posicao);
            getchar();
            op_invalida = 1;
        } while(valida_escolha_pos(*escolha_posicao, *escolha_pedra, pedras_jog, pedras_mesa, pedras_ladoA, pedras_ladoB, *mesa_inicio, *mesa_fim));
        
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("ESCOLHA INVALIDA!");
            }
            printf("\nEncaixar o lado A (cima) ou lado B (baixo) da pedra? ");
            scanf("%c",&*escolha_lado);
            getchar();
            op_invalida = 1;
        } while(valida_escolha_lado(*escolha_lado, *escolha_posicao, *escolha_pedra, pedras_jog, pedras_mesa, pedras_ladoA, pedras_ladoB, *mesa_inicio, *mesa_fim));
            
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("ESCOLHA INVALIDA!");
            }
            printf("\nConfirma jogada? (S/N) ");
            scanf("%c",&confirma);
            getchar();
            op_invalida = 1;
        } while((confirma!='S')&&(confirma!='s')&&(confirma!='N')&&(confirma!='n'));
        
    } while((confirma!='S')&&(confirma!='s'));
}

int valida_escolha_num (int escolha_pedra, int pedras_jog[], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim) {
    /**
        Verifica se a escolha da pedra pelo jogador e valida e se a
        pedra tem algum lado que se encaixe na mesa.
    **/

    if(escolha_pedra<1) {
        return(1);
    }
    else if(escolha_pedra>qtd_pedras(pedras_jog)) {
        return(1);
    } 
    else if(pedras_ladoA[pedras_jog[escolha_pedra-1]]!=pedras_ladoA[pedras_mesa[mesa_inicio]]) {
        if(pedras_ladoB[pedras_jog[escolha_pedra-1]]!=pedras_ladoA[pedras_mesa[mesa_inicio]]) {
            if(pedras_ladoA[pedras_jog[escolha_pedra-1]]!=pedras_ladoB[pedras_mesa[mesa_fim]]) {
                if(pedras_ladoB[pedras_jog[escolha_pedra-1]]!=pedras_ladoB[pedras_mesa[mesa_fim]]) {
                    return(1);
                }
            }
        }
    }
    
    return(0);
}

int valida_escolha_pos (char escolha_posicao, int escolha_pedra, int pedras_jog[], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim) {
    /**
        Verifica se a escolha da posicao na mesa pelo jogador e valida e se a pedra
        escolhida tem algum lado que se encaixe nessa posicao.
    **/
    
    if((escolha_posicao!='I')&&(escolha_posicao!='i')&&(escolha_posicao!='F')&&(escolha_posicao!='f')) {
        return(1);
    }
    else if((escolha_posicao=='I')||(escolha_posicao=='i')) {
        if(pedras_ladoA[pedras_jog[escolha_pedra-1]]!=pedras_ladoA[pedras_mesa[mesa_inicio]]){
            if(pedras_ladoB[pedras_jog[escolha_pedra-1]]!=pedras_ladoA[pedras_mesa[mesa_inicio]]) {
                return(1);
            }
        }
    }
    else if((escolha_posicao=='F')||(escolha_posicao=='f')) {
        if(pedras_ladoA[pedras_jog[escolha_pedra-1]]!=pedras_ladoB[pedras_mesa[mesa_fim]]) {
            if(pedras_ladoB[pedras_jog[escolha_pedra-1]]!=pedras_ladoB[pedras_mesa[mesa_fim]]) {
                return(1);
            }
        }
    }
    
    return(0);
}

int valida_escolha_lado (char escolha_lado, char escolha_posicao, int escolha_pedra, int pedras_jog[], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim) {
    /**
        Verifica se a escolha do lado da pedra pelo jogador e valida e se 
        o lado da pedra escolhida se encaixa na posicao escolhida da mesa.
    **/
    
    if((escolha_lado!='A')&&(escolha_lado!='a')&&(escolha_lado!='B')&&(escolha_lado!='b')) {
        return(1);
    }
    else if((escolha_lado=='A')||(escolha_lado=='a')) {
        if((escolha_posicao=='I')||(escolha_posicao=='i')) {
            if(pedras_ladoA[pedras_jog[escolha_pedra-1]]!=pedras_ladoA[pedras_mesa[mesa_inicio]]) {
                return(1);
            }
        }
        else if((escolha_posicao=='F')||(escolha_posicao=='f')) {
            if(pedras_ladoA[pedras_jog[escolha_pedra-1]]!=pedras_ladoB[pedras_mesa[mesa_fim]]) {
                return(1);
            }
        }
    }
    else if((escolha_lado=='B')||(escolha_lado=='b')) {
        if((escolha_posicao=='I')||(escolha_posicao=='i')) {
            if(pedras_ladoB[pedras_jog[escolha_pedra-1]]!=pedras_ladoA[pedras_mesa[mesa_inicio]]) {
                return(1);
            }
        }
        else if((escolha_posicao=='F')||(escolha_posicao=='f')) {
            if(pedras_ladoB[pedras_jog[escolha_pedra-1]]!=pedras_ladoB[pedras_mesa[mesa_fim]]) {
                return(1);
            }
        }
    }
    
    return(0);
}

char* nome_pedras (char pedras_nomes[], int pedra_lado) {
    /**
        Preenche uma string com o nome de um dos lados da pedra que o jogador jogou
        e retorna o ponteiro dessa mesma string.
    **/
    
    if(pedra_lado==0) {
        pedras_nomes[0] = 'P';
        pedras_nomes[1] = 'E';
        pedras_nomes[2] = 'L';
        pedras_nomes[3] = 'A';
        pedras_nomes[4] = 'D';
        pedras_nomes[5] = 'O';
        pedras_nomes[6] = '\0';
    }
    else if(pedra_lado==1) {
        pedras_nomes[0] = 'A';
        pedras_nomes[1] = 'S';
        pedras_nomes[2] = '\0';
    }
    else if(pedra_lado==2) {
        pedras_nomes[0] = 'D';
        pedras_nomes[1] = 'U';
        pedras_nomes[2] = 'Q';
        pedras_nomes[3] = 'U';
        pedras_nomes[4] = 'E';
        pedras_nomes[5] = '\0';
    }
    else {
        pedras_nomes[0] = 'T';
        pedras_nomes[1] = 'E';
        pedras_nomes[2] = 'R';
        pedras_nomes[3] = 'N';
        pedras_nomes[4] = 'A';
        pedras_nomes[5] = '\0';
    }
    
    return(pedras_nomes);
}

int inverteu (char escolha_lado, char escolha_posicao) {
    /**
        Verifica se a pedra deve ter seus lados invertidos
        para se encaixar na mesa.
    **/
    
    if((escolha_lado=='A')||(escolha_lado=='a')) {
        if((escolha_posicao=='I')||(escolha_posicao=='i')) {
            return(1);
        }
    }
    else if((escolha_lado=='B')||(escolha_lado=='b')) {
        if((escolha_posicao=='F')||(escolha_posicao=='f')) {
            return(1);
        }
    }
    
    return(0);
}

void atualiza_vet_mesa (char escolha_posicao, int escolha_pedra, int *mesa_inicio, int *mesa_fim, int pedras_mesa[], int pedras_jog[]) {
    /**
        Atualiza o vetor pedras_mesa de acordo com a pedra
        escolhida pelo jogador.
    **/

    if((escolha_posicao=='I')||(escolha_posicao=='i')) {
        *mesa_inicio -= 1;
        pedras_mesa[*mesa_inicio] = pedras_jog[escolha_pedra-1];
    }
    else if((escolha_posicao=='F')||(escolha_posicao=='f')) {
        *mesa_fim += 1;
        pedras_mesa[*mesa_fim] = pedras_jog[escolha_pedra-1];
    }
}

void preenche_mesa (char mesa[][136], int pedras_mesa[], int pedras_ladoA[], int pedras_ladoB[], int mesa_inicio, int mesa_fim) {
    /**
        Preenche a matriz que representa a mesa graficamente de
        acordo com as pedras na mesa.
    **/

    int i, i2, i3;
    char pedra[5][17];
    
    for(i=0; i<5; i++) {
        for(i2=0; i2<17; i2++) {
            pedra[i][i2] = ' ';
        }
    }
    for(i=1; i<4; i++) {
        for(i2=0; i2<17; i2+=8) {
            pedra[i][i2] = '|';
        }
    }
    for(i=0; i<5; i+=4) {
        for(i2=1; i2<16; i2++) {
            pedra[i][i2] = '-';
        }
    }

    for(i=8; i>=mesa_inicio; i--) {
        if(pedras_mesa[i]!=-1) {
            for(i2=0; i2<5; i2++) {
                for(i3=0; i3<17; i3++) {
                    mesa[i2][i3+(17*(-(i-8)))] = pedra[i2][i3];
                }
            }
            if(pedras_ladoA[pedras_mesa[i]]==1) {
                mesa[2][12+(17*(-(i-8)))] = '*';
            }
            else if(pedras_ladoA[pedras_mesa[i]]==2) {
                mesa[3][10+(17*(-(i-8)))] = '*';
                mesa[1][14+(17*(-(i-8)))] = '*';
            }
            else if(pedras_ladoA[pedras_mesa[i]]==3) {
                mesa[2][12+(17*(-(i-8)))] = '*';
                mesa[3][10+(17*(-(i-8)))] = '*';
                mesa[1][14+(17*(-(i-8)))] = '*';
            }
            if(pedras_ladoB[pedras_mesa[i]]==1) {
                mesa[2][4+(17*(-(i-8)))] = '*';
            }
            else if(pedras_ladoB[pedras_mesa[i]]==2) {
                mesa[3][2+(17*(-(i-8)))] = '*';
                mesa[1][6+(17*(-(i-8)))] = '*';
            }
            else if(pedras_ladoB[pedras_mesa[i]]==3) {
                mesa[2][4+(17*(-(i-8)))] = '*';
                mesa[3][2+(17*(-(i-8)))] = '*';
                mesa[1][6+(17*(-(i-8)))] = '*';
            }
        }
    }
    
    for(i=10; i<=mesa_fim; i++) {
        if(pedras_mesa[i]!=-1) {
            for(i2=0; i2<5; i2++) {
                for(i3=0; i3<17; i3++) {
                    mesa[i2+14][i3+(17*(i-10))] = pedra[i2][i3];
                }
            }
            if(pedras_ladoA[pedras_mesa[i]]==1) {
                mesa[16][4+(17*(i-10))] = '*';
            }
            else if(pedras_ladoA[pedras_mesa[i]]==2) {
                mesa[17][2+(17*(i-10))] = '*';
                mesa[15][6+(17*(i-10))] = '*';
            }
            else if(pedras_ladoA[pedras_mesa[i]]==3) {
                mesa[16][4+(17*(i-10))] = '*';
                mesa[17][2+(17*(i-10))] = '*';
                mesa[15][6+(17*(i-10))] = '*';
            }
            if(pedras_ladoB[pedras_mesa[i]]==1) {
                mesa[16][12+(17*(i-10))] = '*';
            }
            else if(pedras_ladoB[pedras_mesa[i]]==2) {
                mesa[17][10+(17*(i-10))] = '*';
                mesa[15][14+(17*(i-10))] = '*';
            }
            else if(pedras_ladoB[pedras_mesa[i]]==3) {
                mesa[16][12+(17*(i-10))] = '*';
                mesa[17][10+(17*(i-10))] = '*';
                mesa[15][14+(17*(i-10))] = '*';
            }
        }
    }
}

void imprime_mesa (int pedras_mesa[], int mesa_inicio, int mesa_fim, int pedras_ladoA[], int pedras_ladoB[], char mesa[][136]) {
    /**
        Imprime a matriz que representa a mesa graficamente.
    **/
    
    int i, i2;

    preenche_mesa(mesa, pedras_mesa, pedras_ladoA, pedras_ladoB, mesa_inicio, mesa_fim);
    
    printf("\n");
    for(i=0; i<19; i++) {
        for(i2=0; i2<136; i2++) {
            printf("%c",mesa[i][i2]);
        }
        printf("\n");
    }
}

int terminou (int pedras_jogA[], int pedras_jogB[], int passou) {
    /**
        A funcao retorna 1 (jogo terminou) quando algum dos jogadores nao tem mais
        pedras na mao ou quando nenhum dos jogadores possa fazer uma jogada valida.
    **/
    
    if((qtd_pedras(pedras_jogA)==0)||(qtd_pedras(pedras_jogB)==0)) {
        return(1);
    }
    else if(passou>1) {
        return(1);
    }
    else {
        return(0);
    }
}

void vitoria (int pedras_jogA[], int pedras_jogB[]) {
    /**
        Anuncia o vencedor (jogador com menor numero de pedras) ou se houve
        empate. Mostra as pedras restantes nas maos dos jogadores (se houverem).
    **/
    
    printf("\nFim de jogo. ");
    if(qtd_pedras(pedras_jogA)<qtd_pedras(pedras_jogB)) {
        printf("O jogador A venceu!");
    }
    else if(qtd_pedras(pedras_jogB)<qtd_pedras(pedras_jogA)) {
        printf("O jogador B venceu!");
    }
    else {
        printf("O jogo empatou.");
    }
    
    printf("\n");
    if(qtd_pedras(pedras_jogA)>0) {
        printf("\nO jogador A ficou com %d pedra(s).",qtd_pedras(pedras_jogA));
    }
    if(qtd_pedras(pedras_jogB)>0) {
        printf("\nO jogador B ficou com %d pedra(s).",qtd_pedras(pedras_jogB));
    }
}
