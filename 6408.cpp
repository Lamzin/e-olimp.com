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

int n;
f64 a[4];
bool ans;

//---------------------VAR---------------------

//---------------------FUNC--------------------
bool dn(f64 val, byte mask)
{
	if (!mask && val == (f64) 24) return true;
	else if (!mask) return false;
	else
	{
		bool tmp = false;

		for (int i = 0; i < 4; i++)
		if (mask & (1 << i))
		{
			tmp |= dn(val + a[i], mask ^ (1 << i));
			tmp |= dn(val - a[i], mask ^ (1 << i));
			tmp |= dn(val * a[i], mask ^ (1 << i));
			tmp |= dn(val / a[i], mask ^ (1 << i));
		}

		return tmp;
	}
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		ans = false;

		for (int i = 0; i < 4; i++)
		{
			ans |= dn(a[i], 15 ^ (1 << i));
		}

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
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