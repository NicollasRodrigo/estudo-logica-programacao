/*
Questão 03 — Sistema de classificação de triângulos

Leia três valores inteiros representando os lados de um triângulo.
O programa deve:
- verificar se os valores podem formar um triângulo;
- classificar como equilátero, isósceles ou escaleno;
- informar o tipo de ângulo;
- informar quando não formar um triângulo.
Restrição: não utilizar funções prontas para classificação.
*/

#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Tres lados: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a) {
        printf("Nao forma triangulo.\n");
        return 0;
    }

    if (a == b && b == c) printf("Equilatero\n");
    else if (a == b || a == c || b == c) printf("Isosceles\n");
    else printf("Escaleno\n");

    return 0;
}
