#include <stdio.h>

int main(void)
{
    int N, K, P;
    int x[50];
    int min = 100, max = 0;
    int count = 0, last = 0;

    scanf("%d %d %d", &N, &K, &P);

    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);

        if(x[i] < min)
            min = x[i];

        if(x[i] > max)
            max = x[i];
    }

    for(int i = min; i <= max; i++){

        int turn = (i - min) % N + 1;

        if(turn == P && (i % 10 == K || i / 10 == K)){
            count++;
            last = i;
        }
    }

    printf("%d %d\n", count, last);

    return 0;
}
