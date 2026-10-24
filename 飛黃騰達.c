#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

Point p[200005];
int tail[200005];

int cmp(const void *a, const void *b)
{
    Point u = *(Point *)a;
    Point v = *(Point *)b;

    if(u.x != v.x)
        return (u.x > v.x) - (u.x < v.x);

    return (u.y > v.y) - (u.y < v.y);
}

int main(void)
{
    int N;
    int i, l, r, mid;
    int len = 0;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
        scanf("%d %d", &p[i].x, &p[i].y);

    qsort(p, N, sizeof(Point), cmp);

    for(i = 0; i < N; i++){
        l = 0;
        r = len;

        while(l < r){
            mid = (l + r) / 2;

            if(tail[mid] <= p[i].y)
                l = mid + 1;
            else
                r = mid;
        }

        tail[l] = p[i].y;

        if(l == len)
            len++;
    }

    printf("%d\n", len);

    return 0;
}
