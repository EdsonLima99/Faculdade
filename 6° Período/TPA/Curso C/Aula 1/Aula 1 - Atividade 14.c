// 14. Fa�a um programa em C que leia a base e a altura de um ret�ngulo e imprima o
// per�metro (base + altura) e a �rea (base * altura).

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float base, altura, perimetro, area;

	printf("Informe a base do retangulo: ");
	scanf("%f", &base);

	printf("Informe a altura do retangulo: ");
	scanf("%f", &altura);

	perimetro = base + altura;
	area = base * altura;

	printf("Perimetro do retangulo: %.2f\n", perimetro);
	printf("Altura do retangulo: %.2f", area);
}
