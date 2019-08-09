#include <stdio.h> 
 
float fat(int x) {
	int i;
	float p;
	
	p=1;
	for (i=1;i<=x;i++){
		p=p*i;
	}
	return(p);
}

int main() {
	int n,k;
	float c;
 
	printf("\nForneca o valor de n: ");
	scanf("%d",&n);
	printf("Forneca o valor de k: ");
	scanf("%d",&k);
 
	c=fat(n)/(fat(k)*fat(n-k));
	printf("\n%.2f",c);
	
	getchar();
	getchar();
	return(0);
} 
