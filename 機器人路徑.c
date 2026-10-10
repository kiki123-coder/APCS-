#include <stdio.h>

int main(void)
{
    int n, m;
    int map[100][100] = {0};
    int visited[100][100] = {0};
    int road = 0;
    int x = 0, y = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // 找出起點：整張地圖的最小值
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] < map[x][y]){
                x = i;
                y = j;
            }
        }
    }

    while(1){
        visited[x][y] = 1;
        road += map[x][y];

        int nx = -1, ny = -1;
        int min = 1000000;

        // 檢查上下左右
        for(int k = 0; k < 4; k++){
            int a = x + dx[k];
            int b = y + dy[k];

            if(a < 0 || a >= n || b < 0 || b >= m)
                continue;

            if(visited[a][b] == 0 && map[a][b] < min){
                min = map[a][b];
                nx = a;
                ny = b;
            }
        }

        // 沒有可走的格子就結束
        if(nx == -1)
            break;

        x = nx;
        y = ny;
    }

    printf("%d\n", road);

    return 0;
}
