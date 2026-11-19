# Visão do Banco

Projeto em C que simula uma carteira digital, com cadastro de clientes e contas corrente, salário e poupança. O sistema permite realizar depósitos e saques, consultar extratos e histórico, solicitar empréstimos, adquirir títulos de capitalização e participar de um sorteio.

## Arquivos

- `main.c` — apresenta os menus e direciona as opções escolhidas.
- `banco.c` — reúne as funções de cadastro, operações, consultas, validações e sorteio.
- `meu_banco.h` — define as estruturas, constantes, códigos de erro e declarações compartilhadas.

## Recursos utilizados

- `realloc` — redimensiona a lista de clientes conforme novos cadastros são feitos.
- `memcpy` — atualiza os movimentos do histórico e copia os clientes para ordenar os cinco maiores saldos sem alterar a lista original.
- `if` e `for` — verificam as condições das operações e percorrem os registros dos clientes.
- `switch` — direciona as opções dos menus e trata os códigos de erro.
- `<time.h>` e `fibonacci` — usam o horário atual para inicializar a semente aleatória; o cálculo de Fibonacci ajuda a definir o vencedor entre os cinco clientes selecionados.

---

[Voltar à lista de projetos](../README.md)
