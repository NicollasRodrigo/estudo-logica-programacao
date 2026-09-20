#include <stdio.h>

void pares_impares(void){int n,pares=0,impares=0;for(int i=0;i<10;i++){scanf("%d",&n);if(n%2==0)pares++;else impares++;}printf("Pares: %d\nImpares: %d\n",pares,impares);}
void maior_menor(void){int n,maior,menor;scanf("%d",&n);maior=menor=n;for(int i=1;i<10;i++){scanf("%d",&n);if(n>maior)maior=n;if(n<menor)menor=n;}printf("Maior: %d\nMenor: %d\nDiferenca: %d\n",maior,menor,maior-menor);}
void positivos_negativos(void){int n,sp=0,sn=0,qp=0,qn=0;do{scanf("%d",&n);if(n>0){sp+=n;qp++;}else if(n<0){sn+=n;qn++;}}while(n!=0);printf("Soma positivos: %d\nSoma negativos: %d\nQtd positivos: %d\nQtd negativos: %d\n",sp,sn,qp,qn);}
void tabuada(void){int n;char c;do{scanf("%d",&n);for(int i=1;i<=10;i++)printf("%d x %d = %d\n",n,i,n*i);scanf(" %c",&c);}while(c=='s'||c=='S');}
void primo(void){int n;char c;do{int p=1;scanf("%d",&n);if(n<2)p=0;for(int d=2;d<n;d++)if(n%d==0){p=0;break;}printf(p?"Primo\n":"Nao primo\n");scanf(" %c",&c);}while(c=='s'||c=='S');}
void fatorial(void){int n;long long f=1;do{scanf("%d",&n);}while(n<0||n>10);for(int i=2;i<=n;i++)f*=i;printf("%d! = %lld\n",n,f);}
void secreto(void){int segredo,palpite,t=0,ok=0;segredo=57;while(t<10&&!ok){scanf("%d",&palpite);t++;if(palpite<segredo)printf("Maior\n");else if(palpite>segredo)printf("Menor\n");else ok=1;}printf("Tentativas: %d\n",t);if(!ok)printf("Numero: %d\n",segredo);}
void notas(void){char c;int a=0,r=0,rr=0;do{float n1,n2,n3,m;scanf("%f%f%f",&n1,&n2,&n3);m=(n1+n2+n3)/3;if(m>=7)a++;else if(m>=5)r++;else rr++;scanf(" %c",&c);}while(c=='s'||c=='S');printf("Aprovados: %d\nRecuperacao: %d\nReprovados: %d\n",a,r,rr);}

int main(void){int op;printf("9-Pares 10-Maior 11-Somas 12-Tabuada 13-Primo 14-Fatorial 15-Secreto 16-Notas\nOpcao: ");scanf("%d",&op);switch(op){case 9:pares_impares();break;case 10:maior_menor();break;case 11:positivos_negativos();break;case 12:tabuada();break;case 13:primo();break;case 14:fatorial();break;case 15:secreto();break;case 16:notas();break;default:printf("Opcao invalida.\n");}return 0;}
