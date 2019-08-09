#include <stdio.h>
#include <math.h>

float pideal (char *sex, float *alt) {
	if((*sex=='m')||(*sex=='M')) {
		return(72.7*(*alt)-58);
	}
	else {
		return(62.1*(*alt)-44.7);
	}
}

int main () {
	int n, i;
	float alt[1000];
	char sex[1000];
	
	printf("\nInforme o numero de pessoas: ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++) {
		getchar();
		printf("Informe o sexo da pessoa %d: ",i+1);
		scanf("%c",&sex[i]);
		printf("Informe a altura da pessoa %d: ",i+1);
		scanf("%f",&alt[i]);
	}
	
	getchar();
	for(i=0; i<n; i++) {
		printf("\nO peso ideal da pessoa %d e: %.1f",i+1,pideal(&sex[i],&alt[i]));
	}
	
	getchar();
	return(0);
}
