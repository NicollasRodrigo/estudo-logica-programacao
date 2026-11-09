#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int primo(int n) {
    int i;

    if (n < 2) return 0;

    for (i = 2; i <= n / i; i++)
        if (n % i == 0) return 0;

    return 1;
}

int main(void) {
    int numeros[15], distintos[15], ocorrencias[15] = {0};
    int primeira_posicao[15], quantidade_distintos = 0;
    long long quantidade_animais[15] = {0};
    size_t inicio_animais[15], total_animais = 0, indice = 0;
    char (*animais)[50] = NULL;
    int i, j;

    printf("Informe 15 numeros inteiros:\n");
    for (i = 0; i < 15; i++) {
        if (scanf("%d", &numeros[i]) != 1) return 1;
    }

    for (i = 0; i < 15; i++) {
        for (j = 0; j < quantidade_distintos &&
                    distintos[j] != numeros[i]; j++);

        if (j == quantidade_distintos) {
            distintos[quantidade_distintos] = numeros[i];
            primeira_posicao[quantidade_distintos] = i;
            quantidade_distintos++;
        }
    }

    for (i = 0; i < quantidade_distintos; i++) {
        inicio_animais[i] = 0;

        for (j = 0; j < 15; j++)
            if (numeros[j] == distintos[i])
                ocorrencias[i]++;

        if (primo(distintos[i]) && ocorrencias[i] % 2 != 0) {
            quantidade_animais[i] =
                (long long)distintos[i] * ocorrencias[i];

            if (quantidade_animais[i] < 0 ||
                (unsigned long long)quantidade_animais[i] >
                SIZE_MAX - total_animais) return 1;

            total_animais += (size_t)quantidade_animais[i];
        }
    }

    if (total_animais > 0) {
        animais = malloc(total_animais * sizeof *animais);
        if (animais == NULL) return 1;
    }

    for (i = 0; i < quantidade_distintos; i++) {
        if (quantidade_animais[i] > 0) {
            inicio_animais[i] = indice;

            for (long long j = 0; j < quantidade_animais[i]; j++) {
                printf("Nome do animal %lld: ", j + 1);
                if (scanf(" %49[^\n]", animais[indice]) != 1) {
                    free(animais);
                    return 1;
                }
                indice++;
            }
        }
    }

    printf("\nNumeros que aparecem mais de uma vez:\n");
    for (i = 0; i < quantidade_distintos; i++) {
        if (ocorrencias[i] > 1)
            printf("%d: %d ocorrencia(s)\n",
                   distintos[i], ocorrencias[i]);
    }

    printf("\nCorrespondencia dos animais:\n");
    for (i = 0; i < quantidade_distintos; i++) {
        if (ocorrencias[i] % 2 != 0 && primo(distintos[i])) {
            printf("%d: ", distintos[i]);

            for (long long j = 0; j < quantidade_animais[i]; j++) {
                size_t pos = inicio_animais[i] + (size_t)j;
                printf("%s%s", animais[pos],
                       j + 1 == quantidade_animais[i] ? "\n" : ", ");
            }
        } else if (ocorrencias[i] > 1 && ocorrencias[i] % 2 == 0) {
            printf("%d: ", distintos[i]);

            if ((size_t)primeira_posicao[i] < total_animais)
                printf("%s\n", animais[primeira_posicao[i]]);
            else
                printf("Nao existe correspondencia.\n");
        }
    }

    free(animais);
    return 0;
}
