#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PARTICIPANTES 4

typedef struct {
    char nome[50];
    int idade;
    int quantidade;
    long double id;
    long double media;
    long double *valores;
} Pessoa;

long double fatorial(int n) {
    long double resultado = 1;
    int i;

    for (i = 2; i <= n; i++) {
        resultado *= i;
        if (!isfinite(resultado)) return INFINITY;
    }

    return resultado;
}

int idExiste(Pessoa pessoas[], int quantidade, long double id) {
    int i;

    for (i = 0; i < quantidade; i++)
        if (pessoas[i].id == id) return 1;

    return 0;
}

long double mediaPonderada(Pessoa pessoa) {
    long double soma = 0, soma_pesos = 0;
    int i;

    for (i = 0; i < pessoa.quantidade; i++) {
        long double peso = i + 1;
        soma += pessoa.valores[i] * peso;
        soma_pesos += peso;
    }

    return soma / soma_pesos;
}

int main(void) {
    Pessoa pessoas[PARTICIPANTES] = {0}, temp;
    long double lados[2], diagonal;
    int quantidade_lados = 0, i, j;

    for (i = 0; i < PARTICIPANTES; i++) {
        printf("Nome do participante %d: ", i + 1);
        if (scanf(" %49[^\n]", pessoas[i].nome) != 1) return 1;

        printf("Idade: ");
        if (scanf("%d", &pessoas[i].idade) != 1 ||
            pessoas[i].idade < 0) return 1;

        printf("Quantidade de valores: ");
        if (scanf("%d", &pessoas[i].quantidade) != 1 ||
            pessoas[i].quantidade < 1) return 1;

        pessoas[i].id = fatorial(pessoas[i].idade) / 2.0L;
        if (!isfinite(pessoas[i].id)) return 1;

        if (idExiste(pessoas, i, pessoas[i].id)) {
            pessoas[i].id =
                powl(fatorial(pessoas[i].idade / 2), pessoas[i].quantidade);
            if (!isfinite(pessoas[i].id)) return 1;

            while (idExiste(pessoas, i, pessoas[i].id)) {
                pessoas[i].id = nextafterl(pessoas[i].id, INFINITY);
                if (!isfinite(pessoas[i].id)) return 1;
            }
        }

        pessoas[i].valores =
            malloc((size_t)pessoas[i].quantidade * sizeof *pessoas[i].valores);
        if (pessoas[i].valores == NULL) {
            for (j = 0; j < i; j++) free(pessoas[j].valores);
            return 1;
        }

        for (j = 0; j < pessoas[i].quantidade; j++) {
            printf("Valor %d: ", j + 1);
            if (scanf("%Lf", &pessoas[i].valores[j]) != 1) {
                for (int k = 0; k <= i; k++) free(pessoas[k].valores);
                return 1;
            }

            if (pessoas[i].valores[j] >= 0 && quantidade_lados < 2)
                lados[quantidade_lados++] = pessoas[i].valores[j];
        }

        pessoas[i].media = mediaPonderada(pessoas[i]);
    }

    for (i = 0; i < PARTICIPANTES; i++) {
        for (j = i + 1; j < PARTICIPANTES; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }

    printf("\nClassificacao final:\n");

    if (quantidade_lados < 2) {
        printf("Nao foi possivel calcular a diagonal.\n");
        for (i = 0; i < PARTICIPANTES; i++)
            printf("%s - Classificacao indisponivel\n", pessoas[i].nome);
    } else {
        diagonal = sqrtl(lados[0] * lados[0] + lados[1] * lados[1]);

        for (i = 0; i < PARTICIPANTES; i++) {
            printf("%s - ", pessoas[i].nome);

            if (fabsl(pessoas[i].media - diagonal) < 0.000001L)
                printf("SOBRE A DIAGONAL\n");
            else if (pessoas[i].media > diagonal)
                printf("ACIMA DA DIAGONAL\n");
            else
                printf("ABAIXO DA DIAGONAL\n");
        }
    }

    for (i = 0; i < PARTICIPANTES; i++)
        free(pessoas[i].valores);

    return 0;
}
