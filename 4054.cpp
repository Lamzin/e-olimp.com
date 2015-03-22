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

s64 n, d[100][100];

//---------------------VAR---------------------

//---------------------FUNC--------------------

s64 dp(s64 one, s64 pos)
{
	if (one > 2 || pos > n) return 0;
	if (pos == n) return 1;
	
	if (d[one][pos] != -1) return d[one][pos];
	
	return d[one][pos] = dp(one + 1, pos + 1) + dp(0, pos + 1);
}

//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (int i = 0; i < 100; i++) 
	for (int j = 0; j < 100; j++) d[i][j] = -1;

	cout << dp(0, 0) << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}