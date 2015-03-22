//1868 - Lamzin Oleh
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define ui unsigned int
#define ll long long
#define re return
#define ull unsigned ll

ll n, tmp, tmp_weight;
ull ans = 0, tmP;

ull vect[200000][2];

int main()
{
    cin >> n;
    
    vect[0][0] = vect[0][1] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp >> tmp_weight;
        if (tmp_weight)
        {
            ans += tmP = vect[tmp][1] + tmp_weight;
            vect[i][0] = tmp;
            vect[i][1] = tmP;
        }
        else
        {
            if (vect[tmp][1])
            {
            ans += tmP = vect[vect[tmp][0]][1];
            vect[i][0] = vect[vect[tmp][0]][0];
            vect[i][1] = tmP;
            }
            else
            {
                vect[i][0] = vect[vect[tmp][0]][0];
                vect[i][1] = 0;
            }
        }
    }
    cout << ans << endl;
}