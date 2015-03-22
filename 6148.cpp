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

int n, m, i, j, ans = 0;
bool mas[1000][1000];
string s;

//---------------------VAR---------------------

//---------------------FUNC--------------------
inline bool check_1_lvl(int x, int y);

inline void check_2_lvl(int x, int y);

inline void rec(int x, int y);

//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> m;

	FOR(i, n)
	{
		cin >> s;
		FOR(j, m) mas[i][j] = s[j] == '1';
	}

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	FOR(i, n)
		FOR(j, m)
	if (mas[i][j])
	{
		rec(i, j);
		ans++;
	}

	cout << ans << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}

inline bool check_1_lvl(int x, int y)
{
	if (x >= n | x < 0 | y >= m | y < 0) re false;
	re true;
}

inline void check_2_lvl(int x, int y)
{
	if (mas[x][y] & check_1_lvl(x, y)) rec(x, y);
}

void rec(int x, int y)
{
	mas[x][y] = false;

	check_2_lvl(x - 1, y);
	check_2_lvl(x + 1, y);
	check_2_lvl(x, y - 1);
	check_2_lvl(x, y + 1);
}