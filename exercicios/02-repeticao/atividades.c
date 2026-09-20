#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int op;
    printf("Aula 5 - escolha (1 a 8): "); scanf("%d", &op);
    if(op==1){int n; do{scanf("%d",&n); if(n)printf("%d\n",n);}while(n);}
    else if(op==2){char u[20],s[20]; do{printf("Usuario e senha: ");scanf("%19s%19s",u,s);}while(!(u[0]=='a'&&s[0]=='1')); printf("Login realizado com sucesso!\n");}
    else if(op==3){for(int i=1;i<=20;i++)printf("%d\n",i);}
    else if(op==4){int x,s=0;for(int i=0;i<5;i++){scanf("%d",&x);s+=x;}printf("Media: %.2f\n",s/5.0);}
    else if(op==5){float x,s=0;for(int i=0;i<5;i++){scanf("%f",&x);s+=x;printf("%s\n",x<=20?"Ate 20 m3":"Acima de 20 m3");}printf("Media: %.2f\n",s/5);}
    else if(op==6){float m,t=0;char c;do{scanf("%f",&m);if(m==.5||m==1||m==2)t+=m;printf("Outra? S/N: ");scanf(" %c",&c);}while(c=='S'||c=='s');printf("Total: R$ %.2f\n",t);}
    else if(op==7){float n,s=0;for(int i=0;i<10;i++){scanf("%f",&n);s+=n;}printf("Media: %.2f\n",s/10);if(s/10<7)printf("Alerta\n");}
    else if(op==8){int p,total=0,h=0;while(total<10000){scanf("%d",&p);total+=p;h++;}printf("Horas: %d\n",h);}
    else printf("Para as demais atividades, consulte os arquivos individuais da aula.\n");
    return 0;
}
