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
 *  Versao do compilador: GCC(3.4.2)/DEV-C++ (Windows)                 *
 *                                                                     *
 *  Descricao:                                                         *
 *   Programa que gerencia um cadastro de itens de um resturante.      *
 *   Cadastra itens de 4 tipos (entrada, prato principal, sobremesa    *
 *   e bebida) em um arquivo binario.                                  *
 *   Pode buscar itens por determinado criterio ou criar um arquivo    *
 *   de texto com um cardapio de itens mais baratos e mais caros.      *
 *   caros.                                                            *
 *                                                                     *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>

/**
    A variavel tipo pode ser igual a:
    'e' : Entrada
    'p' : Prato principal
    's' : Sobremesa
    'b' : Bebida
**/
typedef struct {
    int codigo;
    char tipo;
    char descricao[41];
    float preco;
} tipoItemCardapio;

void ordena_alfabet (tipoItemCardapio ItemCardapio[], int tamanho) {
    /**
        Ordena o vetor de registros dos itens de
        acordo com o nome.
    **/
    
    int i, trocou;
    tipoItemCardapio aux;
    
    trocou = 1;
    i = 0;
    while(trocou) {
        trocou = 0;
        for(i=1; i<tamanho; i++) {
            if(strcmp(ItemCardapio[i-1].descricao,ItemCardapio[i].descricao)>0) {
                aux = ItemCardapio[i-1];
                ItemCardapio[i-1] = ItemCardapio[i];
                ItemCardapio[i] = aux;
                trocou = 1;
            }
        }
    }
}

char* nome_tipo (char nome_tipo[], char tipo_busca) {
    /**
        Retorna um ponteiro para uma string contendo o nome de
        um determinado tipo de item.
    **/
    
    if((tipo_busca=='e')||(tipo_busca=='E')) {
        nome_tipo[0] = 'E';
        nome_tipo[1] = 'N';
        nome_tipo[2] = 'T';
        nome_tipo[3] = 'R';
        nome_tipo[4] = 'A';
        nome_tipo[5] = 'D';
        nome_tipo[6] = 'A';
        nome_tipo[7] = '\0';
    }
    else if((tipo_busca=='p')||(tipo_busca=='P')) {
        nome_tipo[0] = 'P';
        nome_tipo[1] = 'R';
        nome_tipo[2] = 'A';
        nome_tipo[3] = 'T';
        nome_tipo[4] = 'O';
        nome_tipo[5] = ' ';
        nome_tipo[6] = 'P';
        nome_tipo[7] = 'R';
        nome_tipo[8] = 'I';
        nome_tipo[9] = 'N';
        nome_tipo[10] = 'C';
        nome_tipo[11] = 'I';
        nome_tipo[12] = 'P';
        nome_tipo[13] = 'A';
        nome_tipo[14] = 'L';
        nome_tipo[15] = '\0';
    }
    else if((tipo_busca=='s')||(tipo_busca=='S')) {
        nome_tipo[0] = 'S';
        nome_tipo[1] = 'O';
        nome_tipo[2] = 'B';
        nome_tipo[3] = 'R';
        nome_tipo[4] = 'E';
        nome_tipo[5] = 'M';
        nome_tipo[6] = 'E';
        nome_tipo[7] = 'S';
        nome_tipo[8] = 'A';
        nome_tipo[9] = '\0';
    }
    else {
        nome_tipo[0] = 'B';
        nome_tipo[1] = 'E';
        nome_tipo[2] = 'B';
        nome_tipo[3] = 'I';
        nome_tipo[4] = 'D';
        nome_tipo[5] = 'A';
        nome_tipo[6] = '\0';
    }
    
    return(nome_tipo);
}

