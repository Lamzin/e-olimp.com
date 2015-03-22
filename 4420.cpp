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
#undef FILE

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

f64 p[4], val[3];

//---------------------VAR---------------------

//---------------------FUNC--------------------

f64 value(f64 x)
{
    re p[0]*x*x*x + p[1]*x*x + p[2]*x + p[3];
}

f64 binary_find(f64 l, f64 r)
{
    if (abs(l-r) < 0.0000001) re l;
    
    val [0] = value(l);
    val [1] = value((l+r)/2);
    val [2] = value(r);

    if (val[0] == 0) re l;
    if (val[1] == 0) re (l+r)/2;
    if (val[2] == 0) re r;

    
    if ((val[0] > 0 && val[1] < 0) || (val[0] < 0 && val[1] > 0) ) re binary_find(l, (l+r)/2);
    else re binary_find((l+r)/2, r);
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

   for (ll i = 0; i < 4 ; i++) cin >> p[i];
   
   cout.precision(6);
   
   cout << fixed << binary_find(-10000.f, 10000.f) << endl;
   
//--------------------MAIN---------------------

#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif
}