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
#include <bitset>

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


//---------------------VAR---------------------

ll n, tmp;
vector <ll> vect;
bitset <1000000000> st;
//bool st[1000000];
int fl = false;

//---------------------VAR---------------------

//---------------------FUNC--------------------


//---------------------FUNC--------------------
int main()
{
#ifdef DEBUG
   double timeStart = clock();
#endif

//--------------------MAIN---------------------

   cin >> n;
   for (ll i = 0; i<n; i++)
   {
       cin >> tmp;
       vect.push_back(tmp);
   }
   
   sort(vect.begin(), vect.end());
   
   fl = 0;
   for (ll j = 0; j<n; j++) 
           {
               while (vect[j] % 2 == 0)
               {
                   fl++;
                   vect[j]/=2;
               }
                    
               if (fl > 1) 
               {
                   cout << 2 << endl;
                   return 0;
               }
           }
   
   ll nsqrt = sqrt(vect[n-1]) + 1;
   for (ll i = 3; i<=nsqrt; i+=2)
   {
       if (!st[i])
       {
           fl = 0;
           
           for (ll j = 0; j<n; j++) 
           {
               while (vect[j] % i == 0)
               {
                   fl++;
                   vect[j]/=i;
               }

               if (fl > 1) 
               {
                   cout << i << endl;
                   return 0;
               }
               
               nsqrt = sqrt(vect[n-1]) + 1;
           }
           
           for (ll j = i; j<=nsqrt; j+=2*i) st[j] = 1;
       }
   }
   
   cout << "Beautiful" << endl;
   
//--------------------MAIN---------------------

#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif
}