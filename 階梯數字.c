#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL

int main(void)
{
    char n[1000010];
    long long ans;
    long long inv[10];

    inv[1] = 1;
    for(int i = 2; i <= 9; i++){
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    while(scanf("%s", n) != EOF){
        int len = strlen(n);
        long long ways[10];

        // 計算比 n 少一位數的所有階梯數字
        ways[0] = 1;
        for(int i = 1; i <= 9; i++)
            ways[i] = ways[i - 1] * (len - 1 + i) % MOD * inv[i] % MOD;

        ans = (ways[9] - 1 + MOD) % MOD;

        int prev = 1;
        int ok = 1;

        for(int i = 0; i < len; i++){
            int digit = n[i] - '0';
            int rem = len - 1 - i;
            int lower = (i == 0) ? 1 : prev;

            ways[0] = 1;
            for(int k = 1; k <= 9; k++)
                ways[k] = ways[k - 1] * (rem + k) % MOD * inv[k] % MOD;

            for(int d = lower; d < digit; d++){
                int k = 9 - d;
                ans = (ans + ways[k]) % MOD;
            }

            if(digit < lower){
                ok = 0;
                break;
            }

            prev = digit;
        }

        if(ok)
            ans = (ans + 1) % MOD;

        printf("%lld\n", ans);
    }

    return 0;
}

