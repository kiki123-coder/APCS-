#include <stdio.h>

int a[2000005];
int first[1000005];
int tree[1000005];
int n;

void add(int x)
{
    while(x <= n){
        tree[x]++;
        x += x & -x;
    }
}

int query(int x)
{
    int sum = 0;

    while(x > 0){
        sum += tree[x];
        x -= x & -x;
    }

    return sum;
}

int main(void)
{
    int i, x;
    long long ans = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        first[i] = -1;

    for(i = 0; i < 2 * n; i++){
        scanf("%d", &x);

        if(first[x] == -1){
            first[x] = query(x - 1);
        }
        else{
            ans += query(x - 1) - first[x];
        }

        add(x);
    }

    printf("%lld\n", ans);

    return 0;
}
