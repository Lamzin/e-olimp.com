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
#define sz size()
#define len length()
#define sqr(x) ((x) * (x))
#define FOR(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define FOR2(i,n,m) for((i) = n; (i) <= (int)(m); (i)++)
#define FOR3(i,n,m) for((i) = n; (i) >= (int)(m); (i)--)
#define get(a) cin >> a
#define pri(a) cout << a;
#define prin cout << endl;
#define pris cout << " ";
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

ll tmp, n, i;
string s;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	while (cin)
	{
		get(n);
		if (cin)
		{
			tmp = n;
			s = "";
			if (tmp == 0) s = "10";
			else if (tmp == 1) s = "1";
			else
			{
				for (int i = 9; i > 1; i--)
				while (tmp % i == 0)
				{
					s += i + 48;
					tmp /= i;
				}
				if (tmp != 1) s = "-1";
				else
				{
					for (int j = 0; j < s.len / 2; j++) swap(s[j], s[s.len - j - 1]);
				}
			}

			pri(s);
			prin;
		}
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