/*
Slide 21 — Menu com switch

1 - Verificar número par ou ímpar
2 - Verificar se é positivo ou negativo
3 - Calcular o quadrado do número
4 - Sair

Use switch para controlar o menu e trate opções inválidas.
Na opção 1, informe também se o número é positivo, negativo ou zero.
*/

#include <stdio.h>

int main(void) {
    int opcao, n;

    printf("===== MENU =====\n");
    printf("1 - Verificar numero par ou impar\n");
    printf("2 - Verificar se e positivo ou negativo\n");
    printf("3 - Calcular o quadrado do numero\n");
    printf("4 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Numero: ");
            scanf("%d", &n);

            printf(n % 2 == 0 ? "Par\n" : "Impar\n");

            if (n > 0)
                printf("Positivo\n");
            else if (n < 0)
                printf("Negativo\n");
            else
                printf("Zero\n");
            break;

        case 2:
            printf("Numero: ");
            scanf("%d", &n);

            if (n > 0)
                printf("Positivo\n");
            else if (n < 0)
                printf("Negativo\n");
            else
                printf("Zero\n");
            break;

        case 3:
            printf("Numero: ");
            scanf("%d", &n);
            printf("Quadrado: %d\n", n * n);
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}
