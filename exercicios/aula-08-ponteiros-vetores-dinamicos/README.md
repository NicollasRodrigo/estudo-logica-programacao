# Aula 08 — Ponteiros e Vetores Dinâmicos

Atividades do material da Aula 08, organizadas na mesma ordem do PDF.

## Atividades

| Atividade | Conteúdo | Arquivo |
|---|---|---|
| 1 | Contagem de ocorrências, cadastro e ordenação de produtos | [01-numeros-e-produtos.c](./01-numeros-e-produtos.c) |
| 2 | Separação de positivos pares e negativos ímpares | [02-positivos-pares-e-negativos-impares.c](./02-positivos-pares-e-negativos-impares.c) |
| 3 | Números repetidos, primos e correspondência de animais | [03-repetidos-primos-e-animais.c](./03-repetidos-primos-e-animais.c) |
| 4 | Soma de Fibonacci e classificação dos apostadores | [04-fibonacci-e-vencedores.c](./04-fibonacci-e-vencedores.c) |
| 5 | Cadastro, média ponderada e diagonal | [05-cadastro-media-e-diagonal.c](./05-cadastro-media-e-diagonal.c) |

## Como executar

Compile cada arquivo separadamente com GCC:

```bash
gcc 01-numeros-e-produtos.c -o atividade1
gcc 02-positivos-pares-e-negativos-impares.c -o atividade2
gcc 03-repetidos-primos-e-animais.c -o atividade3
gcc 04-fibonacci-e-vencedores.c -o atividade4
gcc 05-cadastro-media-e-diagonal.c -o atividade5 -lm
```

Execute o programa correspondente depois da compilação.

## Observações sobre a entrada

- **Atividade 1:** informe 12 inteiros. Quando um número negativo tiver quantidade ímpar de ocorrências, o programa solicitará os 12 números novamente, pois uma quantidade de produtos não pode ser negativa. Para cada número não negativo com ocorrências ímpares, informe a quantidade correspondente de produtos, com nome e preço.
- **Atividade 2:** informe 10 inteiros. O programa apresenta separadamente os positivos pares e os negativos ímpares, ambos em ordem crescente.
- **Atividade 3:** informe 15 inteiros. Para cada número primo com quantidade ímpar de ocorrências, cadastre nomes de animais em quantidade igual ao número multiplicado pela quantidade de ocorrências. Para números com quantidade par de ocorrências, a posição da primeira aparição no vetor é usada para procurar um animal na lista cadastrada. Se o índice não existir, o programa informa que não há correspondência.
- **Atividade 4:** informe nome e quantidade de termos para cada um dos cinco apostadores. O programa aceita de 1 a 92 termos para manter o cálculo dentro do tipo inteiro utilizado. A saída apresenta somente as colocações e os nomes dos vencedores, incluindo a indicação de vaga sem vencedor quando necessário.
- **Atividade 5:** informe nome, idade, quantidade de valores e os valores de cada participante. O programa considera os dois primeiros valores não negativos informados como lados do retângulo. Os valores de cada participante permanecem associados ao respectivo cadastro durante a ordenação alfabética.

## Critérios e observações

- As cinco atividades do PDF estão representadas por um arquivo C cada.
- Na atividade 3, a listagem de ocorrências destaca os números que aparecem mais de uma vez, conforme o item (a) do enunciado.
- Na atividade 5, se a segunda fórmula de ID também produzir duplicidade, o programa avança para o próximo valor representável para garantir um ID exclusivo. Essa é uma solução de desempate para evitar repetição infinita, já que repetir exatamente a mesma fórmula com os mesmos dados produziria o mesmo resultado.
- A atividade 5 usa alocação dinâmica por participante para armazenar quantidades diferentes de valores, mantendo os dados associados ao participante.

---

[Voltar para Exercícios](../README.md)
