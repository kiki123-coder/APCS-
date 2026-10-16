#include <stdio.h>

int S[1000005];
int step[1000005];
int que[1000005];

int main(void)
{
    int n, P, L, R;
    int i, head = 0, tail = 0;
    int x, v, d;

    scanf("%d %d %d %d", &n, &P, &L, &R);

    for(i = 0; i < n; i++)
        scanf("%d", &S[i]);

    for(i = 0; i < n; i++)
        step[i] = -1;

    step[0] = 0;
    que[tail++] = 0;

    while(head < tail){
        x = que[head++];

        if(x == P){
            printf("%d\n", step[x]);
            return 0;
        }

        for(i = 0; i < 2; i++){
            if(i == 0)
                d = -L;
            else
                d = R;

            v = x + d;

            if(v < 0 || v >= n)
                continue;

            v = S[v];

            if(v < 0 || v >= n)
                continue;

            if(step[v] != -1)
                continue;

            step[v] = step[x] + 1;
            que[tail++] = v;
        }
    }

    printf("-1\n");

    return 0;
}
