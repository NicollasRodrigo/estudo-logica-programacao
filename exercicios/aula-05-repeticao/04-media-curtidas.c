/*
Questão 04 — Média de curtidas

Leia o número de curtidas de 5 publicações.
Use for, some os valores e exiba a média final.
*/
#include <stdio.h>
int main(void){
    int x,soma=0;
    for(int i=0;i<5;i++){ scanf("%d",&x); soma+=x; }
    printf("Media: %.2f\n",soma/5.0);
    return 0;
}
