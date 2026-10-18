#include <stdio.h>

int a[55][10005];
int dp[55][10005];
int left[10005], right[10005];

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int m, n;
    int i, j, sum;

    scanf("%d %d", &m, &n);

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    /* 第一排：可以從任意位置開始 */
    sum = a[0][0];
    left[0] = sum;

    for(j = 1; j < n; j++){
        sum = max(0, sum) + a[0][j];
        left[j] = sum;
    }

    sum = a[0][n-1];
    right[n-1] = sum;

    for(j = n-2; j >= 0; j--){
        sum = max(0, sum) + a[0][j];
        right[j] = sum;
    }

    for(j = 0; j < n; j++)
        dp[0][j] = max(left[j], right[j]);

    /* 後面的每一排 */
    for(i = 1; i < m; i++){
        left[0] = dp[i-1][0] + a[i][0];

        for(j = 1; j < n; j++){
            left[j] = max(dp[i-1][j], left[j-1]) + a[i][j];
        }

        right[n-1] = dp[i-1][n-1] + a[i][n-1];

        for(j = n-2; j >= 0; j--){
            right[j] = max(dp[i-1][j], right[j+1]) + a[i][j];
        }

        for(j = 0; j < n; j++)
            dp[i][j] = max(left[j], right[j]);
    }

    int ans = dp[m-1][0];

    for(j = 1; j < n; j++)
        ans = max(ans, dp[m-1][j]);

    printf("%d\n", ans);

    return 0;
}
