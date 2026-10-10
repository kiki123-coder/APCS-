#include <stdio.h>

int letter[10000] = {0};

int max(int num[4]);

int main(void)
{
    letter[101] = 'A';
    letter[111] = 'B';
    letter[10] = 'C';
    letter[1101] = 'D';
    letter[1000] = 'E';
    letter[1100] = 'F';

    int n, m;
    int num[4];
    int ans;
    while(scanf("%d", &n) != EOF){
        m = n;
        for(int j = 0; j < n ; j++){
            for(int i = 0; i < 4; i++){
                scanf("%d", &num[i]);
            }
            ans = max(num);
            printf("%c", letter[ans]);
            m--;
        }
        if(m == 0){
            printf("\n");
        }
    }
    return 0;
}

int max(int num[4])
{
    int ans = 0;

    ans = (num[0] * 1000) + (num[1] * 100) + (num[2] * 10) + num[3];

    return ans;
}
