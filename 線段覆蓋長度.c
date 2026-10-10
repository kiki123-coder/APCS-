#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int l;
    int r;
} Line;

int cmp(const void *a, const void *b)
{
    Line *x = (Line *)a;
    Line *y = (Line *)b;

    return x->l - y->l;
}

int main(void)
{
    int N;
    Line a[10000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &a[i].l, &a[i].r);

    qsort(a, N, sizeof(Line), cmp);

    int left = a[0].l;
    int right = a[0].r;
    int ans = 0;

    for(int i = 1; i < N; i++){

        if(a[i].l > right){
            ans += right - left;

            left = a[i].l;
            right = a[i].r;
        }
        else{
            if(a[i].r > right)
                right = a[i].r;
        }
    }

    ans += right - left;

    printf("%d\n", ans);

    return 0;
}
