/*
Questão 06 — Estoque de produtos

Uma loja possui 10 produtos.
Armazene em um array a quantidade disponível de cada produto.
O programa deve:
- mostrar a quantidade de cada produto;
- informar produtos com estoque baixo (< 5);
- informar produtos esgotados (= 0);
- contar produtos com mais de 20 unidades;
- informar o produto com maior estoque.
*/
#include <stdio.h>
int main(void){
    int estoque[10],maior=0,produto=0,mais20=0;

    for(int i=0;i<10;i++)
        scanf("%d",&estoque[i]);

    for(int i=0;i<10;i++){
        printf("Produto %d: %d\n",i+1,estoque[i]);

        if(estoque[i]<5)
            printf("Estoque baixo\n");

        if(estoque[i]==0)
            printf("Esgotado\n");

        if(estoque[i]>20)
            mais20++;

        if(estoque[i]>maior){
            maior=estoque[i];
            produto=i+1;
        }
    }

    printf("Mais de 20: %d\n",mais20);
    printf("Maior estoque: produto %d (%d)\n",produto,maior);

    return 0;
}
