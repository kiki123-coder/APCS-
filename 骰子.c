#include <stdio.h>

int up[25], front[25], right[25];

int main(void)
{
    int n, m;
    int a, b, i, temp;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++){
        up[i] = 1;
        front[i] = 4;
        right[i] = 2;
    }

    for(i = 0; i < m; i++){
        scanf("%d %d", &a, &b);

        if(b > 0){
            temp = up[a];
            up[a] = up[b];
            up[b] = temp;

            temp = front[a];
            front[a] = front[b];
            front[b] = temp;

            temp = right[a];
            right[a] = right[b];
            right[b] = temp;
        }
        else if(b == -1){
            temp = up[a];
            up[a] = 7 - front[a];
            front[a] = temp;
        }
        else if(b == -2){
            temp = up[a];
            up[a] = 7 - right[a];
            right[a] = temp;
        }
    }

    for(i = 1; i <= n; i++){
        if(i > 1)
            printf(" ");
        printf("%d", up[i]);
    }

    printf("\n");
    return 0;
}
