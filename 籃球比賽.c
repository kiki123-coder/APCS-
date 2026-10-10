#include <stdio.h>

int main(void)
{
    int a, b;
    int i, j, k, l;
    int suma, sumb;
    int win = 0, lose = 0;

    scanf("%d %d %d %d", &i, &j, &k, &l);
    suma = i + j + k + l;

    scanf("%d %d %d %d", &i, &j, &k, &l);
    sumb = i + j + k + l;

    printf("%d:%d\n", suma, sumb);

    if(suma > sumb){
        win++;
    }
    else{
        lose++;
    }

    scanf("%d %d %d %d", &i, &j, &k, &l);
    suma = i + j + k + l;

    scanf("%d %d %d %d", &i, &j, &k, &l);
    sumb = i + j + k + l;

    printf("%d:%d\n", suma, sumb);

    if(suma > sumb){
        win++;
    }
    else{
        lose++;
    }

    if(win > lose){
        printf("Win");
    }
    else if(win < lose){
        printf("Lose");
    }
    else{
        printf("Tie");
    }
    return 0;
}
