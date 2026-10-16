#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char s[30], up[30], down[30];
    long long n, a, b;
    int len, i, j;

    while(scanf("%lld", &n) != EOF){
        sprintf(s, "%lld", n);
        len = strlen(s);

        strcpy(up, s);
        strcpy(down, s);

        /* т单 N 程Ч计 */
        for(i = 0; i < len; i++){
            if((up[i] - '0') % 2 == 0){
                up[i]++;
                for(j = i + 1; j < len; j++)
                    up[j] = '1';
                break;
            }
        }
        up[len] = '\0';

        /* т单 N 程Ч计 */
        for(i = 0; i < len; i++){
            if((down[i] - '0') % 2 == 0){
                if(down[i] != '0'){
                    down[i]--;
                    for(j = i + 1; j < len; j++)
                        down[j] = '9';
                }else{
                    for(j = i - 1; j >= 0; j--){
                        if(down[j] > '1'){
                            down[j] -= 2;
                            for(int k = j + 1; k < len; k++)
                                down[k] = '9';
                            break;
                        }
                    }

                    if(j < 0){
                        if(len == 1){
                            down[0] = '0';
                            down[1] = '\0';
                        }else{
                            for(j = 0; j < len - 1; j++)
                                down[j] = '9';
                            down[len - 1] = '\0';
                        }
                    }
                }
                break;
            }
        }

        a = atoll(up);
        b = atoll(down);

        if(a - n < n - b)
            printf("%lld\n", a - n);
        else
            printf("%lld\n", n - b);
    }

    return 0;
}
