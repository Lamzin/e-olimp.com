#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
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

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define REP(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define sc(a) cin >> a
#define pr_ cout << " "
#define pr(a) cout << a
#define pre(a) cout << a << endl
#define prE cout << endl
#define STR_COUP(s) REP(i,len(s)/2) swap(s[i], s[len(s)-i-1])
#define SORT(x) sort(x.begin(), x.end())

using namespace std;

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

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

ll n, m, k, i;
vll v;


//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> k >> n >> m;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (i = 1; i*i < n; i++)
	{
		if (n % i == 0)
		{
			if (m % (i + k) == 0) v.pb(i);
			if (m % (n / i + k) == 0) v.pb(n / i);
		}
	}

	if (i*i == n && m % (i + k) == 0) v.pb(i);

	SORT(v);

	REP(i,sz(v)) pre(v[i]);

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}