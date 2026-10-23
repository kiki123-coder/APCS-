#include <stdio.h>

int main(void)
{
    int a, b, n;
    int x, i;
    int cntA, cntB;
    int ans = 0;

    scanf("%d %d", &a, &b);
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        cntA = 0;
        cntB = 0;

        while(1){
            scanf("%d", &x);

            if(x == 0)
                break;

            if(x == a)
                cntA++;
            else if(x == -a)
                cntA--;

            if(x == b)
                cntB++;
            else if(x == -b)
                cntB--;
        }

        if(cntA > 0 && cntB > 0)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
