/*
Slide 19 — Saque no caixa

O caixa possui notas de R$ 200, R$ 100, R$ 50, R$ 20, R$ 10 e R$ 5.
O usuário informa o valor do saque.
Verifique se o saque é válido e possível, quais notas serão entregues,
a quantidade de cada nota e o total de cédulas.
O caixa deve preservar pelo menos uma nota de cada denominação disponível.
*/

#include <stdio.h>

int main(void) {
    int notas[6] = {200, 100, 50, 20, 10, 5};
    int qtd[6];
    int saque, restante, totalCedulas = 0;

    for (int i = 0; i < 6; i++) {
        printf("Quantidade de notas de %d: ", notas[i]);
        scanf("%d", &qtd[i]);

        if (qtd[i] < 0)
            qtd[i] = 0;
    }

    printf("Valor do saque: ");
    scanf("%d", &saque);

    if (saque <= 0) {
        printf("Valor invalido.\n");
        return 0;
    }

    restante = saque;

    for (int i = 0; i < 6; i++) {
        int disponiveis = qtd[i] > 0 ? qtd[i] - 1 : 0;
        int usar = restante / notas[i];

        if (usar > disponiveis)
            usar = disponiveis;

        restante -= usar * notas[i];
        totalCedulas += usar;

        if (usar > 0)
            printf("R$ %d: %d nota(s)\n", notas[i], usar);
    }

    if (restante != 0) {
        printf("Saque impossivel sem violar a regra do caixa.\n");
        return 0;
    }

    printf("Total de cedulas: %d\n", totalCedulas);
    printf("Saque realizado.\n");

    return 0;
}
