#include <stdio.h>

int main() {
    float a,b;
    int c,d;
    scanf("%f %d", &b, &d);
    a = c = 5;
    printf("%6.3f %6.3f %d %d\n", a,b,c,d);
    a += b - 2;
    printf("%6.3f %6.3f %d %d\n", a,b,c,d);
    d += ++c - a;
    printf("%6.3f %6.3f %d %d\n", a,b,c,d);
    a *= c--;
    printf("%6.3f %6.3f %d %d\n", a,b,c,d);
    d *= ((c /= 2) + --b + (a /= 10));
    printf("%6.3f %6.3f %d %d\n", a,b,c,d);
}