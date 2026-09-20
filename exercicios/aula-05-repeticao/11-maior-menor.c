/*
Questão 11 — Maior, menor e diferença

Leia 10 números inteiros e determine:
- maior número;
- menor número;
- diferença entre o maior e o menor.
Restrição: não usar vetores ou matrizes.
*/
#include <stdio.h>
int main(void){
    int n,maior,menor;
    scanf("%d",&n);
    maior=menor=n;
    for(int i=1;i<10;i++){
        scanf("%d",&n);
        if(n>maior) maior=n;
        if(n<menor) menor=n;
    }
    printf("Maior: %d\nMenor: %d\nDiferenca: %d\n",maior,menor,maior-menor);
    return 0;
}
