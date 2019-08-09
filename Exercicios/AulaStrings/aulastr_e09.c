#include <stdio.h>
#include <string.h>

int main () {
	int i = 0, i2 = 0, i3 = 0, i4 = 0;
	char str[100], str2[100], str_aux[100], aux;
	
	printf("\nInforme a string: ");
	scanf("%[^\n]s",str);
	getchar();

	while(i<=strlen(str)) {
		if((str[i]==' ')||(str[i]=='\0')) {
			str_aux[i2] = '\0';
			i2 = 0;
			i4 = strlen(str_aux)-1;
			while(i2!=i4) {
				aux = str_aux[i2];
				str_aux[i2] =  str_aux[i4];
				str_aux[i4] = aux;
				i2++;
				i4--;
			}
			i2 = 0;
			while(str_aux[i2]!='\0') {
				str2[i3] = str_aux[i2];
				i2++;
				i3++;
			}
			str2[i3] = ' ';
			i3++;
			i2 = 0;
		}
		else {	
			str_aux[i2] = str[i];
			i2++;
		}
		i++;
	}
	str2[i3-1] = '\0';
	
	printf("\n%s",str2);
	
	getchar();
	return(0);
}
