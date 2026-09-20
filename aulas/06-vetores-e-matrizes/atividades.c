#include <stdio.h>

int main(void) {
    int op;
    printf("Aula 6 - escolha (1 a 6): "); scanf("%d", &op);
    if(op==1){char nome[100];float media;scanf(" %99[^\n]",nome);scanf("%f",&media);printf("%s - %.2f\n",nome,media);}
    else if(op==2){char nomes[30][100];float medias[30];for(int i=0;i<30;i++){scanf(" %99[^\n]",nomes[i]);scanf("%f",&medias[i]);}for(int i=0;i<30;i++)printf("%d - %s - %.2f\n",i+1,nomes[i],medias[i]);}
    else if(op==3){int m[3][3];for(int i=0;i<3;i++)for(int j=0;j<3;j++)scanf("%d",&m[i][j]);for(int i=0;i<3;i++){for(int j=0;j<3;j++)printf("%d ",m[i][j]);printf("\n");}}
    else if(op==4){float n[3][4];for(int i=0;i<3;i++){for(int j=0;j<3;j++)scanf("%f",&n[i][j]);n[i][3]=(n[i][0]+n[i][1]+n[i][2])/3;}for(int i=0;i<3;i++)printf("Aluno %d: %.2f\n",i+1,n[i][3]);}
    else if(op==5){int v[10],p,q=0;for(int i=0;i<10;i++)scanf("%d",&v[i]);scanf("%d",&p);for(int i=0;i<10;i++)if(v[i]==p){q++;printf("Posicao %d\n",i+1);}printf("Quantidade: %d\n",q);}
    else if(op==6){int e[10],maior=0,produto=0,mais20=0;for(int i=0;i<10;i++)scanf("%d",&e[i]);for(int i=0;i<10;i++){printf("Produto %d: %d\n",i+1,e[i]);if(e[i]<5)printf("Estoque baixo\n");if(e[i]==0)printf("Esgotado\n");if(e[i]>20)mais20++;if(e[i]>maior){maior=e[i];produto=i+1;}}printf("Mais de 20: %d\nMaior estoque: produto %d (%d)\n",mais20,produto,maior);}
    else printf("Opcao invalida.\n");
    return 0;
}
