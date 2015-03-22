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

s32 d[20][20], ans, n, m;
char ch;

//---------------------VAR---------------------

//---------------------FUNC--------------------
void rec(s32 x, s32 y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
	if (d[x][y])
	{
		d[x][y] = 0;
		rec(x + 1, y);
		rec(x, y + 1);
		rec(x - 1, y);
		rec(x, y - 1);
	}
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> ch;
		if (ch == '#') d[i][j] = 1;
	}

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	if (d[i][j])
	{
		ans++;
		rec(i, j);
	}

	cout << ans << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}