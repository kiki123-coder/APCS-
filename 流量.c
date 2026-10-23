#include <stdio.h>

int flow[1005][1005];
int place[1005];
long long sum[1005][1005];

int main(void)
{
    int n, m, k;
    int i, j, x, y, t;
    long long cost, ans = 0;
    long long f;

    scanf("%d %d %d", &n, &m, &k);

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &flow[i][j]);
        }
    }

    for(t = 0; t < k; t++){
        for(i = 0; i < n; i++){
            scanf("%d", &place[i]);
        }

        for(i = 0; i < m; i++){
            for(j = 0; j < m; j++){
                sum[i][j] = 0;
            }
        }

        for(i = 0; i < n; i++){
            x = place[i];

            for(j = 0; j < m; j++){
                sum[x][j] += flow[i][j];
            }
        }

        cost = 0;

        for(x = 0; x < m; x++){
            for(y = 0; y < m; y++){
                f = sum[x][y];

                if(x == y){
                    cost += f;
                }
                else if(f <= 1000){
                    cost += f * 3;
                }
                else{
                    cost += 3000 + (f - 1000) * 2;
                }
            }
        }

        if(t == 0 || cost < ans){
            ans = cost;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
