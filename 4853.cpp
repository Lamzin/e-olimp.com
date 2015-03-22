#include <iostream>
#include <vector>

using namespace std;

int a,b,n,m,i,u,v,to;
vector <pair<int, pair<int, int > > > vect;
vector <vector <int> > g;
vector <int> used;

int main(){
    cin >> n >> m >> a >> b;
    g.resize(n+1);
    used.resize(n+1);
    
    for (int ii = 0; ii < m; ii++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    
    vect.push_back(make_pair(b, make_pair(-1, 0)));
    used[b] = true;
    i = 0;
    
    while(i<vect.size()){
        if (vect[i].first == a){
            break;
        }
        for (int ii = 0; ii < g[vect[i].first].size(); ii++){
            to = g[vect[i].first][ii];
            if (!used[to]){
                vect.push_back(make_pair(to, make_pair(i, vect[i].second.second+1)));
                used[to] = true;
            }
        }
        i++;
    }
    
    if (i == vect.size()) cout << "-1\n";
    else
    {
        cout << vect[i].second.second << endl;
        while(vect[i].second.first != -1){
            cout << vect[i].first << " ";
            i = vect[i].second.first;
        }
        cout << vect[0].first;
        cout << endl;
    }
}