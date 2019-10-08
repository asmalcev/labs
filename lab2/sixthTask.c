#include <stdio.h>

int main() {
    long int n, b = 0;
    scanf("%ld", &n);
    while (n > 0) {
        b = b*10 + n % 10;
        n /= 10;
    }
    printf("%ld\n", b);
}