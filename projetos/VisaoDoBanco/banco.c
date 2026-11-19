#include "meu_banco.h"

// Definicao das variaveis globais
Cliente *clientes = NULL;
int qtd_clientes = 0;
int banco_aberto = 0;
int proximo_numero = 1000;

void tratarErro(int codigo)
{
	switch (codigo) {
		case OK:
			break;
		case ERRO_BANCO_FECHADO:
			printf("\n[ERRO] O banco esta fechado. Abra o banco primeiro.\n");
			break;
		case ERRO_BANCO_JA_ABERTO:
			printf("\n[ERRO] O banco ja se encontra aberto.\n");
			break;
		case ERRO_COMBINACAO_CONTA:
			printf("\n[ERRO] O cliente nao pode possuir conta-salario e conta corrente ao mesmo tempo.\n");
			break;
		case ERRO_NENHUMA_CONTA:
			printf("\n[ERRO] O cliente precisa ter pelo menos um tipo de conta.\n");
			break;
		case ERRO_CLIENTE_NAO_ENCONTRADO:
			printf("\n[ERRO] Cliente nao encontrado.\n");
			break;
		case ERRO_VALOR_INVALIDO:
			printf("\n[ERRO] Valor informado eh invalido.\n");
			break;
		case ERRO_SALDO_INSUFICIENTE:
			printf("\n[ERRO] Saldo insuficiente para realizar a operacao.\n");
			break;
		case ERRO_CONTA_INEXISTENTE:
			printf("\n[ERRO] O cliente nao possui esse tipo de conta.\n");
			break;
		case ERRO_EMPRESTIMO_NEGADO:
			printf("\n[ERRO] Emprestimo negado. Necessario ter conta corrente, saldo na poupanca e nenhum emprestimo ativo.\n");
			break;
		case ERRO_LIMITE_EMPRESTIMO:
			printf("\n[ERRO] Valor solicitado ultrapassa o limite permitido.\n");
			break;
		case ERRO_TITULO_NEGADO:
			printf("\n[ERRO] Necessario possuir entre R$ 1000.00 e R$ 1500.00 na conta-salario.\n");
			break;
		case ERRO_JA_POSSUI_TITULO:
			printf("\n[ERRO] Este cliente ja adquiriu titulo de capitalizacao.\n");
			break;
		case ERRO_POUCOS_CLIENTES:
			printf("\n[ERRO] Sao necessarios pelo menos 5 clientes cadastrados para o sorteio.\n");
			break;
		case ERRO_SEM_TITULO_SORTEIO:
			printf("\n[ERRO] Sorteio cancelado: nem todos os 5 clientes com maiores saldos possuem titulo de capitalizacao.\n");
			break;
		case ERRO_MEMORIA:
			printf("\n[ERRO] Falha ao alocar memoria.\n");
			break;
		case ERRO_OPCAO_INVALIDA:
			printf("\n[ERRO] Opcao invalida.\n");
			break;
		default:
			printf("\n[ERRO] Erro desconhecido.\n");
			break;
	}
}

int fibonacci(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}

float saldoTotalCliente(Cliente c)
{
	// Declaracao de variaveis
	float total;
	
	total = c.saldo_corrente + c.saldo_salario + c.saldo_poupanca;
	
	return total;
}

void obterNumeroPrincipal(Cliente c, char destino[])
{
	if (c.tem_corrente == 1)
	{
		strcpy(destino, c.num_corrente);
	}
	else if (c.tem_salario == 1)
	{
		strcpy(destino, c.num_salario);
	}
	else
	{
		strcpy(destino, c.num_poupanca);
	}
}

void registrarMovimento(Cliente *c, float valor, char tipo)
{
	// Declaracao de variaveis
	Movimento aux[MAX_HIST - 1];
	
	if (c->qtd_hist == MAX_HIST)
	{
		// Usa memcpy para deslocar os ultimos movimentos sem sobreposicao
		memcpy(aux, &c->historico[1], (MAX_HIST - 1) * sizeof(Movimento));
		memcpy(&c->historico[0], aux, (MAX_HIST - 1) * sizeof(Movimento));
		c->qtd_hist = MAX_HIST - 1;
	}
	
	c->historico[c->qtd_hist].valor = valor;
	c->historico[c->qtd_hist].tipo = tipo;
	c->qtd_hist++;
}

int buscarCliente(int numero_base)
{
	// Declaracao de variaveis
	int i;
	
	for (i=0; i<qtd_clientes; i++)
	{
		if (clientes[i].numero_base == numero_base)
		{
			return i;
		}
	}
	
	return -1;
}

