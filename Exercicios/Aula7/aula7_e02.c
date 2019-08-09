#include <stdio.h>

void trocaValor (int *u, int *v, int *x, int *y ) {
    *u = 1;
    *v = 2;
    *x = 3;
    *y = 4;
}

int main() {
    int a = 1, b = 2, c = 3, z = 100;

    printf ("\na = %d, b = %d, c = %d, z= %d \n",a,b,c,z);
    printf ("\nApos a funcao:\n");
    trocaValor(&a, &b, &c, &z);
    printf ("a = %d, b = %d, c = %d, z= %d \n",a,b,c,z);
	
	getchar();
    return(0);
}
