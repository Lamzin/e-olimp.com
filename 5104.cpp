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

ull n,m;
string dn[100][100];

//---------------------VAR---------------------

//---------------------FUNC--------------------

void swap(string &strtmp)
{
   int length = strtmp.length();

   char tmp;
   for (int i = 0; i < length / 2; i++)
   {
       tmp = strtmp[i];
       strtmp[i] = strtmp[length - i - 1];
       strtmp[length - i - 1] = tmp;
   }
}

string sum(string a, string b)
{
    string c;
    
    swap(a);
    swap(b);
    int lengthA = a.length(), lengthB = b.length(), length = (lengthA > lengthB) ? lengthA : lengthB, ost = 0;
    for (int i = 0; i < length; i++)
    {
        if (i < lengthA) ost += a[i] - 48;
        if (i < lengthB) ost += b[i] - 48;

        c += ((ost % 10) +48);
        ost /= 10;
    }
    if (ost) c += "1";

    swap(c);
    
    re c;
}


string d(ull a, ull b)
{
    if (dn[a][b] != "0") re dn[a][b];

    re dn[a][b] = sum(d(a-1,b), d(a,b-1));
}

//---------------------FUNC--------------------
int main()
{
//---------------------IN----------------------
    
    cin >> n >> m;

    ll i,j;
    FOR(i,100)
    FOR(j,100) dn[i][j] = "0";

    FOR(i,100) dn[1][i] = dn[i][1] = "1";

    
//---------------------IN----------------------

#ifdef DEBUG
   double timeStart = clock();
#endif

//--------------------MAIN---------------------

   cout << d(n,m) << endl; 

//--------------------MAIN---------------------

#ifdef DEBUG
   cout.precision(3);
   cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
   cin >> timeStart;
#endif
}