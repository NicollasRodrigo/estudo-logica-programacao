/*
Questão 04 — Notas de 3 alunos

Leia 3 notas de 3 alunos e calcule a média de cada aluno.
Armazene em uma matriz 2D:
coluna 1 = nota 1
coluna 2 = nota 2
coluna 3 = nota 3
coluna 4 = média
Depois, exiba a tabela.
*/
#include <stdio.h>
int main(void){
    float notas[3][4];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            scanf("%f",&notas[i][j]);
        notas[i][3]=(notas[i][0]+notas[i][1]+notas[i][2])/3;
    }

    for(int i=0;i<3;i++)
        printf("Aluno %d: %.2f\n",i+1,notas[i][3]);

    return 0;
}
