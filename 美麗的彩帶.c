#include <stdio.h>

int main(void)
{
    int m, n, num = 0;
    int color[200000];
    int last[200001] = {0};

    scanf("%d %d", &m, &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &color[i]);
    }

    int left = 0;

    for(int i = 0; i < n; i++){
        if(color[i] >= 0 && color[i] <= 200000){
            if(last[color[i]] > left){
                left = last[color[i]];
            }
            last[color[i]] = i + 1;
        }

        if(i - left + 1 >= m){
            num++;
        }
    }

    printf("%d\n", num);

    return 0;
}