int podeEmprestimo(Cliente c)
{
	if (c.tem_corrente == 1 && c.tem_poupanca == 1 && c.saldo_poupanca > 0 && c.emprestimo == 0)
	{
		if (limiteEmprestimo(c) > 0)
		{
			return 1;
		}
	}
	
	return 0;
}

float limiteEmprestimo(Cliente c)
{
	// Declaracao de variaveis
	float total, limite;
	
	total = saldoTotalCliente(c);
	limite = 0.25f * (10.0f * total);
	
	return limite;
}

int podeComprarTitulo(Cliente c)
{
	if (c.tem_salario == 1 && c.saldo_salario >= 1000.0f && c.saldo_salario <= 1500.0f)
	{
		return 1;
	}
	
	return 0;
}

void verificarAlertaNegativo(Cliente c)
{
	if (c.tem_corrente == 1 && c.saldo_corrente < 0)
	{
		printf("\n========================================================\n");
		printf("ALERTA: Sua conta corrente (%s) esta com saldo negativo!\n", c.num_corrente);
		printf("Saldo atual: R$ %.2f\n", c.saldo_corrente);
		printf("========================================================\n");
	}
}

int cadastrarCliente()
{
	// Declaracao de variaveis
	Cliente novo;
	Cliente *temp;
	int c_corr, c_sal, c_poup;
	
	printf("\n--- Cadastro de Cliente ---\n");
	printf("Nome do cliente: ");
	scanf(" %99[^\n]", novo.nome);
	
	printf("Deseja Conta Corrente (01)? (1-Sim / 0-Nao): ");
	scanf("%d", &c_corr);
	
	printf("Deseja Conta Salario (02)? (1-Sim / 0-Nao): ");
	scanf("%d", &c_sal);
	
	printf("Deseja Conta Poupanca (03)? (1-Sim / 0-Nao): ");
	scanf("%d", &c_poup);
	
	if ((c_corr != 0 && c_corr != 1) ||
		(c_sal != 0 && c_sal != 1) ||
		(c_poup != 0 && c_poup != 1))
	{
		return ERRO_OPCAO_INVALIDA;
	}
	
	// Validacao das combinacoes de contas permitidas
	if (c_corr == 1 && c_sal == 1)
	{
		return ERRO_COMBINACAO_CONTA;
	}
	
	if (c_corr != 1 && c_sal != 1 && c_poup != 1)
	{
		return ERRO_NENHUMA_CONTA;
	}
	
	// Realoca o vetor dinamico para suportar n clientes
	temp = (Cliente *) realloc(clientes, (qtd_clientes + 1) * sizeof(Cliente));
	if (temp == NULL)
	{
		return ERRO_MEMORIA;
	}
	clientes = temp;
	
	novo.numero_base = proximo_numero;
	proximo_numero++;
	
	novo.tem_corrente = (c_corr == 1) ? 1 : 0;
	novo.tem_salario = (c_sal == 1) ? 1 : 0;
	novo.tem_poupanca = (c_poup == 1) ? 1 : 0;
	
	sprintf(novo.num_corrente, "%d-01", novo.numero_base);
	sprintf(novo.num_salario, "%d-02", novo.numero_base);
	sprintf(novo.num_poupanca, "%d-03", novo.numero_base);
	
	// Todos os clientes iniciam com saldos zerados
	novo.saldo_corrente = 0.0f;
	novo.saldo_salario = 0.0f;
	novo.saldo_poupanca = 0.0f;
	
	novo.emprestimo = 0;
	novo.tem_titulo = 0;
	novo.contemplado_sorteio = 0;
	novo.valor_premio = 0.0f;
	novo.qtd_hist = 0;
	
	clientes[qtd_clientes] = novo;
	qtd_clientes++;
	
	printf("Cliente cadastrado com sucesso! Codigo base: %d\n", novo.numero_base);
	if (novo.tem_corrente == 1)
	{
		printf("  - Conta Corrente: %s (Saldo: R$ 0.00)\n", novo.num_corrente);
	}
	if (novo.tem_salario == 1)
	{
		printf("  - Conta Salario:  %s (Saldo: R$ 0.00)\n", novo.num_salario);
	}
	if (novo.tem_poupanca == 1)
	{
		printf("  - Conta Poupanca: %s (Saldo: R$ 0.00)\n", novo.num_poupanca);
	}
	
	return OK;
}

