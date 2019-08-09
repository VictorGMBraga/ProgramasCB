#include <stdio.h>

int main () {
	int i, i2 = 0, n;
	char s1[100],s2[100];
	
	printf("\nInforme a string 1: ");
	scanf("%[^\n]s",s1);
	printf("\n");
	do {
		printf("Copiar quantos caracteres da string 1 para a string 2? ");
		scanf("%d",&n);
	} while((n>100)||(n<1));
	do {
		printf("Copiar a partir de qual caracter? ");
		scanf("%d",&i);
		i = i-1;
	} while((i<1)||(i+(n-1)>=100));
	
	while(i2<n) {
		s2[i2] = s1[i];
		i++;
		i2++;
	}
	s2[i2] = '\0';
	
	printf("\nA string 2 e: %s",s2);	
	
	getchar();
	return(0);
}
