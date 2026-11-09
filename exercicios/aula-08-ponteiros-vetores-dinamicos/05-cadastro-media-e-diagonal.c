#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define P 4

typedef struct {
    char nome[50];
    int idade, qtd;
    long double id, media, *valores;
} Pessoa;

long double fatorial(int n) {
    long double f = 1;
    int i;
    for (i = 2; i <= n; i++) f *= i;
    return f;
}

int existe(Pessoa p[], int n, long double id) {
    int i;
    for (i = 0; i < n; i++) if (p[i].id == id) return 1;
    return 0;
}

long double mediaPonderada(Pessoa p) {
    long double soma = 0, pesos = 0;
    int i;
    for (i = 0; i < p.qtd; i++) {
        soma += p.valores[i] * (i + 1);
        pesos += i + 1;
    }
    return soma / pesos;
}

int main(void) {
    Pessoa p[P] = {0}, t;
    long double lados[2], diagonal;
    int nlados = 0, i, j;

    for (i = 0; i < P; i++) {
        scanf(" %49[^\n]", p[i].nome);
        scanf("%d%d", &p[i].idade, &p[i].qtd);
        if (p[i].idade < 0 || p[i].qtd < 1) return 1;

        p[i].id = fatorial(p[i].idade) / 2.0L;
        if (!isfinite(p[i].id)) return 1;

        if (existe(p, i, p[i].id)) {
            p[i].id = powl(fatorial(p[i].idade / 2), p[i].qtd);
            if (!isfinite(p[i].id)) p[i].id = 1;
            while (existe(p, i, p[i].id))
                p[i].id = nextafterl(p[i].id, INFINITY);
        }

        p[i].valores = malloc((size_t)p[i].qtd * sizeof *p[i].valores);
        if (!p[i].valores) return 1;

        for (j = 0; j < p[i].qtd; j++) {
            scanf("%Lf", &p[i].valores[j]);
            if (p[i].valores[j] >= 0 && nlados < 2)
                lados[nlados++] = p[i].valores[j];
        }
        p[i].media = mediaPonderada(p[i]);
    }

    for (i = 0; i < P; i++)
        for (j = i + 1; j < P; j++)
            if (strcmp(p[i].nome, p[j].nome) > 0) {
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    printf("CLASSIFICACAO FINAL\n");
    if (nlados < 2) {
        printf("Nao foi possivel calcular a diagonal.\n");
        for (i = 0; i < P; i++) printf("%s - Classificacao indisponivel\n", p[i].nome);
    } else {
        diagonal = sqrtl(lados[0] * lados[0] + lados[1] * lados[1]);
        for (i = 0; i < P; i++) {
            printf("%s - ", p[i].nome);
            if (fabsl(p[i].media - diagonal) < 0.000001L) printf("SOBRE A DIAGONAL\n");
            else if (p[i].media > diagonal) printf("ACIMA DA DIAGONAL\n");
            else printf("ABAIXO DA DIAGONAL\n");
        }
    }

    for (i = 0; i < P; i++) free(p[i].valores);
    return 0;
}
