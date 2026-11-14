#include <stdio.h>

int main(void)
{
    int n, x, y;
    int egg = 0, flour = 0;
    int A, M, B, N;
    /*
    n	并翴计秖
    x	–并翴惠璶蔓矹
    y	–并翴惠璶难
    egg	┮Τ并翴惠璶蔓矹羆计
    flour	┮Τ并翴惠璶难羆秖
    A	–舶蔓矹计秖
    M	–舶蔓矹基
    B	–砋难秖
    N	–砋难基
    */
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);

        egg += x;
        flour += y;
    }

    scanf("%d %d %d %d", &A, &M, &B, &N);

    int box = (egg + A - 1) / A;
    int bag = (flour + B - 1) / B;

    printf("%d\n", box * M + bag * N);

    return 0;
}
