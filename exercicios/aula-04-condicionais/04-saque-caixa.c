/*
Questão 04 — Saque no caixa

Um caixa possui notas de R$ 200, R$ 100, R$ 50, R$ 20, R$ 10 e R$ 5.
O usuário informa o valor do saque.
Verifique se o saque é válido e possível, quais notas serão entregues,
a quantidade de cada nota e o total de cédulas.
O caixa deve preservar pelo menos uma nota de cada denominação disponível.
*/

#include <stdio.h>

int main(void) {
    int notas[6] = {200, 100, 50, 20, 10, 5};
    int qtd[6];
    int saque, restante;

    for (int i = 0; i < 6; i++) {
        printf("Quantidade de notas de %d: ", notas[i]);
        scanf("%d", &qtd[i]);
    }

    printf("Saque: ");
    scanf("%d", &saque);

    restante = saque;

    for (int i = 0; i < 6; i++) {
        int usar = restante / notas[i];

        if (usar > qtd[i] - 1)
            usar = qtd[i] - 1;

        restante -= usar * notas[i];

        if (usar)
            printf("%d x R$%d\n", usar, notas[i]);
    }

    if (restante)
        printf("Saque impossivel.\n");
    else
        printf("Saque realizado.\n");

    return 0;
}
