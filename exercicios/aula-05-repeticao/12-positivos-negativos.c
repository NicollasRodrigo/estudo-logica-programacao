/*
Questão 12 — Positivos e negativos

Leia números inteiros continuamente até o usuário digitar 0.
Apresente:
- soma dos positivos;
- soma dos negativos;
- quantidade de positivos;
- quantidade de negativos.
O zero não conta como positivo ou negativo.
*/
#include <stdio.h>
int main(void){
    int n,sp=0,sn=0,qp=0,qn=0;
    do{
        scanf("%d",&n);
        if(n>0){ sp+=n; qp++; }
        else if(n<0){ sn+=n; qn++; }
    }while(n!=0);
    printf("Soma positivos: %d\nSoma negativos: %d\nQtd positivos: %d\nQtd negativos: %d\n",sp,sn,qp,qn);
    return 0;
}
