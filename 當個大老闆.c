#include <stdio.h>

int main(void)
{
    int N, D;
    int S, W;
    int salary = 0, speed = 0;
    int day, price;
    int income, profit;
    int max = -1, ans = 0;

    scanf("%d %d", &N, &D);

    for(int i = 1; i <= N; i++){
        scanf("%d %d", &S, &W);

        salary += S;
        speed += W;

        day = (D + speed - 1) / speed;

        if(day == 1)
            price = 50;
        else if(day == 2)
            price = 40;
        else if(day == 3)
            price = 30;
        else if(day == 4)
            price = 20;
        else
            price = 10;

        income = D * price;
        profit = income - salary;

        if(profit > max){
            max = profit;
            ans = i;
        }
    }

    printf("%d %d\n", ans, max);

    return 0;
}
