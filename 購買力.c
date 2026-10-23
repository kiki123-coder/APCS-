#include <stdio.h>

int main(void)
{
    int n, k;
    int a, b, c;
    int max, min;
    int count = 0, total = 0;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &c);

        max = a;
        min = a;

        if(b > max) max = b;
        if(c > max) max = c;

        if(b < min) min = b;
        if(c < min) min = c;

        if(max - min >= k){
            count++;
            total += (a + b + c) / 3;
        }
    }

    printf("%d %d\n", count, total);

    return 0;
}
