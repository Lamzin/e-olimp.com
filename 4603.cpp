#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <fstream>
//#define cin in
//#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);


#define SIZE 1000
#define SSIIZZEE 1000001

int n,m,a,b,ans = 0;
vector <vector <int> > g;
vector <int> used;

void dfs(int v)
{
    used[v] = 1;
    vector<int> tmp;
    
    for (int ii = 0; ii < g[v].size(); ii++)
    {
        tmp.push_back(g[v][ii]);
        if (!used[g[v][ii]])
        {
            dfs(g[v][ii]);
            for (int jj = 0; jj < g[g[v][ii]].size(); jj++) 
                tmp.push_back(g[g[v][ii]][jj]);
        }
    }
    sort(tmp.begin(), tmp.end());
    g[v].clear();
    if (tmp.size())
    {
        g[v].push_back(tmp[0]);
        for (int i = 1; i<tmp.size(); i++)
            if (tmp[i] != tmp[i-1]) g[v].push_back(tmp[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    g.resize(n);
    used.resize(n);

    for (int i = 0; i<m; i++)
    {
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }
    
    for (int i = 0; i<n; i++)
        if (!used[i]) dfs(i);
    
    //cout << endl;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<g[i].size(); j++)
        {
            ans+= g[i][j] != i; 
          //  cout << g[i][j]+1 <<  " ";
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}