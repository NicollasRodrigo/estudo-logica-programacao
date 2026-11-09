#include <stdio.h>

unsigned long long fibonacci(int n) {
    unsigned long long a = 0, b = 1, soma = 0, t;
    int i;
    for (i = 0; i < n; i++) {
        soma += a;
        t = a + b; a = b; b = t;
    }
    return soma;
}

int primo(unsigned long long n) {
    unsigned long long i;
    if (n < 2) return 0;
    for (i = 2; i <= n / i; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    char nome[5][50];
    unsigned long long resultado[5];
    long double soma = 0;
    int n, premiado[5] = {0};
    int primeiro = -1, segundo = -1, terceiro = -1, i;

    for (i = 0; i < 5; i++) {
        scanf(" %49[^\n]", nome[i]);
        do scanf("%d", &n); while (n < 1 || n > 92);
        resultado[i] = fibonacci(n);
        soma += resultado[i];
    }

    for (i = 0; i < 5; i++)
        if (primo(resultado[i]) && (primeiro < 0 || resultado[i] > resultado[primeiro]))
            primeiro = i;
    if (primeiro >= 0) premiado[primeiro] = 1;

    for (i = 0; i < 5; i++)
        if (!premiado[i] && resultado[i] % 2 == 0 &&
            (segundo < 0 || resultado[i] > resultado[segundo])) segundo = i;
    if (segundo >= 0) premiado[segundo] = 1;

    for (i = 0; i < 5; i++)
        if (!premiado[i] && resultado[i] > soma / 5.0L &&
            (terceiro < 0 || resultado[i] > resultado[terceiro])) terceiro = i;

    printf("1o lugar: %s\n", primeiro < 0 ? "Sem vencedor" : nome[primeiro]);
    printf("2o lugar: %s\n", segundo < 0 ? "Sem vencedor" : nome[segundo]);
    printf("3o lugar: %s\n", terceiro < 0 ? "Sem vencedor" : nome[terceiro]);
    return 0;
}
