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

int test, n, m, i, j, ans, eventCount;
char d[100][100];
unsigned int mas[100][100];
bool bevent, key[26];
string str;

//---------------------VAR---------------------

//---------------------FUNC--------------------

void rec(char x, char y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
	if (mas[x][y] != eventCount && d[x][y] != '*')
	{
		if (d[x][y] == '.')
		{
			mas[x][y] = eventCount;
			rec(x + 1, y); rec(x - 1, y); rec(x, y + 1); rec(x, y - 1);
		}
		else if (d[x][y] >= 'A' && d[x][y] <= 'Z')
		{
			if (key[d[x][y] - 65])
			{
				mas[x][y] = eventCount; bevent = true; d[x][y] = '.';
				rec(x + 1, y); rec(x - 1, y); rec(x, y + 1); rec(x, y - 1);
			}
		}
		else if (d[x][y] >= 'a' && d[x][y] <= 'z')
		{
			key[d[x][y] - 97] = true; d[x][y] = '.';
			mas[x][y] = eventCount; bevent = true;
			rec(x + 1, y); rec(x - 1, y); rec(x, y + 1); rec(x, y - 1);
		}
		else if (d[x][y] == '$')
		{
			ans++; d[x][y] = '.';
			mas[x][y] = eventCount;
			rec(x + 1, y); rec(x - 1, y); rec(x, y + 1); rec(x, y - 1);
		}
	}
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> test;
	for (int _test = 0; _test < test; _test++)
	{
		for (i = 0; i < 26; i++) key[i] = false;
		for (i = 0; i < 100; i++) for (j = 0; j < 100; j++) mas[i][j] = 0;
		bevent = true; ans = 0;

		cin >> n >> m;
		for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> d[i][j];
		cin >> str;
		if (str != "0") for (i = 0; i < str.length(); i++) key[str[i] - 97] = true;

		for (eventCount = 1; bevent; eventCount++)
		{
			bevent = false;
			for (i = 0; i < n; i++) rec(i,0);
			for (i = 0; i < n; i++) rec(i, m - 1);
			for (i = 0; i < m; i++) rec(0, i);
			for (i = 0; i < m; i++) rec(n - 1, i);
		}

		cout << ans << endl;
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