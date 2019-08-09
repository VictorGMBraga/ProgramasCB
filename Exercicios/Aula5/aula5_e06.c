#include <stdio.h>

int main () {
    float mai = -99999.0, men = 99999.0, temp[12];
	int i, mes_mai, mes_men;

	printf("\n");
	for(i=0; i<12; i++) {
		printf("Digite a temperatura media do mes %d: ",i+1);
		scanf("%f",&temp[i]);
	}
	
	for(i=0; i<12; i++) {
		if(temp[i]>mai) {
			mai = temp[i];
			mes_mai = i;
		}
		else {
			if(temp[i]<men) {
				men = temp[i];
				mes_men = i;
			}
		}
	}
	
	printf("\nA maior temperatura e %.1f no mes %d.",mai,mes_mai+1);
	printf("\nA menor temperatura e %.1f no mes %d.",men,mes_men+1);
	
	getchar();
	getchar();
	return 0;
}
