#include <stdio.h>
#include <string.h>

int main () {
	int i = 0, i2 = 0, i3 = 0;
	char str[100], str2[100], aux[100];
	char troca1[7] = {'p','v','e','l','h','a','\0'};
	char troca2[6] = {'p','n','o','v','a','\0'};
	
	printf("\nInforme a string: ");
	scanf("%[^\n]s",str);
	getchar();

	while(i<=strlen(str)) {
		if((str[i]==' ')||(str[i]=='\0')) {
			aux[i2] = '\0';
			if(strlen(aux)==strlen(troca1)) {
				i2 = 0;
				while((aux[i2]==troca1[i2])&&(i2<strlen(aux))) {
					i2++;
				}
				if(i2==6) {
					i2 = 0;
					while(troca2[i2]!='\0') {
						str2[i3] = troca2[i2];
						i2++;
						i3++;
					}
					str2[i3] = ' ';
					i3++;
				}
				else {
					i2 = 0;
					while(aux[i2]!='\0') {
						str2[i3] = aux[i2];
						i2++;
						i3++;
					}
					str2[i3] = ' ';
					i3++;
				}
			}
			else {
				i2 = 0;
				while(aux[i2]!='\0') {
					str2[i3] = aux[i2];
					i2++;
					i3++;
				}
				str2[i3] = ' ';
				i3++;
			}
			i2 = 0;
		}
		else {	
			aux[i2] = str[i];
			i2++;
		}
		i++;
	}
	str2[i3-1] = '\0';
	
	printf("\n%s",str2);
	
	getchar();
	return(0);
}
