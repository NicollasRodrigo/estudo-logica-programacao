# Aula 08 — Ponteiros e Vetores Dinâmicos

Atividades práticas do material da aula, organizadas na ordem do enunciado.

## Atividades

| Atividade | Conteúdo | Arquivo |
|---|---|---|
| 1 | Contagem de ocorrências e cadastro de produtos | [01-numeros-e-produtos.c](./01-numeros-e-produtos.c) |
| 2 | Separação e ordenação de números | [02-positivos-pares-e-negativos-impares.c](./02-positivos-pares-e-negativos-impares.c) |
| 3 | Números primos, frequências e cadastro de animais | [03-repetidos-primos-e-animais.c](./03-repetidos-primos-e-animais.c) |
| 4 | Sequência de Fibonacci e classificação dos apostadores | [04-fibonacci-e-vencedores.c](./04-fibonacci-e-vencedores.c) |
| 5 | Cadastro de participantes, médias e matriz | [05-cadastro-media-e-diagonal.c](./05-cadastro-media-e-diagonal.c) |

## Entrada de dados

- **Atividade 1:** informe 12 inteiros. Se um número negativo aparecer uma quantidade ímpar de vezes, o programa solicita os números novamente. Para cada número não negativo com frequência ímpar, informe os nomes e preços dos produtos.
- **Atividade 2:** informe 10 inteiros.
- **Atividade 3:** informe 15 inteiros. Para cada número primo com frequência ímpar, cadastre nomes de animais em quantidade igual ao produto entre o número e sua frequência. Os nomes seguem a ordem da primeira aparição.
- **Atividade 4:** informe o nome e a quantidade de termos para cada um dos cinco apostadores. O limite aceito é de 1 a 92 termos para evitar estouro do tipo inteiro usado no cálculo.
- **Atividade 5:** informe nome, idade, quantidade de valores e, em seguida, os valores de cada participante.

## Compilação

Compile cada atividade separadamente com GCC:

```bash
gcc 01-numeros-e-produtos.c -o atividade1
gcc 02-positivos-pares-e-negativos-impares.c -o atividade2
gcc 03-repetidos-primos-e-animais.c -o atividade3
gcc 04-fibonacci-e-vencedores.c -o atividade4
gcc 05-cadastro-media-e-diagonal.c -o atividade5 -lm
```

## Observações

- Na atividade 3, para números com frequência par, a posição da primeira ocorrência no vetor é usada como índice na lista de animais. Se não houver essa posição, o programa informa que não há correspondência.
- Na atividade 5, o enunciado não especifica como variar a segunda fórmula quando ela também gera um ID repetido. O código avança para o próximo valor representável até encontrar um ID exclusivo; valores fora da capacidade do tipo são recusados.

---

[Voltar para Exercícios](../README.md)