int menu () {
    /**
        Menu principal do programa contendo suas funcoes.
    **/
    
    int opcao, op_invalida;
    
    printf("\n*** CADASTRO DE PRATOS E BEBIDAS ***\n\n");
    printf("1. CRIAR E INICIAR CADASTRO NOVO\n");
    printf("2. INCLUIR DADOS NO CADASTRO EXISTENTE\n");
    printf("3. CONSULTAR O CADASTRO POR CODIGO DO PRATO\n");
    printf("4. CONSULTAR O CADASTRO POR TIPO DE PRATO E FAIXA DE PRECO\n");
    printf("5. GERAR CARDAPIOS EM ARQUIVO TXT\n");
    printf("6. SAIR\n\n");
    
    op_invalida = 0;
    do {
        if(op_invalida) {
            printf("OPCAO INVALIDA!\n");
        }
        printf(" ESCOLHA A OPCAO DESEJADA: ");
        scanf("%d",&opcao);
        getchar();
        op_invalida = 1;
    } while((opcao<1)||(opcao>6));
    
    return(opcao);
}

void gera_cadastro (char nomeArquivo[], int opcao) {
    /**
        Gera um cadastro de itens em arquivo binario.
        O cadastro pode ser criado (opcao==1) ou atualizado (opcao==2)
        de acrodo com a opcao escolhida no menu principal.
    **/
    
    FILE *fp;
    char recadastrar;
    int op_invalida;
    tipoItemCardapio ItemCardapio;
    
    if(opcao==1) {
        fp = fopen(nomeArquivo, "wb");
    }
    else {
        fp = fopen(nomeArquivo, "r+b");
        if(fp==NULL) {
            printf("\nArquivo nao encontrado, criando novo cadastro...\n");
            fp = fopen(nomeArquivo, "wb");
        }
        else {
            fseek(fp, 0, SEEK_END);
        }
    }
    printf("\n");
    
    do {
    
        printf("\n");
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Codigo invalido!\n");
            }
            printf("Informe o codigo do item: ");
            scanf("%d",&ItemCardapio.codigo);
            getchar();
            op_invalida = 1;
        } while(ItemCardapio.codigo<1);
        
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Tipo invalido!\n");
            }
            printf("Informe o tipo do item (E,P,S,B): ");
            scanf("%c",&ItemCardapio.tipo);
            getchar();
            op_invalida = 1;
        } while((ItemCardapio.tipo!='E')&&(ItemCardapio.tipo!='e')&&(ItemCardapio.tipo!='P')&&(ItemCardapio.tipo!='p')&&(ItemCardapio.tipo!='S')&&(ItemCardapio.tipo!='s')&&(ItemCardapio.tipo!='B')&&(ItemCardapio.tipo!='b'));
        
        printf("Informe a descricao do item: ");
        scanf("%[^\n]s",ItemCardapio.descricao);
        getchar();
        
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Preco invalido!\n");
            }
            printf("Informe o preco do item: ");
            scanf("%f",&ItemCardapio.preco);
            getchar();
            op_invalida = 1;
        } while(ItemCardapio.preco<=0);
        
        fwrite(&ItemCardapio, sizeof(tipoItemCardapio), 1, fp);
    
        printf("\n");
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Escolha invalida!\n");
            }
            printf("Cadastrar outro item? (S/N) ");
            scanf("%c",&recadastrar);
            getchar();
            op_invalida = 1;
        } while((recadastrar!='S')&&(recadastrar!='s')&&(recadastrar!='N')&&(recadastrar!='n'));
        
    } while((recadastrar=='S')||(recadastrar=='s'));
    
    fclose(fp);
}

