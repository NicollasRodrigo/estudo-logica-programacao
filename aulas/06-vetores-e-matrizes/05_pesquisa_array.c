#include <stdio.h>

int main(void) {
    int numeros[10], pesquisa, quantidade = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Digite um numero para pesquisar: ");
    scanf("%d", &pesquisa);

    for (int i = 0; i < 10; i++)
        if (numeros[i] == pesquisa) quantidade++;

    if (quantidade == 0) {
        printf("O numero nao foi encontrado.\n");
    } else {
        printf("O numero %d foi encontrado %d vez(es).\nPosicoes: ", pesquisa, quantidade);
        for (int i = 0; i < 10; i++)
            if (numeros[i] == pesquisa) printf("%d ", i + 1);
        printf("\n");
    }
    return 0;
}
