//1936.cpp
//strongly connected
//by Lamzin Oleh
//Date: 10.04.2014

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define SIZE 1000

struct vertex{
    int used, color;
    int g[SIZE],gr[SIZE];
};

void dfs(int i);
void dfsr(int i, int color);
bool strongly_connected_count();

vector <int> lst;
vector <vertex> v;
int n,m,color = 0, weight, a;
int l,r=-1;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    {
        scanf("%d", &a);
        v[i].g[j] = a;
        v[j].gr[i] = a;
        r = max(r,a);
    }

    while(l < r){
        static bool res;
        weight = (l+r)/2;
        //printf("l = %d, r = %d, w = %d\n", l,r,weight);

        res = strongly_connected_count();
        if (res){
            r = weight;
        }
        else l = weight+1;
    }

    printf("%d\n", r);
}

bool strongly_connected_count(){
  int color = 0;
  for (int i = 0; i<n; i++) v[i].used = 0;

  for (int i = 0; i<n; i++)
      if (!v[i].used) dfs(i);

  for (int i = lst.size()-1; i>=0; i--)
      if (v[lst[i]].used != 2)
          dfsr(lst[i], color++);

  return color == 1;
}

void dfs(int i){
    v[i].used = 1;
    for (int ii = 0; ii < n; ii++){
        if (ii != i && !v[ii].used && v[i].g[ii] <= weight) dfs(ii);
    }

    lst.push_back(i);
}

void dfsr(int i, int color){
    v[i].used = 2;
    v[i].color = color;
    for (int ii = 0; ii < n; ii++){
        if (ii != i && v[ii].used != 2 && v[i].gr[ii] <= weight) dfsr(ii, color);
    }
}
