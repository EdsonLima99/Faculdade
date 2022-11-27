// 10. Fa�a um programa em C que leia tr�s n�meros reais e calcule a m�dia aritm�tica
// destes n�meros. Ao final, o programa deve imprimir o resultado do c�lculo.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float num1, num2, num3, media;

	printf("Informe o primeiro numero: ");
	scanf("%f", &num1);

	printf("Informe o segundo numero: ");
	scanf("%f", &num2);

	printf("Informe o terceiro numero: ");
	scanf("%f", &num3);

	media = (num1 + num2 + num3) / 3;

	printf("A media aritimetica e: %.2f", media);
}
