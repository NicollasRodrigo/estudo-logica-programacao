/*
Questão 15 — Fatorial

Leia um inteiro entre 0 e 10.
Repita a leitura enquanto estiver fora desse intervalo
e calcule o fatorial.
*/
#include <stdio.h>
int main(void){
    int n;
    long long f=1;
    do{ scanf("%d",&n); }while(n<0||n>10);
    for(int i=2;i<=n;i++) f*=i;
    printf("%d! = %lld\n",n,f);
    return 0;
}
