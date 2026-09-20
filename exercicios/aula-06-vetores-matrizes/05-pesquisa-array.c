/*
Slide 28 — Pesquisa em array

Ler 10 números inteiros e armazená-los em um array.
Depois, pedir um número para pesquisar e informar:
- se foi encontrado;
- quantas vezes aparece;
- as posições em que foi encontrado.
*/

#include <stdio.h>

int main(void) {
    int numeros[10];
    int pesquisa;
    int quantidade = 0;

    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Numero para pesquisar: ");
    scanf("%d", &pesquisa);

    for (int i = 0; i < 10; i++) {
        if (numeros[i] == pesquisa) {
            quantidade++;
        }
    }

    if (quantidade == 0) {
        printf("O numero %d nao foi encontrado.\n", pesquisa);
        return 0;
    }

    printf("O numero %d foi encontrado %d vez(es).\n", pesquisa, quantidade);
    printf("Posicoes: ");

    int primeira = 1;

    for (int i = 0; i < 10; i++) {
        if (numeros[i] == pesquisa) {
            if (!primeira) {
                printf(", ");
            }
            printf("%d", i + 1);
            primeira = 0;
        }
    }

    printf("\n");
    return 0;
}
