#include <stdio.h>

void ordenar(int v[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (v[i] > v[j]) {
                t = v[i]; v[i] = v[j]; v[j] = t;
            }
}

int main(void) {
    int v[10], pares[10], impares[10], p = 0, n = 0, i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
        if (v[i] > 0 && v[i] % 2 == 0) pares[p++] = v[i];
        if (v[i] < 0 && v[i] % 2 != 0) impares[n++] = v[i];
    }

    ordenar(pares, p);
    ordenar(impares, n);

    printf("Positivos e pares: ");
    for (i = 0; i < p; i++) printf("%d ", pares[i]);
    printf("\nNegativos e impares: ");
    for (i = 0; i < n; i++) printf("%d ", impares[i]);
    printf("\n");
    return 0;
}
