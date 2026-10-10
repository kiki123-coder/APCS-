#include <stdio.h>

int main(void)
{
    int n, round = 0;
    int selfnumber[50000];
    int friendnumber[50000];
    int visited[50000] = {0};

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &friendnumber[i]);
        selfnumber[i] = i;
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){

            round++;

            int now = i;

            while(visited[now] == 0){
                visited[now] = 1;
                now = friendnumber[now];
            }
        }
    }

    printf("%d\n", round);

    return 0;
}
