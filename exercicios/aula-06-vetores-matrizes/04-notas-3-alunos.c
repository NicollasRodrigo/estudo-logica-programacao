/*
Slides 25–26 — Notas de 3 alunos

Ler 3 notas de 3 alunos e calcular a média de cada aluno.
Armazenar os dados em uma matriz 2D:
coluna 1 = nota 1
coluna 2 = nota 2
coluna 3 = nota 3
coluna 4 = média

Em seguida, exibir a tabela.
*/

#include <stdio.h>

int main(void) {
    float alunos[3][4];

    for (int i = 0; i < 3; i++) {
        printf("Aluno %d\n", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i][j]);
        }

        alunos[i][3] =
            (alunos[i][0] + alunos[i][1] + alunos[i][2]) / 3.0f;
    }

    printf("\nAluno\tNota1\tNota2\tNota3\tMedia\n");

    for (int i = 0; i < 3; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",
               i + 1,
               alunos[i][0],
               alunos[i][1],
               alunos[i][2],
               alunos[i][3]);
    }

    return 0;
}
