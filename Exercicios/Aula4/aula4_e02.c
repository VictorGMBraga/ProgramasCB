/***
Imprime na tela os n�meros de 1 a 5, cinco vezes. 
Sa�da:  1
		1 2
		1 2 3   
		1 2 3 4
		1 2 3 4 5
***/ 

#include <stdio.h> 

int main(){
	int i,j;
	
    for(j=1;j<=5;j++){
		i=0;
		do{
			i++;
			printf("%d ",i);
		}while(i<j);
		printf("\n");
    }
    getchar();
    return(0);
}
