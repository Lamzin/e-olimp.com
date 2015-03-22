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


//---------------------VAR---------------------

ull t, n, k, gcd_tmp, C;

//---------------------VAR---------------------

//---------------------FUNC--------------------

ull gcd(ull a, ull b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    re a;
}

//---------------------FUNC--------------------
int main()
{
//---------------------IN----------------------

    cin >> t;
    
//---------------------IN----------------------

#ifdef DEBUG
   double timeStart = clock();
#endif

//--------------------MAIN---------------------

   for (ll i = 0; i<t; i++)
   {
       cin >> n >> k;
       
       if (k > n-k) k = n-k;
       
       C = 1;
       if (n > 0)
       for (ull d = 0; d<k; d++)
       {
           gcd_tmp = gcd(C, d+1);
           //C = C * (n-d) / (d+1);
           C = (C/gcd_tmp)*((n-d)/((d+1)/gcd_tmp));
       }
           
       cout << C << endl;
   }
   
//--------------------MAIN---------------------

#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif
}