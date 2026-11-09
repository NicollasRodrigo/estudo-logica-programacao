#include <stdio.h>

void ordenar(int v[], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main(void) {
    int numeros[10], pares[10], impares[10];
    int quantidade_pares = 0, quantidade_impares = 0;
    int i;

    printf("Informe 10 valores inteiros:\n");

    for (i = 0; i < 10; i++) {
        if (scanf("%d", &numeros[i]) != 1) return 1;

        if (numeros[i] > 0 && numeros[i] % 2 == 0)
            pares[quantidade_pares++] = numeros[i];

        if (numeros[i] < 0 && numeros[i] % 2 != 0)
            impares[quantidade_impares++] = numeros[i];
    }

    ordenar(pares, quantidade_pares);
    ordenar(impares, quantidade_impares);

    printf("Positivos e pares (ordem crescente): ");
    for (i = 0; i < quantidade_pares; i++) printf("%d ", pares[i]);

    printf("\nNegativos e impares (ordem crescente): ");
    for (i = 0; i < quantidade_impares; i++) printf("%d ", impares[i]);

    printf("\n");
    return 0;
}