int abrirBanco()
{
	// Declaracao de variaveis
	int n, i, erro;
	
	if (banco_aberto == 1)
	{
		return ERRO_BANCO_JA_ABERTO;
	}
	
	printf("\n=== ABERTURA DO BANCO ===\n");
	printf("Quantos clientes deseja cadastrar inicialmente? ");
	scanf("%d", &n);
	
	if (n <= 0)
	{
		return ERRO_VALOR_INVALIDO;
	}
	
	for (i=0; i<n; i++)
	{
		printf("\nCliente %d de %d:\n", i+1, n);
		erro = cadastrarCliente();
		
		if (erro != OK)
		{
			tratarErro(erro);
			printf("Tente cadastrar este cliente novamente.\n");
			i--;
		}
	}
	
	banco_aberto = 1;
	printf("\nBanco aberto com sucesso! Total de clientes: %d\n", qtd_clientes);
	
	return OK;
}

int depositar(int idx)
{
	// Declaracao de variaveis
	int tipo_conta;
	float valor;
	
	printf("\nQual conta deseja depositar? (1-Corrente, 2-Salario, 3-Poupanca): ");
	scanf("%d", &tipo_conta);
	
	printf("Valor do deposito: R$ ");
	scanf("%f", &valor);
	
	if (valor <= 0)
	{
		return ERRO_VALOR_INVALIDO;
	}
	
	if (tipo_conta == CORRENTE)
	{
		if (clientes[idx].tem_corrente == 0)
		{
			return ERRO_CONTA_INEXISTENTE;
		}
		clientes[idx].saldo_corrente += valor;
		printf("Deposito realizado na conta %s! Novo saldo: R$ %.2f\n", clientes[idx].num_corrente, clientes[idx].saldo_corrente);
	}
	else if (tipo_conta == SALARIO)
	{
		if (clientes[idx].tem_salario == 0)
		{
			return ERRO_CONTA_INEXISTENTE;
		}
		clientes[idx].saldo_salario += valor;
		printf("Deposito realizado na conta %s! Novo saldo: R$ %.2f\n", clientes[idx].num_salario, clientes[idx].saldo_salario);
	}
	else if (tipo_conta == POUPANCA)
	{
		if (clientes[idx].tem_poupanca == 0)
		{
			return ERRO_CONTA_INEXISTENTE;
		}
		clientes[idx].saldo_poupanca += valor;
		printf("Deposito realizado na conta %s! Novo saldo: R$ %.2f\n", clientes[idx].num_poupanca, clientes[idx].saldo_poupanca);
	}
	else
	{
		return ERRO_OPCAO_INVALIDA;
	}
	
	registrarMovimento(&clientes[idx], valor, 'D');
	return OK;
}

int sacar(int idx)
{
	// Declaracao de variaveis
	int tipo_conta;
	float valor;
	
	printf("\nQual conta deseja sacar? (1-Corrente, 2-Salario, 3-Poupanca): ");
	scanf("%d", &tipo_conta);
	
	printf("Valor do saque: R$ ");
	scanf("%f", &valor);
	
	if (valor <= 0)
	{
		return ERRO_VALOR_INVALIDO;
	}
	
	if (tipo_conta == CORRENTE)
	{
		if (clientes[idx].tem_corrente == 0)
		{
			return ERRO_CONTA_INEXISTENTE;
		}
		// Apenas a conta corrente pode ficar negativa
		clientes[idx].saldo_corrente -= valor;
		printf("Saque realizado na conta %s! Novo saldo: R$ %.2f\n", clientes[idx].num_corrente, clientes[idx].saldo_corrente);
		verificarAlertaNegativo(clientes[idx]);
	}
	else if (tipo_conta == SALARIO)
	{
		if (clientes[idx].tem_salario == 0)
		{
			return ERRO_CONTA_INEXISTENTE;
		}
		if (valor > clientes[idx].saldo_salario)
		{
			return ERRO_SALDO_INSUFICIENTE;
		}
		clientes[idx].saldo_salario -= valor;
		printf("Saque realizado na conta %s! Novo saldo: R$ %.2f\n", clientes[idx].num_salario, clientes[idx].saldo_salario);
	}
	else if (tipo_conta == POUPANCA)
	{
		if (clientes[idx].tem_poupanca == 0)
		{
			return ERRO_CONTA_INEXISTENTE;
		}
		if (valor > clientes[idx].saldo_poupanca)
		{
			return ERRO_SALDO_INSUFICIENTE;
		}
		clientes[idx].saldo_poupanca -= valor;
		printf("Saque realizado na conta %s! Novo saldo: R$ %.2f\n", clientes[idx].num_poupanca, clientes[idx].saldo_poupanca);
	}
	else
	{
		return ERRO_OPCAO_INVALIDA;
	}
	
	registrarMovimento(&clientes[idx], valor, 'S');
	return OK;
}

