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

ull A, B;
string s, ans;

//---------------------VAR---------------------

//---------------------FUNC--------------------
bool ch()
{
	for (int i = 0; i < s.ln; i++)
	if (s[i] != '9') re false;
		
	pri(1);
	for (int i = 0; i < s.ln - 1; i++) pri(0);
	pri(1);
	prin;

	re true;
}
bool MAIN()
{
	A = 0;
	B = 0;

	if (ch()) re 0;//check s = "999...999"

	//for (int i = 0; i < s.ln / 2; i++) A = A * 10 + s[i] - 48;
	//for (int i = s.ln - 1; i >= (s.ln + 1) / 2; i--) B = B * 10 + s[i] - 48;

	for (int i = s.ln / 2 - 1; i >= 0; i--) A = A * 10 + s[i] - 48;
	for (int i = (s.ln + 1) / 2; i < s.ln; i++) B = B * 10 + s[i] - 48;

	if (s.ln % 2 && s[s.ln / 2] != '9' && A <= B)
	{
		for (int i = 0; i < s.ln / 2; i++) pri(s[i]);
		pri((char) (s[s.ln / 2] + 1));
		for (int i = s.ln / 2 - 1; i >= 0; i--) pri(s[i]);
		prin;
		re 0;
	}

	if (B >= A)
	{
		A++;
		ll ost = 1;
		for (int i = s.ln / 2 - 1; i >= 0; i--)
		{
			ost += s [i] - 48;
			ans += ost % 10 + 48;
			ost /= 10;
		}

		if (s.ln % 2) s[s.ln / 2] = '0';
	}
	else
	{
		ans = "";

		while (A)
		{
		ans += A % 10 + 48;
		A /= 10;
		}
		for (int i = 0; i < ans.ln / 2; i++) swap(ans[i], ans[ans.ln - i - 1]);

	}
	for (int i = ans.ln - 1; i >= 0; i--) pri(ans[i]);
	if (s.ln % 2) pri(s[s.ln / 2]);
	pri(ans);
	prin;

	re 0;
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	//get(s);

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	//s = "1040";
	get(s);
	MAIN();

	/*for (int i = 100; i < 10000; i++)
	{
		ll tmp = i;
		s = "";
		while (tmp)
		{
			s += tmp % 10 + 48;
			tmp /= 10;
		}
		for (int j = 0; j < s.ln / 2; j++) swap(s[j], s[s.ln - j - 1]);

		cout << i << " - ";
		MAIN();
	}*/

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}