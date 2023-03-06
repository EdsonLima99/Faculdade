// 17. Fa�a um programa em C que calcule a convers�o entre graus cent�grados e Fahrenheit.
// Para isso, leia o valor em cent�grados e calcule com base na f�rmula a
// seguir. Ap�s calcular o programa deve imprimir o resultado da convers�o.
// F = 9�C + 160
//     ---------
//         5
// Em que:
//� F = Graus em Fahrenheit
//� C = Graus cent�grados

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float celsius, fahrenheit;

	printf("Informe a temperatura em Celsius: ");
	scanf("%f", &celsius);

	fahrenheit = ((9 * celsius) + 160) / 5;

	printf("Temperatura em Fahrenheit: %.2f", fahrenheit);
}
