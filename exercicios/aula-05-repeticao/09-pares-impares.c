/*
Questão 09 — Pares e ímpares

Leia 10 números inteiros.
Informe para cada um se é par ou ímpar e, ao final,
a quantidade de pares e a quantidade de ímpares.
*/
#include <stdio.h>
int main(void){
    int n,pares=0,impares=0;
    for(int i=0;i<10;i++){
        scanf("%d",&n);
        if(n%2==0){ printf("Par\n"); pares++; }
        else { printf("Impar\n"); impares++; }
    }
    printf("Pares: %d\nImpares: %d\n",pares,impares);
    return 0;
}
