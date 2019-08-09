#include <stdio.h>

int main ()
{
	int quant,n1,n5,n10,n25,n50,n100;
	printf("\nInforme a quantia em dinheiro: ");
	scanf("%d",&quant);
	n100=quant/100;
	quant=quant%100;
	n50=quant/50;
	quant=quant%50;
	n25=quant/25;
	quant=quant%25;
	n10=quant/10;
	quant=quant%10;
	n5=quant/5;
	n1=quant%5;
	printf("%d,%d,%d,%d,%d,%d",n100,n50,n25,n10,n5,n1);
	return(0);
}
