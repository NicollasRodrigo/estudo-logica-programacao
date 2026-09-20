/*
Questão 02 — Nome e média de 30 alunos

Usando vetores, leia o nome e a média de 30 alunos.
Em seguida, exiba a lista com os nomes e as médias.
*/
#include <stdio.h>
int main(void){
    char nomes[30][100];
    float medias[30];
    for(int i=0;i<30;i++){
        scanf(" %99[^\n]",nomes[i]);
        scanf("%f",&medias[i]);
    }
    for(int i=0;i<30;i++)
        printf("%d - %s - %.2f\n",i+1,nomes[i],medias[i]);
    return 0;
}
