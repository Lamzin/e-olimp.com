#include <iostream>
#include <vector>

using namespace std;

#include <fstream>
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);


#define SIZE 1000
#define SSIIZZEE 1000001

int test, n, m, a, b, i, j, len, mmin = 1000001, mmax = -1;
int g[SIZE][SIZE], used[SIZE];
int have[SSIIZZEE];
bool result;

void dfs(int v, int color)
{
    if (!result) return;
    used[v] = color;
    for (int ii = 0; ii < n; ii++)
    {
        if (v != ii && g[v][ii] > len)
        {
            if (used[ii] == color) result = false;
            if (used[ii] == 0) dfs(ii, 3-color);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;

    for (i = 0; i<n-1; i++)
    {
        for (j = i+1; j<n; j++)
        {
            cin >> a;
            have[a] = 1;
            mmin = min(mmin,a);
            mmax = max(mmax,a);
            g[i][j] = g[j][i] = a;
        }
    }

    if (n == 2) 
    {
        cout << "0\n";
    }
    else
    {
        while(mmin != mmax)
        {
            result = true;
            for (i = 0; i<n; i++) used[i] = 0;
            
            len = (mmin + mmax) / 2;
            
            for (i = 0; i<n; i++)
                if (!used[i]) dfs(i, 1);
            
            (result) ? mmax = len : mmin = len+1;
        }
        
        while(!have[mmax]) mmax--;
        cout << mmax << endl;
    }
    
    return 0;
}