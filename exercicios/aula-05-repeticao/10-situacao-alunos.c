/*
Questão 10 — Situação de alunos

Leia 3 notas de vários alunos enquanto o usuário desejar.
Calcule a média e classifique:
- Aprovado: média >= 7
- Recuperação: média entre 5 e 6,9
- Reprovado: média < 5
Ao final, conte cada situação.
*/
#include <stdio.h>
int main(void){
    char continuar;
    int aprovados=0,recuperacao=0,reprovados=0;
    do{
        float n1,n2,n3,media;
        scanf("%f%f%f",&n1,&n2,&n3);
        media=(n1+n2+n3)/3;
        if(media>=7) aprovados++;
        else if(media>=5) recuperacao++;
        else reprovados++;
        printf("Outro aluno? S/N: ");
        scanf(" %c",&continuar);
    }while(continuar=='S'||continuar=='s');
    printf("Aprovados: %d\nRecuperacao: %d\nReprovados: %d\n",aprovados,recuperacao,reprovados);
    return 0;
}
