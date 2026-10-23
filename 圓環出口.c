#include <stdio.h>

int p[200005];
long long sum[200005];

int main(void)
{
    int n, m;
    int i, pos = 0, l, r, mid;
    long long q, total, target;

    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
        sum[i + 1] = sum[i] + p[i];
    }

    total = sum[n];

    for(i = 0; i < m; i++){
        scanf("%lld", &q);

        target = sum[pos] + q;

        if(target > total)
            target -= total;

        l = 1;
        r = n;

        while(l < r){
            mid = (l + r) / 2;

            if(sum[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }

        pos = l % n;
    }

    printf("%d\n", pos);

    return 0;
}
