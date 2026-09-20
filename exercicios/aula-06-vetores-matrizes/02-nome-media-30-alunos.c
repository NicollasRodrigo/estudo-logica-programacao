/*
Slides 20–21 — Nome e média de 30 alunos

Usando vetores, ler o nome e a média de 30 alunos.
Em seguida, exibir a lista com os nomes e as médias.
*/

#include <stdio.h>

int main(void) {
    char nomes[30][50];
    float medias[30];

    for (int i = 0; i < 30; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf("%49s", nomes[i]);

        printf("Media do aluno %d: ", i + 1);
        scanf("%f", &medias[i]);
    }

    printf("\n--- Lista de alunos ---\n");

    for (int i = 0; i < 30; i++) {
        printf("%d - %s - %.2f\n", i + 1, nomes[i], medias[i]);
    }

    return 0;
}
