#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int k;
    char str[100001];

    scanf("%d", &k);
    scanf("%100000s", str);

    int len = strlen(str);
    int now = 0;
    int ans = 0;

    for(int i = 0; i < len; ){

        int j = i;

        // 找出連續相同大小寫的一段
        while(j < len && (islower((unsigned char)str[i]) == islower((unsigned char)str[j]))){
            j++;
        }

        int count = j - i;

        if(count == k){
            // 剛好 k 個，可以接在前面的交錯字串後面
            now += k;
        }
        else if(count < k){
            // 不足 k 個，交錯字串中斷
            if(now > ans)
                ans = now;

            now = 0;
        }
        else{
            // 超過 k 個，只能取 k 個，並重新開始
            now += k;

            if(now > ans)
                ans = now;

            now = k;
        }

        i = j;
    }

    if(now > ans)
        ans = now;

    printf("%d\n", ans);

    return 0;
}
