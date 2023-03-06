// 12. Fa�a um programa em C que leia um n�mero real e calcule o quadrado deste
// n�mero. Ao final, o programa deve imprimir o resultado do c�lculo.

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

void main()
{
	float num, quadrado;

	printf("Informe o numero: ");
	scanf("%f", &num);

	quadrado = num * num;
	// Ou
	// quadrado = pow(num,2);

	printf("O quadrado do numero e: %.2f", quadrado);
}
