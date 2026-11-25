#include "meu_banco.h"

int main()
{
	// Declaracao de variaveis
	int opcao, sub_opcao, num_conta, idx, erro;
	
	// Inicializa semente aleatoria usando a biblioteca time.h
	srand(time(NULL));
	
	do
	{
		printf("\n========== VISAO DO BANCO ==========\n");
		printf("Status: %s\n", (banco_aberto == 1) ? "ABERTO" : "FECHADO");
		printf("1 - Abrir o banco\n");
		printf("2 - Consultar historico\n");
		printf("3 - Efetuar sorteio\n");
		printf("4 - Operacoes de clientes (Deposito/Saque/Emprestimo/Titulo)\n");
		printf("0 - Sair\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				erro = abrirBanco();
				tratarErro(erro);
				break;
				
			case 2:
				erro = consultarHistoricoBanco();
				tratarErro(erro);
				break;
				
			case 3:
				erro = efetuarSorteio();
				tratarErro(erro);
				break;
				
			case 4:
				if (banco_aberto == 0)
				{
					tratarErro(ERRO_BANCO_FECHADO);
				}
				else
				{
					do
					{
						printf("\n--- Menu de Operacoes ---\n");
						printf("1 - Cadastrar novo cliente\n");
						printf("2 - Acessar conta de cliente\n");
						printf("0 - Voltar ao menu principal\n");
						printf("Digite a opcao: ");
						scanf("%d", &sub_opcao);
						
						if (sub_opcao == 1)
						{
							erro = cadastrarCliente();
							tratarErro(erro);
						}
						else if (sub_opcao == 2)
						{
							printf("\nDigite o numero base da conta (ex: 1000): ");
							scanf("%d", &num_conta);
							
							idx = buscarCliente(num_conta);
							if (idx == -1)
							{
								tratarErro(ERRO_CLIENTE_NAO_ENCONTRADO);
							}
							else
							{
								// Regra: alertar sempre que acessar com conta corrente negativa
								verificarAlertaNegativo(clientes[idx]);
								
								do
								{
									printf("\n--- Conta de %s (Codigo %d) ---\n", clientes[idx].nome, clientes[idx].numero_base);
									printf("1 - Depositar\n");
									printf("2 - Sacar\n");
									printf("3 - Solicitar emprestimo\n");
									printf("4 - Adquirir titulo de capitalizacao\n");
									printf("5 - Ver extrato individual\n");
									printf("0 - Sair da conta\n");
									printf("Digite a opcao: ");
									scanf("%d", &sub_opcao);
									
									switch (sub_opcao) {
										case 1:
											erro = depositar(idx);
											tratarErro(erro);
											break;
										case 2:
											erro = sacar(idx);
											tratarErro(erro);
											break;
										case 3:
											erro = solicitarEmprestimo(idx);
											tratarErro(erro);
											break;
										case 4:
											erro = comprarTitulo(idx);
											tratarErro(erro);
											break;
										case 5:
											verExtratoCliente(idx);
											break;
										case 0:
											break;
										default:
											tratarErro(ERRO_OPCAO_INVALIDA);
											break;
									}
								} while (sub_opcao != 0);
								
								sub_opcao = 2; // Mantem no menu de operacoes ao sair da conta
							}
						}
						else if (sub_opcao != 0)
						{
							tratarErro(ERRO_OPCAO_INVALIDA);
						}
					} while (sub_opcao != 0);
				}
				break;
				
			case 0:
				printf("\nEncerrando o sistema...\n");
				break;
				
			default:
				tratarErro(ERRO_OPCAO_INVALIDA);
				break;
		}
	} while (opcao != 0);
	
	liberarMemoria();
	return 0;
}
