//0000 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>
#include <map>
#include <stdlib.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
//#define cin in
//#define cout out
#define re return

map <ll, ll> dp_map;
ll n;

ll dp(ll x)
{
    if (dp_map[x]) re dp_map[x];
    else
    {         
        ll ans = dp(1) + dp(x-1);
        for (ll i = 1; 2*i < x; i++) ans = min(ans, dp(i)+dp(x-i));
        re dp_map[x] = ans;
    }
}

int main()
{
    cin >> n;
    
    for (ll i = 1; i*i*i <= n; i++) dp_map[i*i*i] = 1;

    cout << dp(n) << endl;
}