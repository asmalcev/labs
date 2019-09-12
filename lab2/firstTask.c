#include <stdio.h>

int main() {
    float m,n;
    scanf("%f %f", &m, &n);
    printf("%f\n", n > -5 && m != 0 ? 5 / m - n / 5 : n <= -5 ? 3*m + n*n : 2*m*n);
}