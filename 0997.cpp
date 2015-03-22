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

#define re return 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz size()
#define len length()
#define sqr(x) ((x) * (x))
#define FOR(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define FOR2(i,n,m) for((i) = n; (i) <= (int)(m); (i)++)
#define FOR3(i,n,m) for((i) = n; (i) >= (int)(m); (i)--)
#define get(a) cin >> a
#define pri(a) cout << a
#define prin cout << endl
#define pris cout << " "
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

ll i, n;
pll x, y;
bool d[100][100];

vector < pair<ll, pll> > v;
//---------------------VAR---------------------

//---------------------FUNC--------------------
/*ll dp(ll a, ll b)
{
	if (a < 1 || a > n || b < 1 || b > n) re 1000000000;
	if (a == y.fi && b == y.se) re 0;
	if (d[a][b]) re d[a][b];

	ll tmp = 100000000;
	tmp = min(tmp, dp(a + 1, b + 2));
	tmp = min(tmp, dp(a + 2, b + 1));
	tmp = min(tmp, dp(a - 1, b + 2));
	tmp = min(tmp, dp(a + 2, b - 1));
	tmp = min(tmp, dp(a + 1, b - 2));
	tmp = min(tmp, dp(a - 2, b + 1));
	tmp = min(tmp, dp(a - 1, b - 2));
	tmp = min(tmp, dp(a - 2, b - 1));

	re d[a][b] = tmp + 1;
}*/
void add(ll a, ll b, ll c)
{
	if (a >= 1 && a <= n && b >= 1 && b <= n && !d[a][b])
	{
		d[a][b] = true;
		v.pb(mp(c, mp(a, b)));
	}
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> x.fi >> x.se >> y.fi >> y.se;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	v.pb(mp(0, x));

	for (ll i = 0; i < v.sz; i++)
	{
		if (v[i].second == y)
		{
			pri(v[i].fi);
			prin;
			re 0;
		}
		add(v[i].se.fi + 1, v[i].se.se + 2, v[i].fi + 1);
		add(v[i].se.fi + 2, v[i].se.se + 1, v[i].fi + 1);
		add(v[i].se.fi - 1, v[i].se.se - 2, v[i].fi + 1);
		add(v[i].se.fi - 2, v[i].se.se - 1, v[i].fi + 1);
		add(v[i].se.fi + 1, v[i].se.se - 2, v[i].fi + 1);
		add(v[i].se.fi - 2, v[i].se.se + 1, v[i].fi + 1);
		add(v[i].se.fi - 1, v[i].se.se + 2, v[i].fi + 1);
		add(v[i].se.fi + 2, v[i].se.se - 1, v[i].fi + 1);
	}

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}