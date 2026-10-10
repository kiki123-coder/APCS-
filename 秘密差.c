#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char x[1000];
    int a = 0, b = 0;
    int pos = 1;

    scanf("%s", x);

    for(int i = 0; x[i] != '\0'; i++){
        int num = x[i] - '0';

        if(pos % 2 == 1)
            a += num;
        else
            b += num;

        pos++;
    }

    printf("%d\n", abs(a - b));

    return 0;
}
