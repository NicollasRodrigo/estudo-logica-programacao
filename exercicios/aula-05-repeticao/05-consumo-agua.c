/*
Questão 05 — Consumo de água

Leia o consumo mensal de 5 moradores.
Informe se cada consumo está até 20 m³ ou acima.
Ao final, mostre o consumo médio geral.
*/
#include <stdio.h>
int main(void){
    float x,soma=0;
    for(int i=0;i<5;i++){
        scanf("%f",&x);
        soma+=x;
        printf("%s\n",x<=20 ? "Ate 20 m3" : "Acima de 20 m3");
    }
    printf("Media: %.2f\n",soma/5);
    return 0;
}
