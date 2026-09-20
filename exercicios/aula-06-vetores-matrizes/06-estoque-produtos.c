/*
Slide 29 — Estoque de produtos

Uma loja possui 10 produtos. Armazenar em um array a quantidade disponível de cada produto.
O programa deve:
- mostrar a quantidade de cada produto;
- informar quais estão em estoque baixo (quantidade < 5);
- informar quais estão esgotados (quantidade = 0);
- contar quantos possuem mais de 20 unidades;
- informar qual produto possui a maior quantidade em estoque.
*/

#include <stdio.h>

int main(void) {
    int estoque[10];
    int acimaDe20 = 0;
    int maior = 0;
    int produtoMaior = 1;

    for (int i = 0; i < 10; i++) {
        printf("Quantidade do produto %d: ", i + 1);
        scanf("%d", &estoque[i]);

        if (estoque[i] > 20) {
            acimaDe20++;
        }

        if (i == 0 || estoque[i] > maior) {
            maior = estoque[i];
            produtoMaior = i + 1;
        }
    }

    printf("\n--- Estoque ---\n");

    for (int i = 0; i < 10; i++) {
        printf("Produto %d: %d\n", i + 1, estoque[i]);
    }

    printf("\nEstoque baixo:\n");
    int encontrouBaixo = 0;

    for (int i = 0; i < 10; i++) {
        if (estoque[i] < 5) {
            printf("Produto %d\n", i + 1);
            encontrouBaixo = 1;
        }
    }

    if (!encontrouBaixo) {
        printf("Nenhum produto.\n");
    }

    printf("\nProdutos esgotados:\n");
    int encontrouEsgotado = 0;

    for (int i = 0; i < 10; i++) {
        if (estoque[i] == 0) {
            printf("Produto %d\n", i + 1);
            encontrouEsgotado = 1;
        }
    }

    if (!encontrouEsgotado) {
        printf("Nenhum produto.\n");
    }

    printf("\nProdutos com mais de 20 unidades: %d\n", acimaDe20);
    printf("Maior estoque: produto %d, com %d unidade(s).\n", produtoMaior, maior);

    return 0;
}
