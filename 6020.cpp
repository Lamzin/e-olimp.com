#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SIZE 1000
#define MOD 2147483647

typedef vector <pair<int, int> > vii;
typedef long long ll;

string s;
vii *cur = new vii, *vect = new vii;
int g[SIZE][SIZE], n;
int i,j;

void check_push(int x, int y)
{
    if (x>=0 && x<n && y>=0 && y<n && g[x][y]>-1)
    {
        g[x][y] = -2;
        vect->push_back(make_pair(x,y));
    }
}

void bfs(int x, int y)
{
    cur->push_back(make_pair(x,y));
    g[x][y] = -2;
    
    while(cur->size())
    {
        //cerr << cur->size() << endl;
        
        for (int i = 0; i<cur->size(); i++)
        {
            x = cur->at(i).first;
            y = cur->at(i).second;
            check_push(x-1,y);
            check_push(x+1,y);
            check_push(x,y-1);
            check_push(x,y+1);
        }
        cur->clear();
        swap(cur, vect);
    }
}

int main()
{
    cin >> n;
    getline(cin, s);
    
    for(i = 0; i<n; i++) 
    {
        getline(cin, s);
        for (j = 0; j<n; j++) g[i][j] = (s[j] == '.') ? 0 : -1;
    }
    
    g[0][0] = i = 1;   
    while (i < n && g[i][0] == 0) g[i++][0] = 1;
    i = 1;
    while (i < n && g[0][i] == 0) g[0][i++] = 1;

    for(i = 1; i<n; i++)
        for(j = 1; j<n; j++)
            if (g[i][j] != -1)
            {
                if (g[i-1][j] != -1) g[i][j] = ((ll)g[i][j] + (ll)g[i-1][j]) % MOD;
                if (g[i][j-1] != -1) g[i][j] = ((ll)g[i][j] + (ll)g[i][j-1]) % MOD;
            }
    
    if (g[n-1][n-1])
    {
        cout << g[n-1][n-1] << endl;
        return 0;
    }
        
    bfs(0,0);
    cout << ((g[n-1][n-1] == -2) ? "THE GAME IS A LIE\n" : "INCONCEIVABLE\n");
    return 0;
}