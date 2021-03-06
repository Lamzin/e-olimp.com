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

int d[10001], n;

//---------------------VAR---------------------

//---------------------FUNC--------------------
int dp(int param)
{
	if (param == 1) return 0;
	if (d[param] != -1) return d[param];

	int med = 1;

	while (med * 2 < param)  
	if (!dp(param - med++)) return d[param] = 1;

	return d[param] = 0;
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n;
	for (int i = 0; i <= n; d[i++] = -1);

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	int TMP = 1;

	while (TMP * 2 < n)
	if (!dp(n - TMP))
	{
		cout << TMP << endl;
		return 0;
	}
	else TMP++;

	cout << 0 << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}