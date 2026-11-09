#include <stdio.h>

int main(void) {
    int passos, total = 0, horas = 0;

    while (total < 10000) {
        do {
            scanf("%d", &passos);
        } while (passos < 0);

        total += passos;
        horas++;
    }

    printf("Horas: %d\n", horas);
    return 0;
}
