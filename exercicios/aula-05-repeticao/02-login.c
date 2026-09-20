/*
Questão 02 — Login

Simule um login usando do...while.
Usuário correto: admin
Senha correta: 1234
Repita enquanto as credenciais estiverem incorretas.
*/
#include <stdio.h>
#include <string.h>
int main(void){
    char usuario[20], senha[20];
    do{
        printf("Digite o usuario: ");
        scanf("%19s",usuario);
        printf("Digite a senha: ");
        scanf("%19s",senha);
        if(strcmp(usuario,"admin")!=0 || strcmp(senha,"1234")!=0)
            printf("Usuario ou senha incorretos. Tente novamente.\n");
    }while(strcmp(usuario,"admin")!=0 || strcmp(senha,"1234")!=0);
    printf("Login realizado com sucesso! Bem-vindo ao sistema.\n");
    return 0;
}
