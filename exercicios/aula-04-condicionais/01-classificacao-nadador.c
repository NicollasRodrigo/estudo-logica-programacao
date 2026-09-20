/*
Slide 10 — Classificação de nadador

Leia a idade de um nadador e classifique-o:
- Infantil A: 5 a 7 anos
- Infantil B: 8 a 10 anos
- Juvenil A: 11 a 13 anos
- Juvenil B: 14 a 17 anos
- Sênior: maiores de 17 anos
*/

#include <stdio.h>

int main(void) {
    int idade;

    printf("Idade: ");
    scanf("%d", &idade);

    if (idade >= 5 && idade <= 7)
        printf("Infantil A\n");
    else if (idade >= 8 && idade <= 10)
        printf("Infantil B\n");
    else if (idade >= 11 && idade <= 13)
        printf("Juvenil A\n");
    else if (idade >= 14 && idade <= 17)
        printf("Juvenil B\n");
    else if (idade > 17)
        printf("Senior\n");
    else
        printf("Idade fora da classificacao.\n");

    return 0;
}
