/*
Questão 05 — Pesquisa em array

Leia 10 números inteiros e armazene em um array.
Depois, peça um número para pesquisar e informe:
- se foi encontrado;
- quantas vezes aparece;
- as posições em que foi encontrado.
*/
#include <stdio.h>
int main(void){
    int numeros[10],pesquisa,quantidade=0;

    for(int i=0;i<10;i++)
        scanf("%d",&numeros[i]);

    scanf("%d",&pesquisa);

    for(int i=0;i<10;i++)
        if(numeros[i]==pesquisa) quantidade++;

    if(quantidade==0){
        printf("O numero nao foi encontrado.\n");
    }else{
        printf("O numero %d foi encontrado %d vez(es).\n",pesquisa,quantidade);
        printf("Posicoes: ");
        for(int i=0;i<10;i++)
            if(numeros[i]==pesquisa) printf("%d ",i+1);
        printf("\n");
    }

    return 0;
}
