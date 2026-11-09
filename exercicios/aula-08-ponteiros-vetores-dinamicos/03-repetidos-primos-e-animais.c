#include <stdio.h>
#include <stdlib.h>

int primo(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i <= n / i; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    int v[15], num[15], freq[15] = {0}, pos[15];
    long long qtd[15] = {0}, total = 0, inicio[15], x;
    char (*animais)[50];
    int d = 0, i, j;
    size_t k = 0;

    for (i = 0; i < 15; i++) scanf("%d", &v[i]);

    for (i = 0; i < 15; i++) {
        for (j = 0; j < d && num[j] != v[i]; j++);
        if (j == d) { num[d] = v[i]; pos[d] = i; d++; }
    }

    for (i = 0; i < d; i++) {
        for (j = 0; j < 15; j++)
            if (v[j] == num[i]) freq[i]++;
        if (freq[i] > 1 && freq[i] % 2 && primo(num[i])) {
            qtd[i] = (long long)num[i] * freq[i];
            total += qtd[i];
        }
        inicio[i] = -1;
    }

    animais = total ? malloc((size_t)total * sizeof *animais) : NULL;
    if (total && !animais) return 1;

    for (i = 0; i < d; i++)
        if (qtd[i]) {
            inicio[i] = (long long)k;
            for (x = 0; x < qtd[i]; x++)
                scanf(" %49[^\n]", animais[k++]);
        }

    printf("Numero | Ocorrencias | Classificacao\n");
    for (i = 0; i < d; i++) {
        printf("%d | %d | ", num[i], freq[i]);
        if (freq[i] == 1) printf("Nao repetido\n");
        else if (primo(num[i]) && freq[i] % 2) printf("Primo - impar\n");
        else if (primo(num[i])) printf("Primo - par\n");
        else if (freq[i] % 2 == 0) printf("Par\n");
        else printf("Repetido - impar\n");
    }

    printf("Correspondencias:\n");
    for (i = 0; i < d; i++) {
        if (qtd[i]) {
            printf("%d: ", num[i]);
            for (x = 0; x < qtd[i]; x++)
                printf("%s%s", animais[inicio[i] + x], x + 1 == qtd[i] ? "\n" : ", ");
        } else if (freq[i] % 2 == 0) {
            printf("%d: ", num[i]);
            if ((size_t)pos[i] < k) printf("%s\n", animais[pos[i]]);
            else printf("Nao existe correspondencia\n");
        }
    }

    free(animais);
    return 0;
}
