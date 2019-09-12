#include <stdio.h>

int main() {
    int x1,y1,x2,y2,x3,y3;
    printf("white unit: ");
    scanf("%d %d",&x1,&y1);
    printf("black units: ");
    scanf("%d %d %d %d",&x2,&y2,&x3,&y3);
    if (x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2) {
        printf("yes");
    } else {
        if (x1 - y1 == x3 - y3 || x1 + y1 == x3 + y3) {
            printf("yes");
        } else {
            printf("no");
        }
    }
}