/*
Questão 13 — Tabuada

Leia um número inteiro e apresente a tabuada de 1 a 10.
Depois pergunte se o usuário deseja calcular outra tabuada.
Continue enquanto a resposta for S ou s.
*/
#include <stdio.h>
int main(void){
    int n;
    char continuar;
    do{
        scanf("%d",&n);
        for(int i=1;i<=10;i++) printf("%d x %d = %d\n",n,i,n*i);
        scanf(" %c",&continuar);
    }while(continuar=='S'||continuar=='s');
    return 0;
}
