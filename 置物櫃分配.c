#include <stdio.h>

int main(void)
{
    int M, S, N;
    int x[100];
    int dp[100001] = {0};
    int sum = 0;
    int i, j, need;

    scanf("%d %d %d", &M, &S, &N);

    for(i = 0; i < N; i++){
        scanf("%d", &x[i]);
        sum += x[i];
    }

    need = S - (M - sum);

    if(need <= 0){
        printf("0\n");
        return 0;
    }

    dp[0] = 1;

    for(i = 0; i < N; i++){
        for(j = sum - x[i]; j >= 0; j--){
            if(dp[j])
                dp[j + x[i]] = 1;
        }
    }

    for(i = need; i <= sum; i++){
        if(dp[i]){
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
