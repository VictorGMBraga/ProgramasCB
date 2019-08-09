#include <stdio.h>

int main () {
	int i, i2 = 0;
	char STR1[50], STR2[50], STR3[100];
	
	printf("\nInforme a string 1: ");
	scanf("%[^\n]s",STR1); 
	getchar();
	printf("Informe a string 2: ");
	scanf("%[^\n]s",STR2); 
	getchar();
	
	for(i=0; STR1[i]!='\0'; i++) {
		STR3[i2] = STR1[i];
		i2++;
	}
	for(i=0; STR2[i]!='\0'; i++) {
		STR3[i2] = STR2[i];
		i2++;
	}
	
	printf("\nA string 3 e: %s",STR3);	
	
	getchar();
	return(0);
}
