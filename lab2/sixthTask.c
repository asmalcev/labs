#include <stdio.h>

int main() {
    long int n;
    scanf("%ld", &n);
    while (n > 0) {
        printf("%ld", n % 10);
        n /= 10;
    }
    printf("\n");
}