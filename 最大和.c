#include <stdio.h>

int main(void)
{
    int n, m, sum = 0, max;
    int num[25];
    int ans[25];

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){

        max = 0;

        for(int j = 0; j < m; j++){
            scanf("%d", &num[j]);

            if(num[j] > max){
                max = num[j];
            }
        }

        ans[i] = max;
        sum += max;
    }

    printf("%d\n", sum);

    int count = 0;

    for(int i = 0; i < n; i++){
        if(sum % ans[i] == 0){

            if(count > 0){
                printf(" ");
            }

            printf("%d", ans[i]);
            count++;
        }
    }

    if(count == 0){
        printf("-1");
    }

    printf("\n");

    return 0;
}