int consulta_codigo (char nomeArquivo[]) {
    /**
        Consulta o cadastro criado para procurar um codigo
        de item informado pelo usuario e exibe informacoes 
        desse item.
    **/
    
    FILE *fp;
    char nova_busca;
    char nome_tipo_item[15];
    int i, i2, op_invalida, codigo_busca;
    tipoItemCardapio ItemCardapio[1000];

    fp = fopen(nomeArquivo, "rb");
    if(fp==NULL) {
        printf("\nArquivo nao encontrado. Retornando ao menu principal...\n");
        getchar();
        fclose(fp);
        return(0);
    }
    
    /* Todo o cadastro e passado para a memoria antes da busca. */
    i = 0;
    while(fread(&ItemCardapio[i], sizeof(tipoItemCardapio), 1, fp)) {
        i++;
        if(i>999) {
            printf("Tamanho do cadastro excede o maximo suportado. Retornando ao menu principal...\n");
            getchar();
            fclose(fp);
            return(0);        
        }
    }
    fclose(fp);
    
    do {
    
        printf("\n");
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Codigo invalido!\n");
            }
            printf("Informe o codigo que deseja buscar: ");
            scanf("%d",&codigo_busca);
            getchar();
            op_invalida = 1;
        } while(codigo_busca<1);
        
        i2 = i;
        for(i=0; i<i2; i++) {
            if(ItemCardapio[i].codigo==codigo_busca){
                printf("\nTIPO: %s\nDESCRICAO: %s\nPRECO: %.2f\n",nome_tipo(nome_tipo_item, ItemCardapio[i].tipo),ItemCardapio[i].descricao,ItemCardapio[i].preco);
                getchar();
                return(0);
            }
        }

        printf("\n");
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Escolha invalida!\n");
            }
            printf("Item nao encontrado, buscar novamente? (S/N) ");
            scanf("%c",&nova_busca);
            getchar();
            op_invalida = 1;
        } while((nova_busca!='S')&&(nova_busca!='s')&&(nova_busca!='N')&&(nova_busca!='n'));
        
    } while((nova_busca=='S')||(nova_busca=='s'));
    
    return(0);
}

int consulta_preco (char nomeArquivo[]) {
    /**
        Consulta o cadastro criado e mostra itens que se encaixem
        num determinado tipo e numa determinada faixa de preco
        informados pelo usuario.
    **/
    
    FILE *fp;
    char tipo_busca, nova_busca;
    int i, i2, i3, op_invalida;
    int itens_busca[1000];
    char nome_tipo_item[15];
    float precoMen_busca, precoMai_busca;
    tipoItemCardapio ItemCardapio[1000];

    fp = fopen(nomeArquivo, "rb");
    if(fp==NULL) {
        printf("\nArquivo nao encontrado. Retornando ao menu principal...\n");
        getchar();
        fclose(fp);
        return(0);
    }
    
    /* Todo o cadastro e passado para a memoria antes da busca. */
    i = 0;
    while(fread(&ItemCardapio[i], sizeof(tipoItemCardapio), 1, fp)) {
        i++;
        if(i>999) {
            printf("Tamanho do cadastro excede o maximo suportado. Retornando ao menu principal...\n");
            getchar();
            fclose(fp);
            return(0);        
        }
    }
    fclose(fp);
    
    /* O cadastro e ordenado em ordem alfabetica de acordo com as descricoes. */
    ordena_alfabet(ItemCardapio, i);
    
    i2 = i;
    printf("\n");
    do {
    
        printf("\n");
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Tipo invalido!\n");
            }
            printf("Informe o tipo de item que deseja buscar (E,P,S,B): ");
            scanf("%c",&tipo_busca);
            getchar();
            op_invalida = 1;
        } while((tipo_busca!='E')&&(tipo_busca!='e')&&(tipo_busca!='P')&&(tipo_busca!='p')&&(tipo_busca!='S')&&(tipo_busca!='s')&&(tipo_busca!='B')&&(tipo_busca!='b'));
        
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Preco invalido!\n");
            }
            printf("Informe o menor preco deseja buscar: ");
            scanf("%f",&precoMen_busca);
            getchar();
            op_invalida = 1;
        } while(precoMen_busca<=0);
    
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Preco invalido!\n");
            }
            printf("Informe o maior preco deseja buscar: ");
            scanf("%f",&precoMai_busca);
            getchar();
            op_invalida = 1;
        } while(precoMai_busca<=precoMen_busca);
        
        i3 = 0;
        for(i=0; i<i2; i++) {
            if(ItemCardapio[i].tipo==tipo_busca) {
                if(ItemCardapio[i].preco>=precoMen_busca) {
                    if(ItemCardapio[i].preco<=precoMai_busca) {
                        itens_busca[i3] = i;
                        i3++;
                    }
                }
            }
        }
        
        /* Caso encontrados na busca, os itens sao mostrados em gurpos de 10 em 10. */
        if(i3>0) {
            printf("\nCONSULTA: %s\nTOTAL DE ITENS: %d", nome_tipo(nome_tipo_item, tipo_busca), i3);
            printf("\n\nCODIGO     DESCRICAO                                  PRECO");
            for(i=0; i<i3; i++) {                
                printf("\n%-10d %-42s %.2f", ItemCardapio[itens_busca[i]].codigo, ItemCardapio[itens_busca[i]].descricao, ItemCardapio[itens_busca[i]].preco);
                if((i+1)%10==0) {
                    printf("\nPressione ENTER para continuar...");
                    getchar();
                    printf("CODIGO     DESCRICAO                                  PRECO");
                }
            }
        }
        else {
            printf("\nNenhum item encontrado.");
        }

        printf("\n");
        op_invalida = 0;
        do {
            if(op_invalida) {
                printf("Escolha invalida!\n");
            }
            printf("\nFazer outra busca? (S/N) ");
            scanf("%c",&nova_busca);
            getchar();
            op_invalida = 1;
        } while((nova_busca!='S')&&(nova_busca!='s')&&(nova_busca!='N')&&(nova_busca!='n'));
        
    } while((nova_busca=='S')||(nova_busca=='s'));
    
    printf("\n");
    return(0);
}

