#include <stdio.h>

void readmat (int mat[][3]) {
	int i, i2;
	
	printf("\n");
	for(i=0; i<3; i++) {
		for(i2=0; i2<3; i2++) {
			printf("Informe o elemento %d,%d da matriz: ",i+1,i2+1);
			scanf("%d",&mat[i][i2]);
		}
	}
}

void showinv (int mat[][3]) {
	int i, i2;
	
	printf("\n");
	for(i=2; i>=0; i--) {
		for(i2=2; i2>=0; i2--) {
			printf("%d  ",mat[i][i2]);
		}
		printf("\n");
	}
}

int main () {
	int mat[3][3];
	
	readmat(mat);
	showinv(mat);
	
	getchar();
	getchar();
	return(0);
}
