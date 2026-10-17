#include <stdio.h>

int a[1005][1005];
int delta[1005][1005];

int main(void)
{
    int n, m, k, days;
    int i, j, d;
    int ni, nj;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int mn = 2147483647, mx = 0;

    scanf("%d %d %d %d", &n, &m, &k, &days);

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    while(days--){
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                delta[i][j] = 0;
            }
        }

        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(a[i][j] == -1)
                    continue;

                for(d = 0; d < 4; d++){
                    ni = i + dx[d];
                    nj = j + dy[d];

                    if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                        continue;

                    if(a[ni][nj] == -1)
                        continue;

                    delta[i][j] -= a[i][j] / k;
                    delta[ni][nj] += a[i][j] / k;
                }
            }
        }

        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(a[i][j] != -1)
                    a[i][j] += delta[i][j];
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(a[i][j] == -1)
                continue;

            if(a[i][j] < mn)
                mn = a[i][j];

            if(a[i][j] > mx)
                mx = a[i][j];
        }
    }

    printf("%d\n%d\n", mn, mx);

    return 0;
}
