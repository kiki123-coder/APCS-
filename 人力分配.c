#include <stdio.h>
#include <math.h>

long long a, b, c, d, e, f, n;

long long profit(long long x)
{
    long long y = n - x;
    return a*x*x + b*x + c + d*y*y + e*y + f;
}

int main(void)
{
    scanf("%lld %lld %lld", &a, &b, &c);
    scanf("%lld %lld %lld", &d, &e, &f);
    scanf("%lld", &n);

    long long A = a + d;
    long long B = b - e - 2*d*n;

    long long ans = profit(0);
    long long temp = profit(n);

    if(temp > ans)
        ans = temp;

    if(A < 0){
        long long x = (long long)floorl(-(long double)B / (2.0L * A));

        for(long long i = x - 1; i <= x + 2; i++){
            if(i >= 0 && i <= n){
                temp = profit(i);

                if(temp > ans)
                    ans = temp;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
