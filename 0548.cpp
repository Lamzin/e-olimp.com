//0548.cpp
//Lamzin Oleh

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FILE_IO
//#undef FILE_IO

#ifdef FILE_IO
#include <fstream>
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#define cin in
#define cout out
#endif

vector <vector<int> > g;
vector <pair<int, int> > edge;
int n,a,b;
int ansd = 10000, ansa, ansb, ansv, ansu;

int most_remote(int v, int u){
    vector <pair<int,int> > que;
    que.push_back(make_pair(v, u));

    for (int i = 0; i < que.size(); i++){
        v = que[i].first;
        u = que[i].second;
        for (int j = 0; j<g[v].size(); j++){
            if (g[v][j] != u) que.push_back(make_pair(g[v][j], v));
        }
    }

    return que[que.size()-1].first;
}

int centre(int v, int notv, int &len){
    int u;
    vector <pair<int,int> > que;
    que.push_back(make_pair(v, -1));

    for (int i = 0; i < que.size(); i++){
        v = que[i].first;
        u = (que[i].second != -1) ? que[que[i].second].first : -1;
        for (int j = 0; j<g[v].size(); j++){
            if (g[v][j] != u && g[v][j] != notv)
                que.push_back(make_pair(g[v][j], i));
        }
    }

    int i = que[que.size()-1].second, d = 0;
    while(i!=-1){
        d++;
        i = que[i].second;
    }

    len = d;
    d = d/2 - 1;
    i = que[que.size()-1].second;
    while(d-- && i != -1){
      i = que[i].second;
    }

    return (i!=-1) ? que[i].first : que[0].first;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    g.resize(n);
    edge.resize(n-1);

    for (int i = 0; i<n-1; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = make_pair(a,b);
    }

    for (int i = 0; i<n-1; i++){
        int v,u,lenv,lenu;
        v = most_remote(edge[i].first, edge[i].second);
        u = most_remote(edge[i].second, edge[i].first);

        v = centre(v, edge[i].second, lenv);
        u = centre(u, edge[i].first, lenu);

        if (max(max(lenv, lenu), (lenv+1)/2 + (lenu+1)/2 + 1) < ansd){
            ansd = max(max(lenv, lenu), (lenv+1)/2 + (lenu+1)/2 + 1);
            ansa = edge[i].first;
            ansb = edge[i].second;
            ansu = u;
            ansv = v;
        }

        /*cout << "a = " << edge[i].first << endl;
        cout << "b = " << edge[i].second << endl;
        cout << "v = " << v << endl;
        cout << "u = " << u << endl;
        cout << "lenv = " << lenv << endl;
        cout << "lenu = " << lenu << endl << endl;*/
    }


    //cout << "_____ANS_____\n";
    cout << ansd << endl;
    cout << ansa+1 << " " << ansb+1 << endl;
    cout << ansu+1 << " " << ansv+1 << endl;
}
