/*
Questão 03 — Matriz 3x3

Gere uma matriz 3x3 de inteiros.
Exiba os elementos da mesma linha separados por "-".
Separe as linhas por nova linha.
*/
#include <stdio.h>
int main(void){
    int m[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&m[i][j]);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j>0) printf(" - ");
            printf("%d",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