int gerar_txt (char ArquivoEntrada[], char ArquivoSaida[]) {
    /**
        Gera um arquvo de texto com 2 cardapios com 1 item de cada tipo.
        Um cardapio com os itens mais baratos e outro com os itens mais caros.
    **/
    
    int i, i2;
    int primeiro_item_barato[4], primeiro_item_caro[4];
    char nome_tipo_item[15], tipos[4];
    tipoItemCardapio ItemCardapio[1000], ItemCardapio_barato[4], ItemCardapio_caro[4];
    FILE *fp;
    
    tipos[0] = 'e';
    tipos[1] = 'p';
    tipos[2] = 's';
    tipos[3] = 'b';
    
    for(i=0; i<4; i++) {
        primeiro_item_barato[i] = 1;
    }
    for(i=0; i<4; i++) {
        primeiro_item_caro[i] = 1;
    }
    
    fp = fopen(ArquivoEntrada, "rb");
    if(fp==NULL) {
        printf("\nArquivo nao encontrado. Retornando ao menu principal...\n");
        getchar();
        fclose(fp);
        return(0);
    }
    
    /* Todo o cadastro e passado para a memoria antes da consulta. */
    i = 0;
    while(fread(&ItemCardapio[i], sizeof(tipoItemCardapio), 1, fp)) {
        i++;
        if(i>999) {
            printf("Tamanho do cadastro excede o maximo suportado. Retornando ao menu principal...\n");
            getchar();
            fclose(fp);
            return(0);        
        }
    }
    fclose(fp);
    
    /* A busca checa os itens do cardapio e os compara com os itens dos vetores ItemCardapio_barato
       e ItemCardapio_caro, onde a posicao 0 de cada vetor representa o tipo 'e', a posicao 1
       representa o tipo 'p', a 2 o tipo 's' e a 3 o tipo 'b'.
       Caso os itens sejam mais baratos ou caros que os itens do respectivo vetor ou sejam o primeiro
       item de cada tipo a ser testados, sao passados ao vetor correspondente. */
    i2 = i;
    for(i=0; i<i2; i++) {
        if((ItemCardapio[i].tipo=='e')||(ItemCardapio[i].tipo=='E')) {
            if((primeiro_item_barato[0])||(ItemCardapio[i].preco<ItemCardapio_barato[0].preco)) {
                primeiro_item_barato[0] = 0;
                ItemCardapio_barato[0] = ItemCardapio[i];
            }
            if((primeiro_item_caro[0])||(ItemCardapio[i].preco>ItemCardapio_caro[0].preco)) {
                primeiro_item_caro[0] = 0;
                ItemCardapio_caro[0] = ItemCardapio[i];
            }        
        }
        else if ((ItemCardapio[i].tipo=='p')||(ItemCardapio[i].tipo=='P')) {
            if((primeiro_item_barato[1])||(ItemCardapio[i].preco<ItemCardapio_barato[1].preco)) {
                primeiro_item_barato[1] = 0;
                ItemCardapio_barato[1] = ItemCardapio[i];
            }
            if((primeiro_item_caro[1])||(ItemCardapio[i].preco>ItemCardapio_caro[1].preco)) {
                primeiro_item_caro[1] = 0;
                ItemCardapio_caro[1] = ItemCardapio[i];
            }        
        }
        else if ((ItemCardapio[i].tipo=='s')||(ItemCardapio[i].tipo=='S')) {
            if((primeiro_item_barato[2])||(ItemCardapio[i].preco<ItemCardapio_barato[2].preco)) {
                primeiro_item_barato[2] = 0;
                ItemCardapio_barato[2] = ItemCardapio[i];
            }
            if((primeiro_item_caro[2])||(ItemCardapio[i].preco>ItemCardapio_caro[2].preco)) {
                primeiro_item_caro[2] = 0;
                ItemCardapio_caro[2] = ItemCardapio[i];
            }        
        }
        else if ((ItemCardapio[i].tipo=='b')||(ItemCardapio[i].tipo=='B')) {
            if((primeiro_item_barato[3])||(ItemCardapio[i].preco<ItemCardapio_barato[3].preco)) {
                primeiro_item_barato[3] = 0;
                ItemCardapio_barato[3] = ItemCardapio[i];
            }
            if((primeiro_item_caro[3])||(ItemCardapio[i].preco>ItemCardapio_caro[3].preco)) {
                primeiro_item_caro[3] = 0;
                ItemCardapio_caro[3] = ItemCardapio[i];
            }        
        }
    }
    
    fp = fopen(ArquivoSaida, "wb");
    
    fprintf(fp, "****************************\n*** CARDAPIO MAIS BARATO ***\n****************************");    
    for(i=0; i<4; i++) {
        fprintf(fp, "\n\n** %s **", nome_tipo(nome_tipo_item, tipos[i]));
        fprintf(fp, "\nCODIGO: %d", ItemCardapio_barato[i].codigo);
        fprintf(fp, "\nDESCRICAO: %s", ItemCardapio_barato[i].descricao);
        fprintf(fp, "\nPRECO: %.2f", ItemCardapio_barato[i].preco);
    }
    
    fprintf(fp, "\n\n****************************\n**** CARDAPIO MAIS CARO ****\n****************************");    
    for(i=0; i<4; i++) {
        fprintf(fp, "\n\n** %s **", nome_tipo(nome_tipo_item, tipos[i]));
        fprintf(fp, "\nCODIGO: %d", ItemCardapio_caro[i].codigo);
        fprintf(fp, "\nDESCRICAO: %s", ItemCardapio_caro[i].descricao);
        fprintf(fp, "\nPRECO: %.2f", ItemCardapio_caro[i].preco);
    }
    
    fclose(fp);
    printf("\nArquivo criado.\n");
    getchar();
    return(0);
}

int main () {
    /**
        O programa se repete indefinidamente entre o menu e as funcoes
        ate o usuario escolher a opcao 6 do menu (SAIR).
    **/
    
    int escolha;
    char nomeArquivo[] = "RESTAURANTE.bin";
    
    do {
        escolha = menu();
        
        if(escolha==1) {
            gera_cadastro(nomeArquivo, 1);
        }
        else if(escolha==2) {
            gera_cadastro(nomeArquivo, 2);
        }
        else if(escolha==3) {
            consulta_codigo(nomeArquivo);
        }
        else if(escolha==4)  {
            consulta_preco(nomeArquivo);
        }
        else if(escolha==5) {
            gerar_txt(nomeArquivo, "CARDAPIO.txt");
        }    
    } while(escolha!=6);
    
    return(0);
}
