#include <stdio.h>

int main(void) {
    int notas[6] = {200, 100, 50, 20, 10, 5};
    int qtd[6], usar[6], saque, restante, total = 0;

    for (int i = 0; i < 6; i++) {
        printf("Quantidade de notas de %d: ", notas[i]);
        scanf("%d", &qtd[i]);
        if (qtd[i] < 0) qtd[i] = 0;
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
        usar[i] = restante / notas[i];
        if (usar[i] > disponiveis) usar[i] = disponiveis;
        restante -= usar[i] * notas[i];
        total += usar[i];
    }

    if (restante != 0) {
        printf("Saque impossivel sem violar a regra do caixa.\n");
        return 0;
    }

    for (int i = 0; i < 6; i++)
        if (usar[i]) printf("R$ %d: %d nota(s)\n", notas[i], usar[i]);

    printf("Total de cedulas: %d\n", total);
    return 0;
}
