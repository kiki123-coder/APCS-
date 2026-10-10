#include <stdio.h>

int main(void)
{
    int R, C, M;
    int a[10][10];
    int b[10][10];
    int op[10];

    scanf("%d %d %d", &R, &C, &M);

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < M; i++){
        scanf("%d", &op[i]);
    }


    for(int k = M - 1; k >= 0; k--){

        if(op[k] == 0){
            // 逆時針旋轉
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    b[C - 1 - j][i] = a[i][j];
                }
            }

            int t = R;
            R = C;
            C = t;
        }
        else{
            // 上下翻轉
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    b[R - 1 - i][j] = a[i][j];
                }
            }
        }

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                a[i][j] = b[i][j];
            }
        }
    }

    printf("%d %d\n", R, C);

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(j > 0)
                printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
