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

vector < pair<ll, ull> > vect;

int main()
{
    cin >> n;
    
    vect.push_back(make_pair(0, 0));
    
    for (int i = 0; i<n; i++)
    {
        cin >> tmp >> tmp_weight;
        if (tmp_weight)
        {
            ans += tmP = vect[tmp].second + tmp_weight;
            vect.push_back(make_pair(tmp, tmP));
        }
        else
        {
            if (vect[tmp].second)
            {
            ans += tmP = vect[vect[tmp].first].second;
            vect.push_back(make_pair(vect[vect[tmp].first].first, tmP));
            }
            else
                vect.push_back(make_pair(vect[vect[tmp].first].first, 0));
        }
    }
    cout << ans << endl;
}