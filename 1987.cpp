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


//---------------------VAR---------------------

ll n, tmp, a, b;
string s;

//---------------------VAR---------------------

//---------------------FUNC--------------------


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
   //cout << "n = " << n << endl;
   
   for (int j = 0; j<n; j++)
   {
       
       cin >> tmp;
       cin >> s;
       // cout << "tmp = " << tmp << endl;
       // cout << "s = " << s << endl;

       cout << tmp << " ";
       
       a = -1;
       for (ll i = s.length()-1; i>=0; i--)
            if (s[i] < s[i+1])
            {
                a = i;
                i = -1;
            }
       
       if (a == -1) cout << "BIGGEST" << endl;
       else
       {
           b = a + 1;
           for (ll i = a+2; i<s.length(); i++) 
           {
               if (s[i] < s[b] && s[i] > s[a])
                   b = i;
           }
           
           swap(s[a], s[b]);
           
           //sort(s[a + 1], s[s.length()-1]);
           //sort(s.begin() + a + 1, s.begin() + s.length() - 1);
           
           for (int x = a+1; x < s.length()-1; x++)
               for (int y = x + 1; y < s.length(); y++)
                   if (s[x] > s[y]) swap(s[x], s[y]);
               
           
           cout << s << endl;
       }
   }
   
//--------------------MAIN---------------------

#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif
}