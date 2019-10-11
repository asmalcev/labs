#include <stdio.h>
#include <math.h>

int main() {
    float s, a, b;
    scanf("%f %f", &a, &b);
    if (b > 0 && 2.5*a + 3 * b > - sqrt(2)) {
      s = (sin(pow(a, 3)) + 2*pow(cos(b), 2)) /
           (sqrt(2.5*a + 3*b + sqrt(2)) * log(b));
      printf("%lf\n", s);
    } else {
      printf("doesn't fit in OOF\n");
    }
}