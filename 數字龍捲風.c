#include <stdio.h>

int main(void)
{
    int arr[100][100];
    int N, direction;

    scanf("%d %d", &N, &direction);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int x = N / 2;
    int y = N / 2;

    printf("%d", arr[x][y]);

    int step = 1;
    int count = 1;

    if(direction == 0){

        while(count < N * N){

            // 左
            for(int i = 0; i < step && count < N * N; i++){
                y--;
                printf("%d", arr[x][y]);
                count++;
            }

            // 上
            for(int i = 0; i < step && count < N * N; i++){
                x--;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;

            // 右
            for(int i = 0; i < step && count < N * N; i++){
                y++;
                printf("%d", arr[x][y]);
                count++;
            }

            // 下
            for(int i = 0; i < step && count < N * N; i++){
                x++;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;
        }
    }

    else if(direction == 1){

        while(count < N * N){

            // 上
            for(int i = 0; i < step && count < N * N; i++){
                x--;
                printf("%d", arr[x][y]);
                count++;
            }

            // 右
            for(int i = 0; i < step && count < N * N; i++){
                y++;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;

            // 下
            for(int i = 0; i < step && count < N * N; i++){
                x++;
                printf("%d", arr[x][y]);
                count++;
            }

            // 左
            for(int i = 0; i < step && count < N * N; i++){
                y--;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;
        }
    }

    else if(direction == 2){

        while(count < N * N){

            // 右
            for(int i = 0; i < step && count < N * N; i++){
                y++;
                printf("%d", arr[x][y]);
                count++;
            }

            // 下
            for(int i = 0; i < step && count < N * N; i++){
                x++;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;

            // 左
            for(int i = 0; i < step && count < N * N; i++){
                y--;
                printf("%d", arr[x][y]);
                count++;
            }

            // 上
            for(int i = 0; i < step && count < N * N; i++){
                x--;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;
        }
    }

    else if(direction == 3){

        while(count < N * N){

            // 下
            for(int i = 0; i < step && count < N * N; i++){
                x++;
                printf("%d", arr[x][y]);
                count++;
            }

            // 左
            for(int i = 0; i < step && count < N * N; i++){
                y--;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;

            // 上
            for(int i = 0; i < step && count < N * N; i++){
                x--;
                printf("%d", arr[x][y]);
                count++;
            }

            // 右
            for(int i = 0; i < step && count < N * N; i++){
                y++;
                printf("%d", arr[x][y]);
                count++;
            }

            step++;
        }
    }

    printf("\n");

    return 0;
}
