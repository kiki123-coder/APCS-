#include <stdio.h>
#include <string.h>

int main(void)
{
    int N, i, j, count, min;
    char s[1001][1001];
    int seen[26];

    scanf("%d", &N);

    for(i = 0; i < N; i++)
        scanf("%s", s[i]);

    min = 27;
    int best = 0;

    for(i = 0; i < N; i++){
        for(j = 0; j < 26; j++)
            seen[j] = 0;

        count = 0;

        for(j = 0; s[i][j] != '\0'; j++){
            int k = s[i][j] - 'A';

            if(seen[k] == 0){
                seen[k] = 1;
                count++;
            }
        }

        if(count < min){
            min = count;
            best = i;
        }else if(count == min && strcmp(s[i], s[best]) < 0){
            best = i;
        }
    }

    printf("%s\n", s[best]);

    return 0;
}
