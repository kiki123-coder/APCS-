#include <stdio.h>

int main(void)
{
    int N, M, K;
    int pos = 0;

    scanf("%d %d %d", &N, &M, &K);

    // 先假設最後剩下的 K 次淘汰後的圈子中，
    // 幸運者的位置是 0
    //
    // 再從 N-K+1 人一路反推回 N 人
    for(int n = N - K + 1; n <= N; n++){
        pos = (pos + M) % n;
    }

    // pos 是 0-based，所以 +1 變成人的編號
    printf("%d\n", pos + 1);

    return 0;
}
