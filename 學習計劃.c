#include <stdio.h>

int main(void)
{
    int n;
    int num[101];
    int fatigue = 0;
    int score = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < n; i++){

        if(num[i] == 1){
            fatigue += 25;
            score += 10;
        }
        else if(num[i] == 2){
            fatigue += 10;
            score += 20;
        }
        else if(num[i] == 3){
            fatigue += 5;
            score += 15;
        }
        else if(num[i] == 4){
            fatigue += 4;
            score += 20;
        }
        else if(num[i] == 5){
            fatigue -= 10;
            score -= 15;

            if(fatigue < 0)
                fatigue = 0;
        }
        else if(num[i] == 6){
            fatigue -= 35;
            score = 0;

            if(fatigue < 0)
                fatigue = 0;
        }
        else if(num[i] == 7){
            fatigue = 0;
            score = score * 9 / 10;
        }

        if(fatigue > 100){
            fatigue = 0;
            score = 0;
        }
    }

    printf("%d\n", score);

    return 0;
}
