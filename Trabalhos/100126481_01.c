/*
 *  Universidade de Brasilia
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciencia da Computacao
 *  
 *  Computacao Basica - 02/2010
 *  Aluno: Victor Gueresi de Mello Braga
 *  Matricula: 100126481
 *  Turma: A
 *  Versão do compilador: GCC(3.4.4)/Cygwin (Windows)
 *  
 *  Descricao:
 *  Programa que cadastra 4 tipos de itens: entrada, prato principal, sobremesa e bebida.
 *  E lido do usuario um numero indefinido de itens (ao menos 1 de cada tipo).
 *  Para cada item, e lido: codigo, descricao e preco.
 *  No final programa sao gerados: um cardapio mais barato e um cardapio mais caro.
 *  Os cardapios informam codigo, descricao e preco de cada item e ainda preco total do cardapio.
 */
 
#include <stdio.h>
#include <string.h>

int main()
{

	/*
	 *   Declaracao de variaveis.
	 */
	
	/*
	 A funcao das variaveis invalida, primeiro_item e recadastro e explicada ao decorrer do codigo.
	*/
	
	int invalida = 0, primeiro_item = 1;
	int codigo_entrada, barato_codigo_entrada, caro_codigo_entrada;
	int codigo_principal, barato_codigo_principal, caro_codigo_principal;
	int codigo_sobremesa, barato_codigo_sobremesa, caro_codigo_sobremesa;
	int codigo_bebida, barato_codigo_bebida, caro_codigo_bebida;
	
	float barato_preco_total, caro_preco_total;
	float preco_entrada, barato_preco_entrada, caro_preco_entrada = 0.0;
	float preco_principal, barato_preco_principal, caro_preco_principal = 0.0;
	float preco_sobremesa, barato_preco_sobremesa, caro_preco_sobremesa = 0.0;
	float preco_bebida, barato_preco_bebida, caro_preco_bebida = 0.0;
	
	char recadastro;
	char descricao_entrada[41], barato_descricao_entrada[41], caro_descricao_entrada[41];
	char descricao_principal[41], barato_descricao_principal[41], caro_descricao_principal[41];
	char descricao_sobremesa[41], barato_descricao_sobremesa[41], caro_descricao_sobremesa[41];
	char descricao_bebida[41], barato_descricao_bebida[41], caro_descricao_bebida[41];
	
	/*
	 *   Inicio do programa. Mostra uma mensagem explicativa ao usuario.
	 */
	
	
	printf("*********************************\n* PROGRAMA GERADOR DE CARDAPIOS *\n*********************************\n\n Insira os dados solicitados para gerar\n um cardapio mais barato e um cardapio mais caro.");
	
	/*
	 *   Cadastro dos itens do cardapio.
	 */
	
	
	/**
	  Cadastro das entradas.
	**/	
	printf("\n\n\n## ENTRADA ##\n\n");
	do
	{
		/*
		 Leitura de: codigo, descricao e preco. Com checagem de consistencia.
		*/
		do
		{
			if(invalida == 1)   /* Variavel para checagem de consistencia. */
				printf(" Codigo invalido! (Deve ser maior que 0)\n");
			printf(" Informe o codigo do item: ");
			scanf("%d",&codigo_entrada);
			invalida = 1;
		}
		while(codigo_entrada <= 0);
		invalida = 0;
		printf(" Informe a descricao do item: ");
		getchar();
		scanf("%[^\n]s",descricao_entrada);
		do
		{
			if(invalida == 1)
				printf(" Preco invalido! (Deve ser maior que 0)\n");
			printf(" Informe o preco do item: ");
			scanf("%f",&preco_entrada);
			invalida = 1;
		}
		while(preco_entrada <= 0);
		invalida = 0;
		
		/*
		 Condicoes: os valores dos itens, se mais baratos ou mais caros, sao passados as respectivas variaveis.
		*/
		if((preco_entrada <= barato_preco_entrada)||(primeiro_item == 1)) /* A variavel primeiro_item certifica que o primeiro item de cada tipo ->   */
		{                                                                 /* -> seja considerado mais barato. Ela recebe o valor 1 na declaracao ->   */
			primeiro_item = 0;                                            /* -> de variaveis e antes de cada loop que compreende o cadastro de ->     */
			barato_codigo_entrada = codigo_entrada;                       /* -> um tipo de item do cardapio.                                          */
			strcpy(barato_descricao_entrada, descricao_entrada);
			barato_preco_entrada = preco_entrada;
		}
		if(preco_entrada >= caro_preco_entrada)
		{
			caro_codigo_entrada = codigo_entrada;
			strcpy(caro_descricao_entrada, descricao_entrada);
			caro_preco_entrada = preco_entrada;
		}
		
		/*
		 Pergunta ao usuario se quer cadastrar mais um item do mesmo tipo.
		 Com checagem de consistencia para a resposta.
		*/
		printf("\n");
		do
		{
			if(invalida == 1)
				printf("Opcao invalida! (Apenas S ou N)\n");
			printf("Deseja cadastrar outro item deste tipo? (S/N) ");
			getchar();
			scanf("%c",&recadastro);
			invalida = 1;
		}
		while((recadastro != 's')&&(recadastro != 'S')&&(recadastro != 'n')&&(recadastro != 'N'));
		printf("\n");
		invalida = 0;
	}
	/*
	 O cadastro de um mesmo tipo se repete indefinidamente
	 ate o usuario fornecer 'N' ou 'n' como resposta para a pergunta anterior.
	*/
	while((recadastro == 's')||(recadastro == 'S'));
	
	
	/*
	 Para o cadastro dos proximos tipos de itens sao realizadas
	 as mesmas operacoes do item anterior, apenas alterando-se as variaveis utilizadas.
	*/
	
	
	/**
	  Cadastro dos pratos principais.
	**/
	primeiro_item = 1;
	printf("\n\n## PRATO PRINCIPAL ##\n\n");
	do
	{
		do
		{
			if(invalida == 1)
				printf(" Codigo invalido! (Deve ser maior que 0)\n");
			printf(" Informe o codigo do item: ");
			scanf("%d",&codigo_principal);
			invalida = 1;
		}
		while(codigo_principal <= 0);
		invalida = 0;
		printf(" Informe a descricao do item: ");
		getchar();
		scanf("%[^\n]s",descricao_principal);
		do
		{
			if(invalida == 1)
				printf(" Preco invalido! (Deve ser maior que 0)\n");
			printf(" Informe o preco do item: ");
			scanf("%f",&preco_principal);
			invalida = 1;
		}
		while(preco_principal <= 0);
		invalida = 0;		
		
		if((preco_principal <= barato_preco_principal)||(primeiro_item == 1))
		{
			primeiro_item = 0;
			barato_codigo_principal = codigo_principal;
			strcpy(barato_descricao_principal, descricao_principal);
			barato_preco_principal = preco_principal;
		}
		if(preco_principal >= caro_preco_principal)
		{
			caro_codigo_principal = codigo_principal;
			strcpy(caro_descricao_principal, descricao_principal);
			caro_preco_principal = preco_principal;
		}
		
		printf("\n");
		do
		{
			if(invalida == 1)
				printf("Opcao invalida! (Apenas S ou N)\n");
			printf("Deseja cadastrar outro item deste tipo? (S/N) ");
			getchar();
			scanf("%c",&recadastro);
			invalida = 1;
		}
		while((recadastro != 's')&&(recadastro != 'S')&&(recadastro != 'n')&&(recadastro != 'N'));
		printf("\n");
		invalida = 0;	
	}
	while((recadastro == 's')||(recadastro == 'S'));
	
	/**
	  Cadastro das sobremesas.
	**/
	primeiro_item = 1;
	printf("\n\n## SOBREMESA ##\n\n");
	do
	{
		do
		{
			if(invalida == 1)
				printf(" Codigo invalido! (Deve ser maior que 0)\n");
			printf(" Informe o codigo do item: ");
			scanf("%d",&codigo_sobremesa);
			invalida = 1;
		}
		while(codigo_sobremesa <= 0);
		invalida = 0;
		printf(" Informe a descricao do item: ");
		getchar();
		scanf("%[^\n]s",descricao_sobremesa);
		do
		{
			if(invalida == 1)
				printf(" Preco invalido! (Deve ser maior que 0)\n");
			printf(" Informe o preco do item: ");
			scanf("%f",&preco_sobremesa);
			invalida = 1;
		}
		while(preco_sobremesa <= 0);
		invalida = 0;		
		
		if((preco_sobremesa <= barato_preco_sobremesa)||(primeiro_item == 1))
		{
			primeiro_item = 0;
			barato_codigo_sobremesa = codigo_sobremesa;
			strcpy(barato_descricao_sobremesa, descricao_sobremesa);
			barato_preco_sobremesa = preco_sobremesa;
		}
		if(preco_sobremesa >= caro_preco_sobremesa)
		{
			caro_codigo_sobremesa = codigo_sobremesa;
			strcpy(caro_descricao_sobremesa, descricao_sobremesa);
			caro_preco_sobremesa = preco_sobremesa;
		}
		
		printf("\n");
		do
		{
			if(invalida == 1)
				printf("Opcao invalida! (Apenas S ou N)\n");
			printf("Deseja cadastrar outro item deste tipo? (S/N) ");
			getchar();
			scanf("%c",&recadastro);
			invalida = 1;
		}
		while((recadastro != 's')&&(recadastro != 'S')&&(recadastro != 'n')&&(recadastro != 'N'));
		printf("\n");
		invalida = 0;	
	}
	while((recadastro == 's')||(recadastro == 'S'));
	
	/**
	  Cadastro das bebidas.
	**/
	primeiro_item = 1;
	printf("\n\n## BEBIDA ##\n\n");
	do
	{
		do
		{
			if(invalida == 1)
				printf(" Codigo invalido! (Deve ser maior que 0)\n");
			printf(" Informe o codigo do item: ");
			scanf("%d",&codigo_bebida);
			invalida = 1;
		}
		while(codigo_bebida <= 0);
		invalida = 0;
		printf(" Informe a descricao do item: ");
		getchar();
		scanf("%[^\n]s",descricao_bebida);
		do
		{
			if(invalida == 1)
				printf(" Preco invalido! (Deve ser maior que 0)\n");
			printf(" Informe o preco do item: ");
			scanf("%f",&preco_bebida);
			invalida = 1;
		}
		while(preco_bebida <= 0);
		invalida = 0;		
		
		if((preco_bebida <= barato_preco_bebida)||(primeiro_item == 1))
		{
			primeiro_item = 0;
			barato_codigo_bebida = codigo_bebida;
			strcpy(barato_descricao_bebida, descricao_bebida);
			barato_preco_bebida = preco_bebida;
		}
		if(preco_bebida >= caro_preco_bebida)
		{
			caro_codigo_bebida = codigo_bebida;
			strcpy(caro_descricao_bebida, descricao_bebida);
			caro_preco_bebida = preco_bebida;
		}
		
		printf("\n");
		do
		{
			if(invalida == 1)
				printf("Opcao invalida! (Apenas S ou N)\n");
			printf("Deseja cadastrar outro item deste tipo? (S/N) ");
			getchar();
			scanf("%c",&recadastro);
			invalida = 1;
		}
		while((recadastro != 's')&&(recadastro != 'S')&&(recadastro != 'n')&&(recadastro != 'N'));
		printf("\n");
		invalida = 0;	
	}
	while((recadastro == 's')||(recadastro == 'S'));
	
	/**
	  Soma do preco dos itens mais baratos e mais caros. Fim do cadastro.
	**/
	barato_preco_total = barato_preco_entrada + barato_preco_principal + barato_preco_sobremesa + barato_preco_bebida;
	caro_preco_total = caro_preco_entrada + caro_preco_principal + caro_preco_sobremesa + caro_preco_bebida;
	printf("Cadastro concluido. Pressione ENTER para continuar...");
	getchar();
	getchar();
	
	/*
	 *   Saida de dados dos cardapios.
	 */
	
	
	/**
	  Exibicao do cardapio mais barato.
	  Mostra codigo, descricao e preco de cada um dos itens e ainda
	  mostra o preco total do cardapio.
	**/
	printf("\n\n*** CARDAPIO MAIS BARATO ***");
	printf("\n\n->Entrada:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", barato_codigo_entrada, barato_descricao_entrada, barato_preco_entrada);
	printf("\n->Prato Principal:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", barato_codigo_principal, barato_descricao_principal, barato_preco_principal);
	printf("\n->Sobremesa:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", barato_codigo_sobremesa, barato_descricao_sobremesa, barato_preco_sobremesa);
	printf("\n->Bebida:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", barato_codigo_bebida, barato_descricao_bebida, barato_preco_bebida);
	printf("\n\n-->Preco Total: %.2f", barato_preco_total);

	printf("\n\nPressione ENTER para continuar...");
	getchar();
	
	/**
	  Exibicao do cardapio mais caro.
	  Mostra codigo, descricao e preco de cada um dos itens e ainda
	  mostra o preco total do cardapio.
	**/
	printf("\n\n*** CARDAPIO MAIS CARO ***");
	printf("\n->Entrada:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", caro_codigo_entrada, caro_descricao_entrada, caro_preco_entrada);
	printf("\n->Prato Principal:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", caro_codigo_principal, caro_descricao_principal, caro_preco_principal);
	printf("\n->Sobremesa:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", caro_codigo_sobremesa, caro_descricao_sobremesa, caro_preco_sobremesa);
	printf("\n->Bebida:\n   Codigo: %d \n   Descricao: %s \n   Preco: %.2f", caro_codigo_bebida, caro_descricao_bebida, caro_preco_bebida);
	printf("\n\n-->Preco Total: %.2f", caro_preco_total);
	
	/**
	  Fim do programa.
	**/
	printf("\n\nPressione ENTER para encerrar o programa...");
	getchar();
    return(0);
}