int solicitarEmprestimo(int idx)
{
	// Declaracao de variaveis
	float limite, valor;
	
	if (podeEmprestimo(clientes[idx]) == 0)
	{
		return ERRO_EMPRESTIMO_NEGADO;
	}
	
	limite = limiteEmprestimo(clientes[idx]);
	printf("\nLimite disponivel para emprestimo: R$ %.2f\n", limite);
	printf("Digite o valor desejado: R$ ");
	scanf("%f", &valor);
	
	if (valor <= 0)
	{
		return ERRO_VALOR_INVALIDO;
	}
	
	if (valor > limite)
	{
		return ERRO_LIMITE_EMPRESTIMO;
	}
	
	clientes[idx].saldo_corrente += valor;
	clientes[idx].emprestimo = 1;
	registrarMovimento(&clientes[idx], valor, 'E');
	
	printf("Emprestimo de R$ %.2f aprovado e creditado na conta %s!\n", valor, clientes[idx].num_corrente);
	return OK;
}

int comprarTitulo(int idx)
{
	if (clientes[idx].tem_titulo == 1)
	{
		return ERRO_JA_POSSUI_TITULO;
	}
	
	if (podeComprarTitulo(clientes[idx]) == 0)
	{
		return ERRO_TITULO_NEGADO;
	}
	
	clientes[idx].tem_titulo = 1;
	registrarMovimento(&clientes[idx], 0.0f, 'T');
	
	printf("\nTitulo de capitalizacao adquirido com sucesso para %s!\n", clientes[idx].nome);
	return OK;
}

void verExtratoCliente(int idx)
{
	// Declaracao de variaveis
	int i;
	
	printf("\n=== Extrato de %s (Codigo %d) ===\n", clientes[idx].nome, clientes[idx].numero_base);
	if (clientes[idx].tem_corrente == 1)
	{
		printf("Conta Corrente (%s): R$ %.2f\n", clientes[idx].num_corrente, clientes[idx].saldo_corrente);
	}
	if (clientes[idx].tem_salario == 1)
	{
		printf("Conta Salario  (%s): R$ %.2f\n", clientes[idx].num_salario, clientes[idx].saldo_salario);
	}
	if (clientes[idx].tem_poupanca == 1)
	{
		printf("Conta Poupanca (%s): R$ %.2f\n", clientes[idx].num_poupanca, clientes[idx].saldo_poupanca);
	}
	
	printf("Ultimas movimentacoes:\n");
	if (clientes[idx].qtd_hist == 0)
	{
		printf("  (sem movimentacoes)\n");
	}
	else
	{
		for (i=0; i<clientes[idx].qtd_hist; i++)
		{
			printf("  Tipo: %c | Valor: R$ %.2f\n", clientes[idx].historico[i].tipo, clientes[idx].historico[i].valor);
		}
	}
}

int consultarHistoricoBanco()
{
	// Declaracao de variaveis
	int i, achou;
	float saldo_total_banco;
	char num_conta[10];
	
	if (banco_aberto == 0)
	{
		return ERRO_BANCO_FECHADO;
	}
	
	saldo_total_banco = 0.0f;
	for (i=0; i<qtd_clientes; i++)
	{
		saldo_total_banco += saldoTotalCliente(clientes[i]);
	}
	
	printf("\n== Saldo Total do banco ==\n");
	printf("%d | R$ %.2f\n", qtd_clientes, saldo_total_banco);
	
	printf("\n== Clientes Aptos a Emprestimos ==\n");
	achou = 0;
	for (i=0; i<qtd_clientes; i++)
	{
		if (podeEmprestimo(clientes[i]) == 1)
		{
			printf("%s|%s|R$ %.2f\n", clientes[i].nome, clientes[i].num_corrente, limiteEmprestimo(clientes[i]));
			achou = 1;
		}
	}
	if (achou == 0)
	{
		printf("Nenhum cliente apto.\n");
	}
	
	printf("\n== Clientes com Saldo Negativo na Conta Corrente ==\n");
	achou = 0;
	for (i=0; i<qtd_clientes; i++)
	{
		if (clientes[i].tem_corrente == 1 && clientes[i].saldo_corrente < 0)
		{
			printf("%s|%s|R$ %.2f\n", clientes[i].nome, clientes[i].num_corrente, clientes[i].saldo_corrente);
			achou = 1;
		}
	}
	if (achou == 0)
	{
		printf("Nenhum cliente com saldo negativo.\n");
	}
	
	printf("\n== Clientes Aptos a Compra de Titulos ==\n");
	achou = 0;
	for (i=0; i<qtd_clientes; i++)
	{
		if (podeComprarTitulo(clientes[i]) == 1)
		{
			printf("%s|%s|R$ %.2f\n", clientes[i].nome, clientes[i].num_salario, clientes[i].saldo_salario);
			achou = 1;
		}
	}
	if (achou == 0)
	{
		printf("Nenhum cliente apto.\n");
	}
	
	printf("\n== Clientes Contemplado no Sorteio ==\n");
	achou = 0;
	for (i=0; i<qtd_clientes; i++)
	{
		if (clientes[i].contemplado_sorteio == 1)
		{
			obterNumeroPrincipal(clientes[i], num_conta);
			printf("%s|%s|R$ %.2f\n", clientes[i].nome, num_conta, clientes[i].valor_premio);
			achou = 1;
		}
	}
	if (achou == 0)
	{
		printf("Nenhum cliente contemplado ate o momento.\n");
	}
	
	return OK;
}

