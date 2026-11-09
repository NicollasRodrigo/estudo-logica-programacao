#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char nome[50];
    double preco;
} Produto;

int main(void) {
    int numeros[12], distintos[12], ocorrencias[12] = {0};
    int pares[12], quantidade_distintos = 0, quantidade_pares = 0;
    int i, j, valido;
    size_t total_produtos = 0, k = 0;
    Produto *produtos = NULL;

    do {
        valido = 1;
        quantidade_distintos = 0;

        printf("Informe 12 numeros inteiros:\n");
        for (i = 0; i < 12; i++) {
            if (scanf("%d", &numeros[i]) != 1) return 1;
        }

        for (i = 0; i < 12; i++) {
            for (j = 0; j < quantidade_distintos &&
                        distintos[j] != numeros[i]; j++);
            if (j == quantidade_distintos)
                distintos[quantidade_distintos++] = numeros[i];
        }

        for (i = 0; i < quantidade_distintos; i++) {
            ocorrencias[i] = 0;
            for (j = 0; j < 12; j++)
                if (numeros[j] == distintos[i])
                    ocorrencias[i]++;
        }

        total_produtos = 0;
        for (i = 0; i < quantidade_distintos; i++) {
            if (ocorrencias[i] % 2 != 0) {
                if (distintos[i] < 0) {
                    printf("O numero %d tem ocorrencia impar e nao pode "
                           "representar uma quantidade de produtos.\n",
                           distintos[i]);
                    valido = 0;
                    break;
                }
                total_produtos += (size_t)distintos[i];
            }
        }
    } while (!valido);

    for (i = 0; i < quantidade_distintos; i++) {
        if (ocorrencias[i] % 2 == 0)
            pares[quantidade_pares++] = distintos[i];
    }

    if (total_produtos > 0) {
        produtos = malloc(total_produtos * sizeof *produtos);
        if (produtos == NULL) return 1;
    }

    for (i = 0; i < quantidade_distintos; i++) {
        if (ocorrencias[i] % 2 != 0) {
            for (j = 0; j < distintos[i]; j++) {
                printf("Produto %d de %d para o numero %d. Nome: ",
                       j + 1, distintos[i], distintos[i]);
                if (scanf(" %49[^\n]", produtos[k].nome) != 1) {
                    free(produtos);
                    return 1;
                }
                printf("Preco unitario: ");
                if (scanf("%lf", &produtos[k].preco) != 1) {
                    free(produtos);
                    return 1;
                }
                k++;
            }
        }
    }

    for (i = 0; i < quantidade_pares; i++) {
        for (j = i + 1; j < quantidade_pares; j++) {
            if (pares[i] < pares[j]) {
                int temp = pares[i];
                pares[i] = pares[j];
                pares[j] = temp;
            }
        }
    }

    for (size_t a = 0; a < k; a++) {
        for (size_t b = a + 1; b < k; b++) {
            if (strcmp(produtos[a].nome, produtos[b].nome) > 0) {
                Produto temp = produtos[a];
                produtos[a] = produtos[b];
                produtos[b] = temp;
            }
        }
    }

    printf("\nNumeros informados: ");
    for (i = 0; i < 12; i++) printf("%d ", numeros[i]);

    printf("\n\nQuantidade de ocorrencias:\n");
    for (i = 0; i < quantidade_distintos; i++)
        printf("%d: %d vez(es)\n", distintos[i], ocorrencias[i]);

    printf("\nProdutos em ordem alfabetica:\n");
    if (k == 0) printf("Nenhum produto cadastrado.\n");
    for (size_t a = 0; a < k; a++)
        printf("%s - R$ %.2f\n", produtos[a].nome, produtos[a].preco);

    printf("\nNumeros com ocorrencias pares (ordem decrescente): ");
    for (i = 0; i < quantidade_pares; i++) printf("%d ", pares[i]);
    printf("\n");

    free(produtos);
    return 0;
}
