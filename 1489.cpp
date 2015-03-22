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

ll n, m, d[100][100], data[100][100], i, j;

//---------------------VAR---------------------

//---------------------FUNC--------------------
bool dp(ll ax, ll ay, ll bx, ll by)
{
	if ((bx - ax == 2 && by - ay == 1) || (bx - ax == 1 && by - ay == 2)) re true;

	bool res = false, tmp;

	for (int t = ax; t < bx; t++)
	{
		tmp = true;
		for (int tt = ay; tt <= by; tt++)
		if (data[t][tt] == data[t + 1][tt])
		{
			tmp = false;
			break;
		}
		if (tmp) res |= (dp(ax, ay, t, by) & dp(t + 1, ay, bx, by));
	}
	for (int tt = ay; tt < by; tt++)
	{
		tmp = true;
		for (int t = ax; t <= bx; t++)
		if (data[t][tt] == data[t][tt + 1])
		{
			tmp = false;
			break;
		}
		if (tmp) res |= (dp(ax, ay, bx, tt) & dp(ax, tt + 1, bx, by));
	}
	
	re res;
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	get(n);
	get(m);

	FOR(i, n) FOR(j, m) get(data[i][j]);

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	if (dp(1, 1, n, m)) pri("Yes");
	else pri("No");

	prin;
	
	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}