int efetuarSorteio()
{
	// Declaracao de variaveis
	Cliente *copia;
	Cliente temp;
	int i, j;
	int termo_sorteado, valor_fib, idx_vencedor_copia, idx_real;
	float premio;
	
	if (banco_aberto == 0)
	{
		return ERRO_BANCO_FECHADO;
	}
	
	if (qtd_clientes < 5)
	{
		return ERRO_POUCOS_CLIENTES;
	}
	
	// Aloca e copia o vetor original usando realloc e memcpy para ordenar sem alterar a ordem original
	copia = (Cliente *) realloc(NULL, qtd_clientes * sizeof(Cliente));
	if (copia == NULL)
	{
		return ERRO_MEMORIA;
	}
	memcpy(copia, clientes, qtd_clientes * sizeof(Cliente));
	
	// Ordena a copia em ordem decrescente pelo saldo total (Bubble Sort)
	for (i=0; i<qtd_clientes-1; i++)
	{
		for (j=0; j<qtd_clientes-1-i; j++)
		{
			if (saldoTotalCliente(copia[j]) < saldoTotalCliente(copia[j+1]))
			{
				temp = copia[j];
				copia[j] = copia[j+1];
				copia[j+1] = temp;
			}
		}
	}
	
	// Verifica se todos os 5 maiores saldos adquiriram titulo de capitalizacao
	for (i=0; i<5; i++)
	{
		if (copia[i].tem_titulo == 0)
		{
			free(copia);
			return ERRO_SEM_TITULO_SORTEIO;
		}
	}
	
	printf("\n=== Participantes do Sorteio (Top 5 Maiores Saldos) ===\n");
	for (i=0; i<5; i++)
	{
		printf("%d - %s | Saldo Total: R$ %.2f\n", i+1, copia[i].nome, saldoTotalCliente(copia[i]));
	}
	
	// Sorteio baseado em Fibonacci + biblioteca time.h (semente inicializada na main)
	termo_sorteado = (rand() % 15) + 1;
	valor_fib = fibonacci(termo_sorteado);
	idx_vencedor_copia = valor_fib % 5;
	
	idx_real = buscarCliente(copia[idx_vencedor_copia].numero_base);
	free(copia);
	
	if (idx_real == -1)
	{
		return ERRO_CLIENTE_NAO_ENCONTRADO;
	}
	
	// Premio equivalente a 10x o saldo disponivel na conta no momento do sorteio
	premio = 10.0f * clientes[idx_real].saldo_salario;
	clientes[idx_real].saldo_salario += premio;
	clientes[idx_real].contemplado_sorteio = 1;
	clientes[idx_real].valor_premio = premio;
	registrarMovimento(&clientes[idx_real], premio, 'P');
	
	printf("\nTermo Fibonacci sorteado: F(%d) = %d\n", termo_sorteado, valor_fib);
	printf("VENCEDOR DO SORTEIO: %s (%s)\n", clientes[idx_real].nome, clientes[idx_real].num_salario);
	printf("Premio creditado: R$ %.2f | Novo saldo: R$ %.2f\n", premio, clientes[idx_real].saldo_salario);
	
	return OK;
}

void liberarMemoria()
{
	if (clientes != NULL)
	{
		free(clientes);
		clientes = NULL;
	}
}
