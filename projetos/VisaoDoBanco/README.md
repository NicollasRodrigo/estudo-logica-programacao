# Visão do Banco

O programa simula o funcionamento de uma carteira digital. Nele, é possível cadastrar clientes, abrir contas corrente, salário e poupança, realizar depósitos e saques e consultar extratos e movimentações. Também estão disponíveis as operações de empréstimo, aquisição de títulos de capitalização e sorteio, seguindo as regras definidas no trabalho.

## Arquivos

- `main.c` — apresenta os menus e direciona as opções escolhidas.
- `banco.c` — reúne as funções de cadastro, operações, consultas, validações e sorteio.
- `meu_banco.h` — define as estruturas, constantes, códigos de erro e declarações compartilhadas.

## Recursos utilizados

- `realloc` — redimensiona a lista de clientes conforme novos cadastros são feitos.
- `memcpy` — atualiza os movimentos do histórico e copia os clientes para ordenar os cinco maiores saldos sem alterar a lista original.
- `if` e `for` — verificam as condições das operações e percorrem os registros dos clientes.
- `switch` — direciona as opções dos menus e trata os códigos de erro.
- `<time.h>` — fornece o horário usado para inicializar a sequência de números pseudoaleatórios.
- `fibonacci` — calcula o termo utilizado para selecionar o vencedor entre os cinco participantes do sorteio.

---

[Voltar à lista de projetos](../README.md)
