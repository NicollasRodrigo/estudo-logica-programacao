/*
Questão 08 — Meta de 10.000 passos

Leia a quantidade de passos dados a cada hora.
Pare quando o total atingir ou ultrapassar 10.000 passos
e informe quantas horas foram necessárias.
*/
#include <stdio.h>
int main(void){
    int passos,total=0,horas=0;
    while(total<10000){
        scanf("%d",&passos);
        total+=passos;
        horas++;
    }
    printf("Horas: %d\n",horas);
    return 0;
}
