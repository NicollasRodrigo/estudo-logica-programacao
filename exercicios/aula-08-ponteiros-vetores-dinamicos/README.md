# Aula 08 — Ponteiros e Vetores Dinâmicos

Atividades do material da Aula 8, na ordem do PDF.

| Atividade | Tema | Código |
|---|---|---|
| 1 | Contagem, produtos e ordenação | [01-numeros-e-produtos.c](./01-numeros-e-produtos.c) |
| 2 | Positivos pares e negativos ímpares | [02-positivos-pares-e-negativos-impares.c](./02-positivos-pares-e-negativos-impares.c) |
| 3 | Números repetidos, primos e animais | [03-repetidos-primos-e-animais.c](./03-repetidos-primos-e-animais.c) |
| 4 | Fibonacci e classificação dos apostadores | [04-fibonacci-e-vencedores.c](./04-fibonacci-e-vencedores.c) |
| 5 | Cadastro, média ponderada e diagonal | [05-cadastro-media-e-diagonal.c](./05-cadastro-media-e-diagonal.c) |

## Entrada de dados

- **Atividade 1:** informe 12 inteiros. Depois, para cada número positivo com quantidade ímpar de ocorrências, cadastre essa quantidade de produtos: nome em uma linha e preço na seguinte. Números negativos não podem representar quantidade de produtos.
- **Atividade 2:** informe 10 inteiros.
- **Atividade 3:** informe 15 inteiros. Para cada número primo repetido com frequência ímpar, cadastre uma quantidade de animais igual à soma de suas ocorrências (valor × frequência). Os nomes são lidos em ordem de primeira aparição dos números.
- **Atividade 4:** informe nome e quantidade de termos para cada um dos cinco apostadores. A quantidade aceita vai de 1 a 92 para evitar estouro do tipo inteiro usado no cálculo.
- **Atividade 5:** para cada participante, informe nome, idade, quantidade de valores e depois os valores. A quantidade deve ser maior que zero.

Na atividade 3, a correspondência dos números com frequência par usa a posição da primeira ocorrência no vetor como índice da lista de animais. Na atividade 5, se o ID calculado pela segunda fórmula ainda se repetir, o programa avança para o próximo valor representável até torná-lo único.

## Compilação

Use GCC:

`gcc arquivo.c -o programa`

Na atividade 5, inclua a biblioteca matemática:

`gcc 05-cadastro-media-e-diagonal.c -o programa -lm`

---

[Voltar para Exercícios](../README.md)
