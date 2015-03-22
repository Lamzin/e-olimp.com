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
//#undef DEBUG
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
//#define cin in
//#define cout out
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

ull n, ans;
map <ull, ull> m;



//---------------------VAR---------------------

//---------------------FUNC--------------------

ull f(ull p)
{
    if (m[p]) re m[p];
    
    ull param = p, res = p;
    
    for (ull j = 2; j*j<=p; j++) 
    {
        if (p % j == 0) res-=res/j;
        while (p % j == 0) p/=j;
    }
    
    if (p-1) res-=res/p;
    
    re m[param] = res;
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
   do
   {
       cin >> n;
       if (n)
       {
           //ans = 0;
           //for (ull i = 2; i<=n; i++) ans += f(i);
           //cout << 2*ans + 1<< endl;
           cout << m[n] << endl;
       }
   }
   while (n);
   
   /*for (ull n2 = 1; n2<=50000; n2++)
   {
        ans = 0;
        for (ull i = 2; i<=n2; i++) ans += f(i);
        out << 2*ans + 1 << ",";
        if (n2 % 1000 == 0) 
        {
            cout << n2;
#ifdef DEBUG
   cout.precision(3);
   cout << "; Time = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC << endl;
#endif
        }
        
   }
   while (n);
   
   */
   
   
//--------------------MAIN---------------------
/*
#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif*/
}
