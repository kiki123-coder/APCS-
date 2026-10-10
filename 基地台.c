#include <stdio.h>
#include <stdlib.h>
//qsort¼gªk
int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int main(void)
{
    int n, k;
    int point[100000];
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &point[i]);
    }

    qsort(point, n, sizeof(int), cmp);

    int left = 0;
    int right = point[n - 1] - point[0];

    while(left < right){
        int d = left + (right - left) / 2;
        int count = 0;
        int i = 0;

        while(i < n){
            int end = point[i] + d;
            count++;

            while(i < n && point[i] <= end){
                i++;
            }
        }

        if(count <= k){
            right = d;
        }
        else{
            left = d + 1;
        }
    }

    printf("%d\n", left);

    return 0;
}

