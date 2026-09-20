/*
Questão 01 — Nome e média

Crie uma aplicação para ler o nome e a média de um aluno.
Em seguida, exiba os valores lidos.
*/
#include <stdio.h>
int main(void){
    char nome[100];
    float media;
    scanf(" %99[^\n]",nome);
    scanf("%f",&media);
    printf("%s - %.2f\n",nome,media);
    return 0;
}
