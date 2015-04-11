//1947.cpp
//strongly connected
//by Lamzin Oleh
//Date: 10.04.2014

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct vertex{
    int used, color;
    vector<int> g,gr;
};

void dfs(int i);
void dfsr(int i, int color);

vector <int> lst;
vector <vertex> v;
int n,m,color = 0;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    v.resize(n);

    while(m--){
        static int a,b;
        scanf("%d%d", &a, &b);
        v[a-1].g.push_back(b-1);
        v[b-1].gr.push_back(a-1);
    }

    for (int i = 0; i<n; i++)
        if (!v[i].used) dfs(i);

    for (int i = lst.size()-1; i>=0; i--){
        if (v[lst[i]].used != 2)
            dfsr(lst[i], color++);
    }


    set <int> gg[10000];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<v[i].g.size(); j++)
            if (v[i].color != v[v[i].g[j]].color){
                gg[v[i].color].insert(v[v[i].g[j]].color);
            }

    int ans = 0;
    for (int i = 0; i<10000; i++)
        ans += gg[i].size();

    printf("%d\n", ans);
}

void dfs(int i){
    v[i].used = 1;
    for (int ii = 0; ii < v[i].g.size(); ii++){
        int to = v[i].g[ii];
        if (!v[to].used) dfs(to);
    }

    lst.push_back(i);
}

void dfsr(int i, int color){
    v[i].used = 2;
    v[i].color = color;
    for (int ii = 0; ii < v[i].gr.size(); ii++){
        int to = v[i].gr[ii];
        if (v[to].used != 2) dfsr(to, color);
    }
}