#ifndef MEU_BANCO_H
#define MEU_BANCO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CORRENTE 1
#define SALARIO  2
#define POUPANCA 3
#define MAX_HIST 5

// Codigos de erro para tratamento via switch
#define OK                          0
#define ERRO_BANCO_FECHADO          1
#define ERRO_BANCO_JA_ABERTO        2
#define ERRO_COMBINACAO_CONTA       3
#define ERRO_NENHUMA_CONTA          4
#define ERRO_CLIENTE_NAO_ENCONTRADO 5
#define ERRO_VALOR_INVALIDO         6
#define ERRO_SALDO_INSUFICIENTE     7
#define ERRO_CONTA_INEXISTENTE      8
#define ERRO_EMPRESTIMO_NEGADO      9
#define ERRO_LIMITE_EMPRESTIMO      10
#define ERRO_TITULO_NEGADO          11
#define ERRO_JA_POSSUI_TITULO       12
#define ERRO_POUCOS_CLIENTES        13
#define ERRO_SEM_TITULO_SORTEIO     14
#define ERRO_MEMORIA                15
#define ERRO_OPCAO_INVALIDA         16

typedef struct
{
	float valor;
	char tipo; // D-Deposito, S-Saque, E-Emprestimo, T-Titulo, P-Premio
} Movimento;

typedef struct
{
	int numero_base;
	char nome[100];
	
	int tem_corrente;
	int tem_salario;
	int tem_poupanca;
	
	char num_corrente[10];
	char num_salario[10];
	char num_poupanca[10];
	
	float saldo_corrente;
	float saldo_salario;
	float saldo_poupanca;
	
	int emprestimo;
	int tem_titulo;
	int contemplado_sorteio;
	float valor_premio;
	
	Movimento historico[MAX_HIST];
	int qtd_hist;
} Cliente;

// Variaveis globais compartilhadas
extern Cliente *clientes;
extern int qtd_clientes;
extern int banco_aberto;
extern int proximo_numero;

// Assinaturas das funcoes (implementadas em banco.c)
void tratarErro(int codigo);
int fibonacci(int num);
float saldoTotalCliente(Cliente c);
void obterNumeroPrincipal(Cliente c, char destino[]);
void registrarMovimento(Cliente *c, float valor, char tipo);
int buscarCliente(int numero_base);
int podeEmprestimo(Cliente c);
float limiteEmprestimo(Cliente c);
int podeComprarTitulo(Cliente c);
void verificarAlertaNegativo(Cliente c);
int cadastrarCliente();
int abrirBanco();
int depositar(int idx);
int sacar(int idx);
int solicitarEmprestimo(int idx);
int comprarTitulo(int idx);
void verExtratoCliente(int idx);
int consultarHistoricoBanco();
int efetuarSorteio();
void liberarMemoria();

#endif
