#include <stdio.h>

int main(void) {
    int op;
    printf("Aula 4 - escolha (1 a 6): ");
    scanf("%d", &op);

    switch (op) {
        case 1: {
            int idade;
            printf("Idade: "); scanf("%d", &idade);
            if (idade >= 5 && idade <= 7) printf("Infantil A\n");
            else if (idade <= 10 && idade >= 8) printf("Infantil B\n");
            else if (idade <= 13 && idade >= 11) printf("Juvenil A\n");
            else if (idade <= 17 && idade >= 14) printf("Juvenil B\n");
            else if (idade > 17) printf("Senior\n");
            else printf("Idade fora da classificacao.\n");
            break;
        }
        case 2: {
            int mes; printf("Mes: "); scanf("%d", &mes);
            switch (mes) {
                case 2: printf("28 dias\n"); break;
                case 4: case 6: case 9: case 11: printf("30 dias\n"); break;
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: printf("31 dias\n"); break;
                default: printf("Mes invalido.\n");
            }
            break;
        }
        case 3: {
            int a,b,c; printf("Tres lados: "); scanf("%d%d%d", &a,&b,&c);
            if (a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a) { printf("Nao forma triangulo.\n"); break; }
            if (a==b && b==c) printf("Equilatero\n");
            else if (a==b || a==c || b==c) printf("Isosceles\n");
            else printf("Escaleno\n");
            break;
        }
        case 4: {
            int notas[6]={200,100,50,20,10,5}, qtd[6], saque, restante;
            for(int i=0;i<6;i++){ printf("Quantidade de notas de %d: ",notas[i]); scanf("%d",&qtd[i]); }
            printf("Saque: "); scanf("%d",&saque); restante=saque;
            for(int i=0;i<6;i++){ int usar=restante/notas[i]; if(usar>qtd[i]-1) usar=qtd[i]-1; restante-=usar*notas[i]; if(usar) printf("%d x R$%d\n",usar,notas[i]); }
            if(restante) printf("Saque impossivel.\n"); else printf("Saque realizado.\n");
            break;
        }
        case 5: {
            int a,b,c,maior,menor; printf("A B C: "); scanf("%d%d%d",&a,&b,&c);
            maior=a; if(b>maior) maior=b; if(c>maior) maior=c;
            menor=a; if(b<menor) menor=b; if(c<menor) menor=c;
            printf("Maior: %d\nMenor: %d\nDiferenca: %d\n",maior,menor,maior-menor);
            if(a==b && b==c) printf("Tres iguais.\n"); else if(a==b||a==c||b==c) printf("Ha repetidos.\n"); else printf("Sem repetidos.\n");
            break;
        }
        case 6: {
            int n; printf("Numero: "); scanf("%d",&n);
            if(n%2==0) printf("Par\n"); else printf("Impar\n");
            if(n>0) printf("Positivo\n"); else if(n<0) printf("Negativo\n"); else printf("Zero\n");
            printf("Quadrado: %d\n",n*n); break;
        }
        default: printf("Opcao invalida.\n");
    }
    return 0;
}
