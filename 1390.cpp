#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SIZE 1000
#define FIRST 1000000

typedef vector <pair<int, int> > vii;
typedef long long ll;

int test, n, m, a, b, i, j;
vector <vector<int> > g;
vector <int> used;
bool result = false;

void dfs(int v, int prev)
{
    used[v] = prev;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (g[v][i] != prev && used[g[v][i]] > 0 && !result) 
        {
            result = true;
            break;
        }
        if (used[g[v][i]] == 0) dfs(g[v][i], v);
    }
    used[v] = -1;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;

    g.resize(n+1);
    used.resize(n+1);

    for(i = 0; i<m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i<=n; i++)
        if (used[i] == 0) dfs(i, FIRST);
    
    cout << ((result) ? "YES\n" : "NO\n");
    return 0;
}