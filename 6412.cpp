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

string str;
long long test, d[30];

//---------------------VAR---------------------

//---------------------FUNC--------------------
string sANS()
{
	for (int j = 0; j < 30; j++) d[j] = 0;

	for (int j = 0; j < (int) str.length() - 1; j++)
	{
		d[str[j] - 65]++;

		if (d[str[j] - 65] % 4 == 3 && str[j] != str[j + 1]) return "FAKE";
	}

	if ((d[str[str.length() - 1] - 65] + 1) % 4 == 3) return "FAKE";

	return "OK";
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> str;
		cout << sANS() << endl;
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