/*
Slides 22–23 — Matriz 3x3

Gerar uma matriz 3x3 de inteiros e exibi-la,
separando os elementos da mesma linha por "-"
e as linhas por nova linha.
*/

#include <stdio.h>

int main(void) {
    int matriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j > 0) {
                printf(" - ");
            }
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
