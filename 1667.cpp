//1667.cpp
//strongly connected
//by Lamzin Oleh
//Date: 10.04.2014

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex{
    int used, color;
    vector<int> g,gr;
};

void dfs(int i);
void dfsr(int i, int color);

vector <int> lst, toans, toin, toout, tocolor;
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

    toans.resize(color);
    tocolor.resize(color);
    toin.resize(color);
    toout.resize(color);

    //for (int i = 0; i<n; i++) printf("%d: %d\n", i, v[i].color);

    for (int i = 0; i<n; i++) tocolor[v[i].color] = i;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<v[i].g.size(); j++)
            if (v[i].color != v[v[i].g[j]].color){
                toans[v[v[i].g[j]].color] = toout[v[i].color] = toin[v[v[i].g[j]].color] = 1;
            }

    vector<int> ans;
    for(int i = 0; i<toans.size(); i++)
        if (toans[i] && toin[i] && !toout[i] || !toin[i] && !toout[i]) ans.push_back(tocolor[i]+1);

    if (!ans.size()) printf("1\n1\n");
    else
    {
        printf("%d\n%d", (int)ans.size(), ans[0]);
        for(int i = 1; i<ans.size(); i++)
        printf(" %d", ans[i]);
        printf("\n");
    }
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
