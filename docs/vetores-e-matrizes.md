# Vetores e Matrizes

Estruturas de dados usadas para armazenar múltiplos valores relacionados.

## Conteúdo

- Vetores (arrays unidimensionais)
- Matrizes (arrays bidimensionais)
- Percorrendo vetores e matrizes
- Busca e ordenação simples

## Exemplo (pseudocódigo)

```text
algoritmo "maior_valor"
  var
    numeros: vetor[1..5] de inteiro
    i, maior: inteiro
  inicio
    para i de 1 ate 5 faca
      escreva("Digite o valor ", i, ": ")
      leia(numeros[i])
    fimpara

    maior <- numeros[1]
    para i de 2 ate 5 faca
      se (numeros[i] > maior) entao
        maior <- numeros[i]
      fimse
    fimpara

    escreva("O maior valor é: ", maior)
fimalgoritmo
```

## Objetivo

Organizar estudos sobre estruturas de dados básicas (vetores e matrizes).

---

[Voltar](https://github.com/NicollasRodrigo/estudo-logica-programacao/blob/main/docs/README.md)
