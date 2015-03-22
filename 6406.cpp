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

ll n, i, j, ans;
pii tmpa, tmpb;
vector < pair<pii, pii> > rect;

//---------------------VAR---------------------

//---------------------FUNC--------------------
bool inside(pii a, pii b, pii c)
{
	re((a.ff <= c.ff && a.ss <= c.ss) && (c.ff <= b.ff && c.ss <= b.ss));
}
//---------------------FUNC--------------------
ll ch(pii a, pii b)
{
	if (a.ff == b.ff || a.ss == b.ss) re 0;

	bool ain, bin, cin, din;

	for (ll ind = 0; ind < rect.sz; ind++)
	{
		pii c = mp(a.ff, b.ss), d = mp(b.ff, a.ss);
		//---------------------------------------------------------------------------------
		ain = inside(rect[ind].ff, rect[ind].ss, a);
		bin = inside(rect[ind].ff, rect[ind].ss, b);
		cin = inside(rect[ind].ff, rect[ind].ss, c);
		din = inside(rect[ind].ff, rect[ind].ss, d);
		//---------------------------------------------------------------------------------
		if (ain && bin) re 0;
		//---------------------------------------------------------------------------------
		if (ain && cin && a.ff != rect[ind].ss.ff)
		{
			ch(mp(rect[ind].ss.ff, a.ss), b);
			re 0;
		}
		if (ain && din && a.ss != rect[ind].ss.ss)
		{
			ch(mp(a.ff, rect[ind].ss.ss), b);
			re 0;
		}
		if (bin && cin && b.ss != rect[ind].ff.ss)
		{
			ch(a, mp(b.ff, rect[ind].ff.ss));
			re 0;
		}
		if (bin && din && b.ff != rect[ind].ff.ff)
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			re 0;
		}
		//---------------------------------------------------------------------------------
		if (ain && a.ff != rect[ind].ss.ff && a.ss != rect[ind].ss.ss)
		{
			ch(mp(a.ff, rect[ind].ss.ss), mp(rect[ind].ss.ff, b.ss));
			ch(mp(rect[ind].ss.ff, a.ss), b);
			re 0;
		}
		if (bin && b.ff != rect[ind].ff.ff && b.ss != rect[ind].ff.ss)
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			ch(mp(rect[ind].ff.ff, a.ss), mp(b.ff, rect[ind].ff.ss));
			re 0;
		}
		if (cin && c.ff != rect[ind].ss.ff && c.ss != rect[ind].ff.ss)
		{
			ch(a, mp(rect[ind].ss.ff, rect[ind].ff.ss));
			ch(mp(rect[ind].ss.ff, a.ss), b);
			re 0;
		}
		if (din && d.ff != rect[ind].ff.ff && d.ss != rect[ind].ss.ss)
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			ch(mp(rect[ind].ff.ff, rect[ind].ss.ss), b);
			re 0;
		}
		//---------------------------------------------------------------------------------
		if (inside(a, b, rect[ind].ff) && inside(a, b, rect[ind].ss))
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			ch(mp(rect[ind].ff.ff, rect[ind].ss.ss), mp(rect[ind].ss.ff, b.ss));
			ch(mp(rect[ind].ff.ff, a.ss), mp(rect[ind].ss.ff, rect[ind].ff.ss));
			ch(mp(rect[ind].ss.ff, a.ss), b);
			re 0;
		}
		//---------------------------------------------------------------------------------
		if (a.ss >= rect[ind].ff.ss && b.ss <= rect[ind].ss.ss && a.ff < rect[ind].ff.ff && b.ff > rect[ind].ss.ff)
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			ch(mp(rect[ind].ss.ff, a.ss), b);
			re 0;
		}
		if (a.ss >= rect[ind].ff.ss && a.ss < rect[ind].ss.ss && a.ff < rect[ind].ff.ff && b.ff > rect[ind].ss.ff)
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			ch(mp(rect[ind].ss.ff, a.ss), b);
			ch(mp(rect[ind].ff.ff, rect[ind].ss.ss), mp(rect[ind].ss.ff, b.ss));
			re 0;
		}
		if (b.ss > rect[ind].ff.ss && b.ss <= rect[ind].ss.ss && a.ff < rect[ind].ff.ff && b.ff > rect[ind].ss.ff)
		{
			ch(a, mp(rect[ind].ff.ff, b.ss));
			ch(mp(rect[ind].ss.ff, a.ss), b);
			ch(mp(rect[ind].ff.ff, a.ss), mp(rect[ind].ss.ff, rect[ind].ff.ss));
			re 0;
		}
		//---------------------------------------------------------------------------------
		if (a.ff >= rect[ind].ff.ff && b.ff <= rect[ind].ss.ff && a.ss < rect[ind].ff.ss && b.ss > rect[ind].ss.ss)
		{
			ch(a, mp(b.ff, rect[ind].ff.ss));
			ch(mp(a.ff, rect[ind].ss.ss), b);
			re 0;
		}
		if (a.ff >= rect[ind].ff.ff && a.ff < rect[ind].ss.ff && a.ss < rect[ind].ff.ss && b.ss > rect[ind].ss.ss)
		{
			ch(a, mp(b.ff, rect[ind].ff.ss));
			ch(mp(a.ff, rect[ind].ss.ss), b);
			ch(mp(rect[ind].ss.ff, a.ss), mp(b.ff, rect[ind].ss.ss));
			re 0;
		}
		if (b.ff > rect[ind].ff.ff && b.ff <= rect[ind].ss.ff && a.ss < rect[ind].ff.ss && b.ss > rect[ind].ss.ss)
		{
			ch(a, mp(b.ff, rect[ind].ff.ss));
			ch(mp(a.ff, rect[ind].ss.ss), b);
			ch(mp(a.ff, rect[ind].ff.ss), mp(rect[ind].ff.ff, rect[ind].ss.ss));
			re 0;
		}
		//---------------------------------------------------------------------------------
	}

	rect.pb(mp(a, b));
	re 0;
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	ll test;
	get(test);

	for (ll te = 0; te < test; te++)
	{
		rect.clear();
		ans = 0;

		get(n);
		FOR(i, n)
		{
			cin >> tmpa.ff >> tmpa.ss >> tmpb.ff >> tmpb.ss;
			ch(mp(min(tmpa.ff, tmpb.ff), min(tmpa.ss, tmpb.ss)), mp(max(tmpa.ff, tmpb.ff), max(tmpa.ss, tmpb.ss)));
		}

		FOR(i, rect.sz) ans += (rect[i].ss.ff - rect[i].ff.ff)*(rect[i].ss.ss - rect[i].ff.ss);

		pri(ans);
		prin;
	}
	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------






	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}