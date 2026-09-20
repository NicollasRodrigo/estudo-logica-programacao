/*
Questão 14 — Número primo

Leia um número inteiro positivo e determine se ele é primo.
Depois permita testar vários números até o usuário escolher parar.
*/
#include <stdio.h>
int main(void){
    int n;
    char continuar;
    do{
        int primo=1;
        scanf("%d",&n);
        if(n<2) primo=0;
        for(int d=2;d<n;d++) if(n%d==0){ primo=0; break; }
        printf(primo ? "Primo\n" : "Nao primo\n");
        scanf(" %c",&continuar);
    }while(continuar=='S'||continuar=='s');
    return 0;
}
