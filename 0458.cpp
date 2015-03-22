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
//#undef FILE

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

bool a[100][100], b[100][100];
char ch, c[4];
int n, m;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> ch;
		if (ch == '1') a[i][j] = true;
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> ch;
		if (ch == '1') b[i][j] = true;
	}

	cin >> c[0] >> c[1] >> c[2] >> c[3];

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		if (!a[i][j] && !b[i][j]) cout << c[0];
		else if (!a[i][j] && b[i][j]) cout << c[1];
		else if (a[i][j] && !b[i][j]) cout << c[2];
		else cout << c[3];
		cout << endl;
	}

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}