#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

using namespace std;

#define DEBUG
#undef DEBUG
#define FILE
#undef FILE

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

typedef char s8;
typedef short int s16;
typedef int s32;
typedef long long int s64;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef float f32;
typedef double f64;
typedef u8 byte;

//---------------------VAR---------------------

u64 n, m;
string d[100][100];

//---------------------VAR---------------------

//---------------------FUNC--------------------

string strSum(string a, string b)
{
	int _next, i;
	if (a.length() < b.length()) swap(a, b);
	for (i = 0; i < a.length() / 2; i++) swap(a[i], a[a.length() - i - 1]);
	for (i = 0; i < b.length() / 2; i++) swap(b[i], b[b.length() - i - 1]);
	for (i = 0; i < b.length(); i++)
	{
		_next += a[i] + b[i] - 96;
		a[i] = _next % 10 + 48;
		_next /= 10;
	}
	while (_next)
	{
		if (a.length() == i) a += _next + 48, _next = 0;
		else
		{
			_next += a[i] - 48;
			a[i] = _next % 10 + 48;
			_next /= 10;
			i++;
		}
	}
	for (i = 0; i < a.length() / 2; i++) swap(a[i], a[a.length() - i - 1]);
	return a;
}

string dp(u64 x, u64 y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return "0";

	if (x == n - 1 && y == m - 1) return "1";

	if (d[x][y] != "-1") return d[x][y];

	return d[x][y] = strSum(strSum(dp(x + 1, y + 2), dp(x + 2, y + 1)), strSum(dp(x - 1, y + 2), dp(x + 2, y - 1)));
}

//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> m;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (int i = 0; i < 100; i++)
	for (int j = 0; j < 100; j++) d[i][j] = "-1";

	cout << dp(0, 0) << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}