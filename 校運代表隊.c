#include <stdio.h>

int a[100], ans[5];
int usedSkill[20], classCnt[20];

int n, m, r, k;
long long t, cnt = 0;
int total;

int dfs(int start, int depth)
{
    int i, c, skill;

    if(depth == k){
        cnt++;

        if(cnt == t){
            for(i = 0; i < k; i++){
                if(i > 0)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
            return 1;
        }

        return 0;
    }

    for(i = start; i <= total - (k - depth); i++){
        skill = a[i];
        c = i / r;

        if(usedSkill[skill] == 1)
            continue;

        if(classCnt[c] == 2)
            continue;

        ans[depth] = i + 1;
        usedSkill[skill] = 1;
        classCnt[c]++;

        if(dfs(i + 1, depth + 1))
            return 1;

        usedSkill[skill] = 0;
        classCnt[c]--;
    }

    return 0;
}

int main(void)
{
    int i;

    scanf("%d %d %d %d %lld", &n, &m, &r, &k, &t);

    total = m * r;

    for(i = 0; i < total; i++)
        scanf("%d", &a[i]);

    dfs(0, 0);

    return 0;
}


