#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int l);

int main(void)
{
    int N;
    int num[21];

    scanf("%d", &N);

    for(int i = 0; i <= N - 1; i++){
        scanf("%d", &num[i]);
    }
    sort(num, N);

    for(int i = 0; i <= N - 1; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    if(num[0] >= 60){
        printf("best case\n");
        printf("%d \n", num[0]);
    }
    else if(num[N - 1] < 60){
        printf("%d \n", num[N - 1]);
        printf("worst case");
    }
    else{
        for(int i = N - 1; i >= 0; i--){
            if(num[i] < 60){
                printf("%d\n", num[i]);
                break;
            }
        }
        for(int i = 0; i <= N - 1; i++){
            if(num[i] >= 60){
                printf("%d\n", num[i]);
                break;
            }
        }
    }
    return 0;
}

void sort(int *a, int l)
{
    int i, j;
    int v;
    //開始排序
    for(i = 0; i < l - 1; i++){
        for(j = i + 1; j < l; j++){
            if(a[i] > a[j]){
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
    }
}
