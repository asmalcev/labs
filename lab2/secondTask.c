#include <stdio.h>
#include <math.h>

int main() {
    float s,a,b;
    scanf("%f %f", &a, &b);
    s = (sin(pow(a, 3)) + 2*pow(cos(b), 2)) /
         pow(2.5*a + 3*b + pow(2, 0.5), 0.5) / log(b);
}