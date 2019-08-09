#include <stdio.h>

int main () {
	int num_alunos, i, i2, nota, maior_nota = 0;
	char gabarito[10], resposta_aluno[999][10];
	
	printf("\nInforme o gabarito: ");
	scanf("%[^\n]s",gabarito); 
	getchar();
	printf("Informe o numero de alunos: ");
	scanf("%d",&num_alunos);
	getchar();
	
	printf("\n");
	for(i=0; i<num_alunos; i++) {
		printf("Informe as respostas do aluno %d: ",i+1);
		scanf("%s",resposta_aluno[i]);
	}
	
	for(i=0; i<num_alunos; i++) {
		nota = 0;
		for(i2=0; i2<10; i2++) {
			if(resposta_aluno[i][i2]==gabarito[i2]) {
				nota++;
			}
		}
		if(nota>maior_nota) {
			maior_nota =  nota;
		}
	}
	
	printf("\nA maior nota foi: %d",maior_nota);	
	
	getchar();
	return(0);
}
