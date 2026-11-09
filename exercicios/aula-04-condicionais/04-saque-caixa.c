#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int resolver(int i, int restante, int notas[], int disponiveis[],
             signed char *memo, int *escolha, size_t largura) {
    size_t estado;
    int qtd;

    if (restante == 0) return 1;
    if (i == 6) return 0;

    estado = (size_t)i * largura + (size_t)restante;
    if (memo[estado] != -1) return memo[estado];

    qtd = disponiveis[i];
    if (qtd > restante / notas[i]) qtd = restante / notas[i];

    for (int n = qtd; n >= 0; n--)
        if (resolver(i + 1, restante - n * notas[i], notas,
                     disponiveis, memo, escolha, largura)) {
            escolha[estado] = n;
            memo[estado] = 1;
            return 1;
        }

    memo[estado] = 0;
    return 0;
}

int main(void) {
    int notas[6] = {200, 100, 50, 20, 10, 5};
    int qtd[6], usar[6] = {0}, saque, total = 0;
    signed char *memo;
    int *escolha;
    size_t largura, estados, restante;

    for (int i = 0; i < 6; i++) {
        printf("Quantidade de notas de %d: ", notas[i]);
        scanf("%d", &qtd[i]);
        if (qtd[i] < 0) qtd[i] = 0;
        if (qtd[i] > 0) qtd[i]--;
    }

    printf("Valor do saque: ");
    scanf("%d", &saque);

    if (saque <= 0 || saque % 5 != 0) {
        printf("Valor invalido.\n");
        return 0;
    }

    largura = (size_t)saque + 1;
    if (largura > (size_t)-1 / 6 / sizeof(int)) return 1;
    estados = 6 * largura;

    memo = malloc(estados * sizeof *memo);
    escolha = malloc(estados * sizeof *escolha);
    if (!memo || !escolha) {
        free(memo);
        free(escolha);
        return 1;
    }

    memset(memo, -1, estados * sizeof *memo);

    if (!resolver(0, saque, notas, qtd, memo, escolha, largura)) {
        printf("Saque impossivel sem violar a regra do caixa.\n");
    } else {
        restante = (size_t)saque;
        for (int i = 0; i < 6; i++) {
            usar[i] = restante ? escolha[(size_t)i * largura + restante] : 0;
            restante -= (size_t)usar[i] * notas[i];
            total += usar[i];
        }

        for (int i = 0; i < 6; i++)
            if (usar[i]) printf("R$ %d: %d nota(s)\n", notas[i], usar[i]);

        printf("Total de cedulas: %d\n", total);
    }

    free(memo);
    free(escolha);
    return 0;
}
