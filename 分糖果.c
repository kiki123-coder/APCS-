#include <stdio.h>

int main(void)
{
    int n, m, sum = 0;
    int K = 0, A, R;
    int num[100];

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n - 1; i++){
        if(num[i] > K){
            K = num[i];
        }
    }
    for(int i = 0; i < n; i++){
        sum += num[i];
    }

    sum = sum - K;
    A = sum / m;
    R = sum - A * m;

    if(R > m / 2){
        R = m - R;
    }
    printf("%d %d %d\n", K, A, R);

    return 0;
}
