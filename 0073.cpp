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

ll a[10], b[10], sumA, i, ans, index;
string A, B, C;

//---------------------VAR---------------------
//---------------------FUNC--------------------
bool check()
{
	ll j;
	FOR(j, 10) if (b[j] > a[j]) re false;

	re true;
}
//---------------------FUNC--------------------
string SUM(string a, string b)
{
	for (int j = 0; j < a.ln / 2; j++) swap(a[j], a[a.ln - j - 1]);
	for (int j = 0; j < b.ln / 2; j++) swap(b[j], b[b.ln - j - 1]);

	if (a.ln < b.ln) swap(a, b);

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
int main()
{
	//---------------------IN----------------------
	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------
	
	A = B = "1";
	ans = -1;
	index = 2;

	FOR(i, 10)
	{
		get(a[i]);
		sumA += a[i];
	}
	
	while (B.ln <= sumA)
	{
		FOR(i, 10) b[i] = 0;
		FOR(i, B.ln) b[B[i] - 48]++;

		if (check()) ans = index;

		index++;

		C = SUM(A,B);
		A = B;
		B = C;
	}

	pri(ans); 
	prin;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}