#include <stdio.h>

int main(void) {
    char nome[50];
    float media;

    printf("Nome: ");
    scanf(" %49[^\n]", nome);
    printf("Media: ");
    scanf("%f", &media);

    printf("\nNome: %s\nMedia: %.2f\n", nome, media);
    return 0;
}
