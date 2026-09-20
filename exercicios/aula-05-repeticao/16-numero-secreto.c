/*
Questão 16 — Número secreto

Jogue um jogo com um número secreto de 1 a 100.
O usuário tem até 10 tentativas e recebe as pistas
"Maior" ou "Menor". Se não acertar, informe o número secreto.
*/
#include <stdio.h>
int main(void){
    int segredo=57,palpite,tentativas=0,acertou=0;
    while(tentativas<10 && !acertou){
        scanf("%d",&palpite);
        tentativas++;
        if(palpite<segredo) printf("Maior\n");
        else if(palpite>segredo) printf("Menor\n");
        else acertou=1;
    }
    printf("Tentativas: %d\n",tentativas);
    if(!acertou) printf("Numero: %d\n",segredo);
    return 0;
}
