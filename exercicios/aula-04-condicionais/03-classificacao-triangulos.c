#include <stdio.h>

int main(void) {
    int a, b, c, maior, x, y;
    long long soma, quadradoMaior, somaQuadrados;

    printf("Tres lados: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0 ||
        (long long)a + b <= c ||
        (long long)a + c <= b ||
        (long long)b + c <= a) {
        printf("Nao forma triangulo.\n");
        return 0;
    }

    if (a == b && b == c) printf("Equilatero\n");
    else if (a == b || a == c || b == c) printf("Isosceles\n");
    else printf("Escaleno\n");

    maior = a; x = b; y = c;
    if (b > maior) { maior = b; x = a; y = c; }
    if (c > maior) { maior = c; x = a; y = b; }

    quadradoMaior = (long long)maior * maior;
    somaQuadrados = (long long)x * x + (long long)y * y;

    if (quadradoMaior == somaQuadrados) printf("Retangulo\n");
    else if (quadradoMaior < somaQuadrados) printf("Acutangulo\n");
    else printf("Obtusangulo\n");

    return 0;
}
