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

int n, tmp, A, B;
string a, b;

//---------------------VAR---------------------

//---------------------FUNC--------------------
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

	tmp = n;

	for (int i = 2; i < 10; i++)
	while (tmp % i == 0)
	{
		a += i + 48;
		tmp /= i;
	}

	tmp = n;

	for (int i = 9; i > 1; i--)
	while (tmp % i == 0)
	{
		b += i + 48;
		tmp /= i;
	}

	if (tmp != 1)
	{
		cout << -1 << " " << -1 << endl;
	}
	else
	{
		for (int i = a.length() - 1; i >= 0; i--) A = A * 10 + a[i] - 48;
		for (int i = b.length() - 1; i >= 0; i--) B = B * 10 + b[i] - 48;
		cout << min(A, B) << " " << max(A, B) << endl;
	}

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}