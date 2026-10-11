#include <stdio.h>
#include <stdlib.h>

unsigned long long cp[500000];

int cmp(const void *a, const void *b)
{
    unsigned long long x = *(unsigned long long *)a;
    unsigned long long y = *(unsigned long long *)b;

    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}

int main(void)
{
    int m, n;
    char str[1001];

    scanf("%d %d", &m, &n);

    for(int i = 0; i < n; i++){
        scanf("%1000s", str);

        cp[i] = 0;

        for(int j = 0; str[j] != '\0'; j++){
            int k;

            if(str[j] >= 'A' && str[j] <= 'Z'){
                k = str[j] - 'A';
            }
            else{
                k = str[j] - 'a' + 26;
            }

            if(k < m){
                cp[i] |= 1ULL << k;
            }
        }
    }

    qsort(cp, n, sizeof(unsigned long long), cmp);

    unsigned long long all = (1ULL << m) - 1;
    long long ans = 0;

    int i = 0;

    while(i < n){
        int j = i;

        while(j < n && cp[j] == cp[i]){
            j++;
        }

        unsigned long long need = all ^ cp[i];

        if(cp[i] < need){
            int left = 0, right = n - 1;

            while(left <= right){
                int mid = (left + right) / 2;

                if(cp[mid] < need){
                    left = mid + 1;
                }
                else if(cp[mid] > need){
                    right = mid - 1;
                }
                else{
                    int l = mid, r = mid;

                    while(l > 0 && cp[l - 1] == need) l--;
                    while(r + 1 < n && cp[r + 1] == need) r++;

                    ans += (long long)(j - i) * (r - l + 1);
                    break;
                }
            }
        }

        i = j;
    }

    printf("%lld\n", ans);

    return 0;
}
