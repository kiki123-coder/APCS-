#include <stdio.h>

int main(void)
{
    int a, b, c;
    int count = 0;

    scanf("%d %d %d", &a, &b, &c);

    if ((a != 0 && b != 0) == c) {
        printf("AND\n");
        count++;
    }

    if ((a != 0 || b != 0) == c) {
        printf("OR\n");
        count++;
    }

    if ((a != 0 && b == 0) || (a == 0 && b != 0)) {
        if (c == 1) {
            printf("XOR\n");
            count++;
        }
    }
    else {
        if (c == 0) {
            printf("XOR\n");
            count++;
        }
    }

    if (count == 0) {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
