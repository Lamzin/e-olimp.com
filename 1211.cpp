#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define re return

ll ans = 0,n,p,q;

map <ll, ll> my_map;

ll f(ll x)
{
    if (x == 0) re 1;
    if (my_map[x]) re my_map[x];
    re my_map[x] = f(x/p) + f(x/q);
}

int main()
{
    cin >> n >> p >> q;
    cout << f(n) << endl;
}