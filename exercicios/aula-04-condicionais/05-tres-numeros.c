/*
Questão 05 — Análise de três números

Leia três números inteiros A, B e C.
Informe:
- maior valor;
- menor valor;
- valor intermediário;
- valores repetidos;
- se os três são iguais;
- se estão em ordem crescente;
- se estão em ordem decrescente.

Restrição: resolver utilizando apenas comparações condicionais.
*/

#include <stdio.h>

int main(void) {
    int a, b, c, maior, menor;

    printf("A B C: ");
    scanf("%d%d%d", &a, &b, &c);

    maior = a;
    if (b > maior) maior = b;
    if (c > maior) maior = c;

    menor = a;
    if (b < menor) menor = b;
    if (c < menor) menor = c;

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Diferenca: %d\n", maior - menor);

    if (a == b && b == c) printf("Tres iguais.\n");
    else if (a == b || a == c || b == c) printf("Ha repetidos.\n");
    else printf("Sem repetidos.\n");

    return 0;
}
