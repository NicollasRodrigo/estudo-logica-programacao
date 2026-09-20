/*
Slide 20 — Análise de três números

Leia três números inteiros A, B e C.
Informe:
- maior valor;
- menor valor;
- valor intermediário;
- se existem valores repetidos;
- se os três são iguais;
- se estão em ordem crescente;
- se estão em ordem decrescente.

Restrição: resolver utilizando apenas comparações condicionais.
*/

#include <stdio.h>

int main(void) {
    int a, b, c;
    int maior, menor, intermediario;

    printf("A B C: ");
    scanf("%d %d %d", &a, &b, &c);

    maior = a;
    if (b > maior) maior = b;
    if (c > maior) maior = c;

    menor = a;
    if (b < menor) menor = b;
    if (c < menor) menor = c;

    if ((a >= b && a <= c) || (a <= b && a >= c))
        intermediario = a;
    else if ((b >= a && b <= c) || (b <= a && b >= c))
        intermediario = b;
    else
        intermediario = c;

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Intermediario: %d\n", intermediario);

    if (a == b && b == c)
        printf("Os tres valores sao iguais.\n");
    else if (a == b || a == c || b == c)
        printf("Existem valores repetidos.\n");
    else
        printf("Nao existem valores repetidos.\n");

    if (a < b && b < c)
        printf("Ordem crescente.\n");
    else if (a > b && b > c)
        printf("Ordem decrescente.\n");
    else
        printf("Nao estao em ordem crescente nem decrescente.\n");

    return 0;
}
