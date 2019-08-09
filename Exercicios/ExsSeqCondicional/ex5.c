#include <stdio.h>

int main ()
{
	float qmac,qmor,pmac,pmor,ptot;
	
	printf("\nInforme a quantidade em Kg de macas: ");
	scanf("%f",&qmac);
	printf("Informe a quantidade em Kg de morangos: ");
	scanf("%f",&qmor);
	if (qmac>=5.00)
		pmac=qmac*1.10;
	else
		pmac=qmac*1.50;
	if (qmor>=5.00)
		pmor=qmor*1.80;
	else
		pmor=qmor*2.00;
	if ((qmac+qmor)>8.00 || (pmac+pmor)>25.00)
		ptot=(pmac+pmor)*0.90;
	else
		ptot=(pmac+pmor);
	printf("\nO valor a ser pago e de: RS %.2f\n\n",ptot);
	return(0);
}
