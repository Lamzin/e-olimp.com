#include <string.h>
#include <stdio.h>
#include <algorithm>

#define SIZE 100
#define INF_INT32 536870912

int n, finish, start, tmp;
int w[SIZE][SIZE], d[SIZE], used[SIZE];

void prrr(){
    for (int i = 0; i<n; i++)
       printf("%d ", d[i]);
    printf("\n");
}

void In(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &start, &finish);
    start--; finish--;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++){
            scanf("%d", &tmp);
            if (tmp!=-1 && i!=j) w[i][j] = tmp;
            else w[i][j] = INF_INT32;
        }
}

void Init(){
    //memset(w, INF_INT32, SIZE*SIZE);
    //memset(d, INF_INT32, SIZE);
    //memset(used, 0, SIZE);
    //used[start] = 1;
    for (int i = 0; i<SIZE; i++) d[i] = w[start][i];
    d[start] = 0;
}

int FindMin(){
    int Min = INF_INT32, v = -1;
    for (int i = 0; i<n; i++)
        if (!used[i] && d[i] < Min){
            Min = d[i];
            v = i; 
        }

    return v;
}

void Relax(int v, int to){
    d[to] = std::min(d[to], d[v] + w[v][to]);
}

int main(){
    In();
    Init();

    for (int cnt = 0; cnt < n; cnt++){
        int v = FindMin();
        if (v == -1){
            d[finish] = -1;
            break;
        }
        if (v == finish) break;

        for(int to = 0; to<n; to++) 
            if (!used[to]) Relax(v, to);
        used[v] = 1;
   }
   printf("%d\n", d[finish]);
}
