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

string s;
ll ans;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	sc(s);

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	int i;
	REP(i, len(s))
	{
		switch (s[i])
		{
		case '0': ans += 6; break;
		case '1': ans += 2; break;
		case '2': ans += 5; break;
		case '3': ans += 5; break;
		case '4': ans += 4; break;
		case '5': ans += 5; break;
		case '6': ans += 6; break;
		case '7': ans += 3; break;
		case '8': ans += 7; break;
		case '9': ans += 6; break;
		}
	}
	pre(ans);

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}