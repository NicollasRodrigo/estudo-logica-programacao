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

- **Atividade 1:** informe 12 inteiros. Se um número negativo aparecer uma quantidade ímpar de vezes, o programa solicitará a entrada dos 12 números novamente. Para cada número positivo ou zero com quantidade ímpar de ocorrências, cadastre essa quantidade de produtos: nome em uma linha e preço na seguinte.
- **Atividade 2:** informe 10 inteiros.
- **Atividade 3:** informe 15 inteiros. Para cada número primo com frequência ímpar (inclusive uma ocorrência), cadastre nomes de animais em quantidade igual à soma de suas ocorrências (valor × frequência). Os nomes são lidos na ordem em que os números aparecem pela primeira vez.
- **Atividade 4:** informe nome e quantidade de termos para cada um dos cinco apostadores. A quantidade aceita vai de 1 a 92 para evitar estouro do tipo inteiro usado no cálculo.
- **Atividade 5:** para cada participante, informe nome, idade, quantidade de valores e, em seguida, os valores. A quantidade deve ser maior que zero.

Na atividade 3, para números com frequência par, a posição da primeira ocorrência no vetor é usada como índice da lista de animais. Se essa posição não existir na lista cadastrada, o programa informa que não há correspondência.

Na atividade 5, o enunciado não define como variar a segunda fórmula quando ela também gera um ID repetido. Para evitar repetição infinita, o código avança para o próximo valor representável até encontrar um ID exclusivo. IDs que ultrapassam a capacidade numérica do tipo usado são recusados.

## Compilação

Use GCC:

`gcc arquivo.c -o programa`

Na atividade 5, inclua a biblioteca matemática:

`gcc 05-cadastro-media-e-diagonal.c -o programa -lm`

---

[Voltar para Exercícios](../README.md)
