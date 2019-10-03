#include <stdio.h>

int main() {
    for (int i = 10; i < 50; i++)
        if (2*((i % 10) + (i / 10)) == (i % 10)*(i / 10))
            if (i / 10 == i % 10)
                printf("%d\n", i);
            else
                printf("%d\n%d%d\n", i, i % 10, i / 10);
}