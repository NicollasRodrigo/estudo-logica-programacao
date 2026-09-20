/*
Slide 14 — Nome e média de um aluno

Criar uma aplicação para ler o nome e a média de um aluno.
Em seguida, exibir os valores lidos.
*/

#include <stdio.h>

int main(void) {
    char nome[50];
    float media;

    printf("Nome: ");
    scanf("%49s", nome);

    printf("Media: ");
    scanf("%f", &media);

    printf("\nNome: %s\n", nome);
    printf("Media: %.2f\n", media);

    return 0;
}
