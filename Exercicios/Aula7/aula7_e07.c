#include <stdio.h>

int prod (int a, int b) {
	int result = 0;
	
	while(a>=1) {
		if((a%2)!=0) {
			result += b;
		}
		a = a/2;
		b = b*2;
	}
	
	return(result);
}

int main () {
    int i, num[10][2];
	
	printf("\n");
	for(i=0; i<10; i++) {
		printf("Informe 1o numero do par %d: ",i+1);
		scanf("%d",&num[i][0]);
		printf("Informe 2o numero do par %d: ",i+1);
		scanf("%d",&num[i][1]);
	}


	for(i=0; i<10; i++) {
		printf("\n");
		printf("%d x %d = %d",num[i][0],num[i][1],prod(num[i][0],num[i][1]));
	}
	
	getchar();
	getchar();
    return(0);
}
