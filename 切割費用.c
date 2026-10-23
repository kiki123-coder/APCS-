#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos, order;
} Cut;

Cut a[200005];
int left[200005], right[200005], stack[200005];

int cmp(const void *x, const void *y)
{
    Cut a1 = *(Cut *)x;
    Cut a2 = *(Cut *)y;

    return (a1.pos > a2.pos) - (a1.pos < a2.pos);
}

int main(void)
{
    int N, L;
    int i, top = 0;
    long long ans = 0;

    scanf("%d %d", &N, &L);

    for(i = 0; i < N; i++)
        scanf("%d %d", &a[i].pos, &a[i].order);

    qsort(a, N, sizeof(Cut), cmp);

    for(i = 0; i < N; i++){
        while(top > 0 && a[stack[top - 1]].order > a[i].order)
            top--;

        if(top == 0)
            left[i] = 0;
        else
            left[i] = a[stack[top - 1]].pos;

        stack[top++] = i;
    }

    top = 0;

    for(i = N - 1; i >= 0; i--){
        while(top > 0 && a[stack[top - 1]].order > a[i].order)
            top--;

        if(top == 0)
            right[i] = L;
        else
            right[i] = a[stack[top - 1]].pos;

        stack[top++] = i;
    }

    for(i = 0; i < N; i++)
        ans += right[i] - left[i];

    printf("%lld\n", ans);

    return 0;
}
