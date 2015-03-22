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

u64 d[50001], data[50001], n, Mod, Limite, power;
char ch;
bool db[50001];

//---------------------VAR---------------------

//---------------------FUNC--------------------
u64 dp(u64 pos)
{
	if (pos > n) return 0;
	if (pos == n) return 1;
	if (db[pos]) return d[pos];
	
	u64 tmp = 0;

	db[pos] = true;

	if (data[pos + 1])
	{
		u64 m = data[pos + 1], index = pos + 1;

		while (m <= Limite)
		{
			tmp = (tmp + dp(index)) % Mod;
			if (index >= n) break;
			m = m * 10 + data[++index];
		}
	}
	else tmp = dp(pos + 1); // 0

	return d[pos] = tmp % Mod;
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> Limite >> power;
	for (u64 i = 1; i <= n; i++)
	{
		cin >> ch;
		data[i] = ch - 48;
	}

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	Mod = 1;
	for (int i = 1; i <= power; i++) Mod *= 10;
	//Mod = pow(10, Mod);

	cout << dp(0) << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif

	return 0;
}