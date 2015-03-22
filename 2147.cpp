//2147 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
#define cin in
#define cout out

ll n;
double ans = 0;
vector < pair<double, double> >  vect;

double S(ll a, ll b)
{
    return (vect[a].first - vect[b].first) * (vect[a].second + vect[b].second)/2;
}

int main()
{
    cin >> n;
    
    vect.reserve(n);
    
    for (int i = 0; i<n; i++) cin >> vect[i].first >> vect[i].second;
    
    for (int i = 1; i<n; i++) ans += S(i-1, i);
    ans += S(n-1, 0);
    
    if (ans < 0) ans *= -1;
    cout.precision(1);
    cout << fixed << ans << endl;
}