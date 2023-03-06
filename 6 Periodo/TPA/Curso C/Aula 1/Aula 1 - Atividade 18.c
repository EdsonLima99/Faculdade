// 18. Fa�a um programa em C que calcule a quantidade de litros de combust�vel consumidos em uma viagem,
// sabendo-se que o carro tem autonomia de 12 km por litro de combust�vel.
// O programa dever� ler o tempo decorrido na viagem e a
// velocidade m�dia e aplicar as f�rmulas:
// D = T � V
// L = D
//    ---
//    12
// Em que:
//� D = Dist�ncia percorrida em horas
//� T = Tempo decorrido
//� V = Velocidade m�dia
//� L = Litros de combust�vel consumidos
// Ao final, o programa dever� imprimir a dist�ncia percorrida e a quantidade de
// litros consumidos na viagem.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float tempo, velocidadeMedia, distancia, litros;

	printf("Informe o tempo da viagem: ");
	scanf("%f", &tempo);

	printf("Informe a velocidade media da viagem: ");
	scanf("%f", &velocidadeMedia);

	distancia = tempo * velocidadeMedia;

	litros = distancia / 12;

	printf("Distancia percorrida: %.2f\n", distancia);
	printf("Quantidade de litros consumidos na viagem: %.2f", litros);
}
