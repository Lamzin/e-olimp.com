//0946 - Lamzin Oleh
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

ll ans = 0;
ll vect[4][2];

ll S(ll a, ll b)
{
    return (vect[a][0] - vect[b][0]) * (vect[a][1] + vect[b][1]);
}

int main()
{
    for (int i = 0; i<4; i++) cin >> vect[i][0] >> vect[i][1];
    
    for (int i = 1; i<4; i++) ans += S(i-1, i);
    ans += S(3, 0);
    
    if (ans < 0) ans *= -1;
    cout << ans / 2 + (ans % 2)<< endl;
}