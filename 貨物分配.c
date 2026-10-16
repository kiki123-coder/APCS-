#include <stdio.h>

int sum[2000005];
int left[2000005], right[2000005];
int w[10005];
int order[2000005];

int main(void)
{
    int n, m;
    int i, a, b, c, now;
    int cnt = 1;

    scanf("%d %d", &n, &m);

    for(i = n; i <= 2 * n - 1; i++)
        scanf("%d", &sum[i]);

    for(i = 0; i < m; i++)
        scanf("%d", &w[i]);

    for(i = 0; i < n - 1; i++){
        scanf("%d %d %d", &a, &b, &c);
        left[a] = b;
        right[a] = c;
    }

    /* 由上往下記錄節點順序 */
    order[0] = 1;

    for(i = 0; i < cnt; i++){
        int x = order[i];

        if(left[x] != 0){
            order[cnt++] = left[x];
            order[cnt++] = right[x];
        }
    }

    /* 反向計算每個分貨站的初始總重量 */
    for(i = cnt - 1; i >= 0; i--){
        int x = order[i];

        if(left[x] != 0)
            sum[x] = sum[left[x]] + sum[right[x]];
    }

    /* 依序分配貨物 */
    for(i = 0; i < m; i++){
        now = 1;

        while(left[now] != 0){
            if(sum[left[now]] <= sum[right[now]])
                now = left[now];
            else
                now = right[now];

            sum[now] += w[i];
        }

        printf("%d", now);

        if(i < m - 1)
            printf(" ");
    }

    printf("\n");

    return 0;
}
