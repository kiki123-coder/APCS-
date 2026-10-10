#include <stdio.h>
#include <string.h>

int main(void)
{
    char hit[9][6][3];
    int n[9];
    int b;

    for(int i = 0; i < 9; i++){
        scanf("%d", &n[i]);

        for(int j = 0; j < n[i]; j++){
            scanf("%s", hit[i][j]);
        }
    }

    scanf("%d", &b);

    int base[4] = {0};  // 0本壘、1一壘、2二壘、3三壘
    int out = 0;
    int score = 0;
    int player = 0;
    int turn[9] = {0};

    while(out < b){
        char *result = hit[player][turn[player]];
        turn[player]++;

        if(strcmp(result, "FO") == 0 ||
           strcmp(result, "GO") == 0 ||
           strcmp(result, "SO") == 0){

            out++;

            if(out % 3 == 0){
                for(int i = 1; i <= 3; i++){
                    base[i] = 0;
                }
            }
        }
        else{
            int k = 0;

            if(strcmp(result, "1B") == 0) k = 1;
            else if(strcmp(result, "2B") == 0) k = 2;
            else if(strcmp(result, "3B") == 0) k = 3;
            else if(strcmp(result, "HR") == 0) k = 4;

            for(int i = 3; i >= 1; i--){
                if(base[i]){
                    if(i + k >= 4){
                        score++;
                    }
                    else{
                        base[i + k] = 1;
                    }

                    base[i] = 0;
                }
            }

            if(k == 4){
                score++;
            }
            else{
                base[k] = 1;
            }
        }

        player = (player + 1) % 9;
    }

    printf("%d\n", score);

    return 0;
}
