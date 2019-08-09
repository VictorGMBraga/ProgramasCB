#include <stdio.h>
#include <math.h>

int main ()
{
	float xo,yo,alt,lar,x,y;
	
	printf("\nInforme a coordenada x da origem: ");
	scanf("%f",&xo);
	printf("Informe a coordenada y da origem: ");
	scanf("%f",&yo);
	printf("\nInforme a largura do retangulo: ");
	scanf("%f",&lar);
	printf("Informe a altura do retangulo: ");
	scanf("%f",&alt);
	printf("\nInforme a coordenada x do ponto: ");
	scanf("%f",&x);
	printf("Informe a coordenada y do ponto: ");
	scanf("%f",&y);
	if (x==xo&&y==yo)
		printf("\nPonto igual a origem.\n");
	else
	{
		if (x<xo||x>(xo+lar)||y<yo||y>(yo+alt))
			printf("\nPonto fora do retangulo.\n");
		else
		{
			if (x==yo||x==(yo+alt)||y==xo||y==(xo+lar))
				printf("\nPonto em uma linha do retangulo.\n");
			else
				printf("\nPonto dentro do retangulo.\n");
		}
	}
	return(0);
}
