#include <stdio.h>

int main(void) {
    int estoque[10], acimaDe20 = 0, maior = 0, produtoMaior = 1;

    for (int i = 0; i < 10; i++) {
        do {
            printf("Quantidade do produto %d: ", i + 1);
            scanf("%d", &estoque[i]);
        } while (estoque[i] < 0);

        if (estoque[i] > 20) acimaDe20++;
        if (i == 0 || estoque[i] > maior) {
            maior = estoque[i];
            produtoMaior = i + 1;
        }
    }

    printf("\n--- Estoque ---\n");
    for (int i = 0; i < 10; i++)
        printf("Produto %d: %d\n", i + 1, estoque[i]);

    printf("\nEstoque baixo:\n");
    int encontrou = 0;
    for (int i = 0; i < 10; i++)
        if (estoque[i] < 5) {
            printf("Produto %d\n", i + 1);
            encontrou = 1;
        }
    if (!encontrou) printf("Nenhum produto.\n");

    printf("\nProdutos esgotados:\n");
    encontrou = 0;
    for (int i = 0; i < 10; i++)
        if (estoque[i] == 0) {
            printf("Produto %d\n", i + 1);
            encontrou = 1;
        }
    if (!encontrou) printf("Nenhum produto.\n");

    printf("\nProdutos com mais de 20 unidades: %d\n", acimaDe20);
    printf("Maior estoque: produto %d, com %d unidade(s).\n", produtoMaior, maior);
    return 0;
}
