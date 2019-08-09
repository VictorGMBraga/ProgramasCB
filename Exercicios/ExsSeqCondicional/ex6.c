#include <stdio.h>

#define	pval vval/(eleit/100.00)
#define	pbra vbra/(eleit/100.00)
#define	pnul vnul/(eleit/100.00)

int main ()
{
	int eleit,vval,vbra,vnul;
	printf("\nInforme o numero total de eleitores: ");
	scanf("%d",&eleit);
	printf("Informe o numero de votos validos: ");
	scanf("%d",&vval);
	printf("Informe o numero de votos brancos: ");
	scanf("%d",&vbra);
	printf("Informe o numero de votos nulos: ");
	scanf("%d",&vnul);
	if ((vval+vbra+vnul)==eleit)
	{
		printf("\nOs votos validos representam %.1f%c do total.",pval,37);
		printf("\nOs votos brancos representam %.1f%c do total.",pbra,37);
		printf("\nOs votos nulos representam %.1f%c do total.\n\n",pnul,37);
	}
	else
	{
		printf("\nO numero de votos nao pode ser diferente do numero de eleitores.\n\n");
	}
	return(0);
}
