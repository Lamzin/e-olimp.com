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

s32 d[52][52], n, m, k, a, b, tmp;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		d[a][b] = 1;
	}

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (d[i][j]) cout << "*";
			else
			{
				tmp = d[i - 1][j] + d[i][j - 1] + d[i + 1][j] + d[i][j + 1] + d[i + 1][j + 1] + d[i - 1][j - 1] + d[i + 1][j - 1] + d[i - 1][j + 1];;
				if (tmp) cout << tmp;
				else cout << ".";
			}
		}
		cout << endl;
	}


	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}