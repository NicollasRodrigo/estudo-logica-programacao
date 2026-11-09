#include <stdio.h>

int main(void) {
    float nota, soma = 0, media;

    for (int i = 0; i < 10; i++) {
        do {
            scanf("%f", &nota);
        } while (nota < 0 || nota > 10);
        soma += nota;
    }

    media = soma / 10;
    printf("Media: %.2f\n", media);
    if (media < 7) printf("Alerta\n");

    return 0;
}
