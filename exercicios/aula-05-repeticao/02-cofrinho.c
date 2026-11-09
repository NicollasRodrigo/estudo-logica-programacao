#include <stdio.h>

int main(void) {
    float moeda, total = 0;
    char continuar;

    do {
        do {
            scanf("%f", &moeda);
        } while (moeda != 0.5f && moeda != 1.0f && moeda != 2.0f);

        total += moeda;
        printf("Outra? S/N: ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    printf("Total: R$ %.2f\n", total);
    return 0;
}
