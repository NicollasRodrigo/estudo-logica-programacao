#include <stdio.h>

unsigned long long fibonacci(int quantidade) {
    unsigned long long a = 0, b = 1, soma = 0, temp;
    int i;

    for (i = 0; i < quantidade; i++) {
        soma += a;
        temp = a + b;
        a = b;
        b = temp;
    }

    return soma;
}

int primo(unsigned long long numero) {
    unsigned long long i;

    if (numero < 2) return 0;

    for (i = 2; i <= numero / i; i++)
        if (numero % i == 0) return 0;

    return 1;
}

int main(void) {
    char nomes[5][50];
    unsigned long long resultados[5];
    long double soma = 0;
    int premiado[5] = {0};
    int quantidade, primeiro = -1, segundo = -1, terceiro = -1;
    int i;

    for (i = 0; i < 5; i++) {
        printf("Nome do apostador %d: ", i + 1);
        if (scanf(" %49[^\n]", nomes[i]) != 1) return 1;

        printf("Quantidade de termos da sequencia (1 a 92): ");
        if (scanf("%d", &quantidade) != 1) return 1;

        while (quantidade < 1 || quantidade > 92) {
            printf("Informe um valor entre 1 e 92: ");
            if (scanf("%d", &quantidade) != 1) return 1;
        }

        resultados[i] = fibonacci(quantidade);
        soma += resultados[i];
    }

    for (i = 0; i < 5; i++) {
        if (primo(resultados[i]) &&
            (primeiro == -1 || resultados[i] > resultados[primeiro]))
            primeiro = i;
    }

    if (primeiro != -1) premiado[primeiro] = 1;

    for (i = 0; i < 5; i++) {
        if (!premiado[i] && resultados[i] % 2 == 0 &&
            (segundo == -1 || resultados[i] > resultados[segundo]))
            segundo = i;
    }

    if (segundo != -1) premiado[segundo] = 1;

    for (i = 0; i < 5; i++) {
        if (!premiado[i] && resultados[i] > soma / 5.0L &&
            (terceiro == -1 || resultados[i] > resultados[terceiro]))
            terceiro = i;
    }

    printf("\nClassificacao final:\n");
    printf("1o lugar: %s\n",
           primeiro == -1 ? "Sem vencedor" : nomes[primeiro]);
    printf("2o lugar: %s\n",
           segundo == -1 ? "Sem vencedor" : nomes[segundo]);
    printf("3o lugar: %s\n",
           terceiro == -1 ? "Sem vencedor" : nomes[terceiro]);

    return 0;
}
