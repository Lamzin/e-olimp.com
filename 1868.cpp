//1868 - Lamzin Oleh
#include <iostream>
#include <map>

using namespace std;

#define ui unsigned int
#define ll long long
#define re return

ll n;

map <ll, ui> my_map;

ui f(ll x)
{
    if (x <= 2) re 1;
    if (my_map[x]) re my_map[x];
    if (x % 2) re my_map[x] = f(6 * x / 7) + f(2 * x / 3);
    re my_map[x] = f(x - 1) + f(x - 3);
}

int main()
{
    cin >> n;
    cout << f(n) << endl;
}