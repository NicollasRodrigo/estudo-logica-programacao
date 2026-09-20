/*
Questão 07 — Média de atendimento

Leia a nota de atendimento (0 a 10) de 10 clientes.
Calcule a média geral. Se a média for menor que 7, exiba um alerta.
*/
#include <stdio.h>
int main(void){
    float nota,soma=0,media;
    for(int i=0;i<10;i++){ scanf("%f",&nota); soma+=nota; }
    media=soma/10;
    printf("Media: %.2f\n",media);
    if(media<7) printf("Alerta\n");
    return 0;
}
