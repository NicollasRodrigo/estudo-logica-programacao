/*
Slide 15 — Dias do mês

Leia um número de 1 a 12 e informe a quantidade de dias do mês.
Use switch case e considere fevereiro com 28 dias.
*/

#include <stdio.h>

int main(void) {
    int mes;

    printf("Mes: ");
    scanf("%d", &mes);

    switch (mes) {
        case 2:
            printf("28 dias\n");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30 dias\n");
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 dias\n");
            break;
        default:
            printf("Mes invalido.\n");
    }

    return 0;
}
