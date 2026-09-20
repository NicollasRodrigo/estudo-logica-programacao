/*
Questão 06 — Cofrinho digital

Permita adicionar moedas de R$0,50, R$1,00 ou R$2,00
quantas vezes quiser. Ao parar, mostre o total acumulado.
*/
#include <stdio.h>
int main(void){
    float moeda,total=0;
    char continuar;
    do{
        scanf("%f",&moeda);
        if(moeda==0.5f || moeda==1.0f || moeda==2.0f) total+=moeda;
        printf("Outra? S/N: ");
        scanf(" %c",&continuar);
    }while(continuar=='S' || continuar=='s');
    printf("Total: R$ %.2f\n",total);
    return 0;
}
