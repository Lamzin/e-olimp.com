#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>

#define DEBUG
#undef DEBUG
#define FILE
//#undef FILE

#define re return 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define sqr(x) ((x) * (x))
#define FOR(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define FOR2(i,n,m) for((i) = n; (i) <= (int)(m); (i)++)
#define FOR3(i,n,m) for((i) = n; (i) >= (int)(m); (i)--)
#define get(a) cin >> a
#define pri(a) cout << a
#define prin cout << endl
#define pris cout << " "
#define SORT(x) sort(x.begin(), x.end())

using namespace std;

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef double f64;

//---------------------VAR---------------------

vector < pair <ll, ll> > vect;
ll n, m, l, r, x;

//---------------------VAR---------------------

//---------------------FUNC--------------------

ll binary_find(ll left, ll right)
{
    if (left == right) re left;
    
    if (vect[(left+right)/2].ff > x) re binary_find(left, (left+right)/2);
    else re binary_find((left+right)/2, right);
}

ll check()
{
    if (x < vect[0].ff || x > vect[n-1].ff) re 0;
    
    ll index = binary_find(0, n-1);
    
    for (ll j = index; j<n; j++)
    {
        if (vect[j].ff > x) re 0;
        else if (j >= l && j <= r) re 1;
    }

    re 0;
}

//---------------------FUNC--------------------
int main()
{
//---------------------IN----------------------

//---------------------IN----------------------

#ifdef DEBUG
   double timeStart = clock();
#endif

//--------------------MAIN---------------------

    cin >> n;
    vect.reserve(n);
    for (ll i = 0; i<n; i++) 
    {
        cin >> vect[i].ff;
        vect[i].ss = i + 1;
    }
   
    sort(vect.begin(), vect.begin()+n);
   
    cin >> m;
    
    for (ll ijk = 0; ijk<m; ijk++) 
    {
        cin >> l >> r >> x;
        //cout << l << " " << r << " " << x << endl;
        
        cout << check();
    }   
    
    cout << endl;
   
//--------------------MAIN---------------------

#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif
}