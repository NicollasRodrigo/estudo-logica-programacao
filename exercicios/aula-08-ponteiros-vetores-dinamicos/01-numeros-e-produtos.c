#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char nome[50]; float preco; } Produto;

int main(void) {
    int v[12], unicos[12], freq[12] = {0}, pares[12];
    int d = 0, np = 0, i, j, valido;
    long long total = 0;
    size_t k = 0;
    Produto *p;

    do {
        d = 0;
        for (i = 0; i < 12; i++) scanf("%d", &v[i]);

        for (i = 0; i < 12; i++) {
            for (j = 0; j < d && unicos[j] != v[i]; j++);
            if (j == d) unicos[d++] = v[i];
        }

        for (i = 0; i < d; i++) {
            freq[i] = 0;
            for (j = 0; j < 12; j++)
                if (v[j] == unicos[i]) freq[i]++;
        }

        valido = 1;
        for (i = 0; i < d; i++)
            if (unicos[i] < 0 && freq[i] % 2) {
                printf("O numero %d nao pode representar quantidade de produtos. Informe os 12 numeros novamente:\n", unicos[i]);
                valido = 0;
                break;
            }
    } while (!valido);

    for (i = 0; i < d; i++) {
        if (freq[i] % 2 == 0) pares[np++] = unicos[i];
        else total += unicos[i];
    }

    p = total ? malloc((size_t)total * sizeof *p) : NULL;
    if (total && !p) return 1;

    for (i = 0; i < d; i++)
        if (freq[i] % 2)
            for (j = 0; j < unicos[i]; j++) {
                scanf(" %49[^\n]", p[k].nome);
                scanf("%f", &p[k++].preco);
            }

    for (i = 0; i < np; i++)
        for (j = i + 1; j < np; j++)
            if (pares[i] < pares[j]) {
                int t = pares[i]; pares[i] = pares[j]; pares[j] = t;
            }

    for (size_t a = 0; a < k; a++)
        for (size_t b = a + 1; b < k; b++)
            if (strcmp(p[a].nome, p[b].nome) > 0) {
                Produto t = p[a]; p[a] = p[b]; p[b] = t;
            }

    printf("Numeros: ");
    for (i = 0; i < 12; i++) printf("%d ", v[i]);

    printf("\nOcorrencias:\n");
    for (i = 0; i < d; i++) printf("%d: %d\n", unicos[i], freq[i]);

    printf("Produtos:\n");
    for (size_t a = 0; a < k; a++) printf("%s - R$ %.2f\n", p[a].nome, p[a].preco);

    printf("Numeros com ocorrencias pares (decrescente): ");
    for (i = 0; i < np; i++) printf("%d ", pares[i]);
    printf("\n");

    free(p);
    return 0;
}
