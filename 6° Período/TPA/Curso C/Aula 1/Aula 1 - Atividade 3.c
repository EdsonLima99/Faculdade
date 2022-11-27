// 3. Fa�a um programa em C que imprima a m�dia aritm�tica entre os n�meros 5, 8, 12.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float num1, num2, num3, media;

	num1 = 5;
	num2 = 8;
	num3 = 12;

	media = (num1 + num2 + num3) / 3;

	printf("A media aritimetica e: %.2f", media);
}
