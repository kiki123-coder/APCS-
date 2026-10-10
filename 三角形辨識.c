#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a > c){
        int temp = a;
        a = c;
        c = temp;
    }
    if(b > c){
        int temp = b;
        b = c;
        c = temp;
        if (a > c){
            temp = a;
            a = c;
            c = temp;
        }
    }
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }

    if(a + b <= c){
        printf("%d %d %d\nNo", a, b, c);
    }
    else if((a * a) + (b * b) < (c * c)){
        printf("%d %d %d\nObtuse", a, b, c);
    }
    else if((a * a) + (b * b) == (c * c)){
        printf("%d %d %d\nRight", a, b, c);
    }
    else if((a * a) + (b * b) > (c * c)){
        printf("%d %d %d\nAcute", a, b, c);
    }
    return 0;
}
