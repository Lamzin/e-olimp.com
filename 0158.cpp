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

ll n, tmp, i;
string d[100000];
bool db[100000];

//---------------------VAR---------------------

//---------------------FUNC--------------------
string SUM(string a, string b)
{
	for (int j = 0; j < a.ln / 2; j++) swap(a[j], a[a.ln - j - 1]);
	for (int j = 0; j < b.ln / 2; j++) swap(b[j], b[b.ln - j - 1]);

	if (a.ln < b.ln) swap(a,b);

	ll j, ost = 0;
	
	for (j = 0; j < b.ln; j++)
	{
		ost += a[j] + b[j] - 96;
		a[j] = ost % 10 + 48;
		ost /= 10;
	}

	while (ost)
	{
		if (j == a.ln) a += ost + 48, ost = 0;
		else
		{
			ost += a[j] - 48;
			a[j] = ost % 10 + 48;
			ost /= 10;
			j++;
		}
	}

	for (int j = 0; j < a.ln / 2; j++) swap(a[j], a[a.ln - j - 1]);

	re a;
}
//---------------------FUNC--------------------
string dp(ll fibo)
{
	if (db[fibo]) re d[fibo];
	
	db[fibo] = true;

	re d[fibo] = SUM(SUM(dp(fibo - 1), dp(fibo - 2)), SUM(dp(fibo - 3), dp(fibo - 4)));
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
	d[0] = d[1] = d[2] = d[3] = d[4] = "1";
	db[0] = db[1] = db[2] = db[3] = db[4] = true;

	get(n);
	FOR(i, n)
	{
		get(tmp);
		pri(dp(tmp));
		prin;
	}

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}