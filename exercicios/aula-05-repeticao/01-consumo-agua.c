#include <stdio.h>

int main(void) {
    float consumo, soma = 0;

    for (int i = 0; i < 5; i++) {
        do {
            scanf("%f", &consumo);
        } while (consumo < 0);

        soma += consumo;
        printf("%s\n", consumo <= 20 ? "Ate 20 m3" : "Acima de 20 m3");
    }

    printf("Media: %.2f\n", soma / 5);
    return 0;
}
