#include <stdio.h>

int graph[100000][100];
int degree[100000];
int child[100000];

int queue[100000];
int dist[100000];

int main(void)
{
    int N;
    int a, b;

    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++){
        scanf("%d %d", &a, &b);

        graph[a][degree[a]++] = b;
        graph[b][degree[b]++] = a;

        child[b] = 1;
    }

    int root = 0;

    for(int i = 0; i < N; i++){
        if(child[i] == 0){
            root = i;
            break;
        }
    }

    // 第一次 BFS
    for(int i = 0; i < N; i++)
        dist[i] = -1;

    int front = 0, rear = 0;

    queue[rear++] = root;
    dist[root] = 0;

    int far = root;

    while(front < rear){
        int now = queue[front++];

        if(dist[now] > dist[far])
            far = now;

        for(int i = 0; i < degree[now]; i++){
            int next = graph[now][i];

            if(dist[next] == -1){
                dist[next] = dist[now] + 1;
                queue[rear++] = next;
            }
        }
    }

    // 第二次 BFS
    for(int i = 0; i < N; i++)
        dist[i] = -1;

    front = 0;
    rear = 0;

    queue[rear++] = far;
    dist[far] = 0;

    int answer = 0;

    while(front < rear){
        int now = queue[front++];

        if(dist[now] > answer)
            answer = dist[now];

        for(int i = 0; i < degree[now]; i++){
            int next = graph[now][i];

            if(dist[next] == -1){
                dist[next] = dist[now] + 1;
                queue[rear++] = next;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
