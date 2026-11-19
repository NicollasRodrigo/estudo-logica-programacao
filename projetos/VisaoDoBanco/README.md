# Visão do Banco

Simulação de uma carteira digital com cadastro de clientes, contas, movimentações, empréstimos, títulos de capitalização e sorteio.

## Arquivos

- `main.c` — controla o menu principal e as opções do sistema.
- `banco.c` — implementa o cadastro, as operações bancárias, as consultas e o sorteio.
- `meu_banco.h` — reúne estruturas, constantes e declarações das funções.

## Recursos utilizados

- `realloc` — ajusta a lista de clientes e aloca a cópia usada no sorteio.
- `memcpy` — organiza os registros do histórico e copia os clientes para o sorteio.
- `if` e `for` — validam as regras e percorrem os clientes.
- `switch` — direciona as opções e trata os códigos de erro.
- `<time.h>` — fornece o horário usado para inicializar o gerador de números aleatórios.
- `fibonacci` — calcula o termo usado para selecionar o vencedor entre os cinco participantes.

---

[Voltar à lista de projetos](../README.md)
