#include <stdio.h>
#include <stdlib.h>

int w[100000];
int f[100000];

int compare(const void *a, const void *b)
{
    int i = *(int *)a;
    int j = *(int *)b;

    if((long long)w[i] * f[j] < (long long)w[j] * f[i])
        return -1;
    if((long long)w[i] * f[j] > (long long)w[j] * f[i])
        return 1;
    return 0;
}

int main(void)
{
    int n;
    int id[100000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
        id[i] = i;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &f[i]);
    }

    qsort(id, n, sizeof(int), compare);

    long long sum = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        int j = id[i];
        ans += sum * f[j];
        sum += w[j];
    }

    printf("%lld\n", ans);

    return 0;
}
