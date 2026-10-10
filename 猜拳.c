#include <stdio.h>

int main(void)
{
    int n, ascore = 0, bscore = 0;
    int a, b;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);

        if(a == b){
            if(a == 2){
                ascore -= 2;
                bscore -= 2;
            }
        }
        else if(a == 2 && b == 5){
            ascore += 2;
            bscore -= 1;
        }
        else if(a == 5 && b == 2){
            ascore -= 1;
            bscore += 2;
        }
        else if(a == 0 && b == 2){
            ascore += 1;
            bscore -= 2;
        }
        else if(a == 2 && b == 0){
            ascore -= 2;
            bscore += 1;
        }
        else if(a == 5 && b == 0){
            ascore += 1;
            bscore -= 1;
        }
        else if(a == 0 && b == 5){
            ascore -= 1;
            bscore += 1;
        }
    }

    printf("%d %d\n", ascore, bscore);

    return 0;
}
