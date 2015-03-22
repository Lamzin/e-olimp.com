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

s64 test;
string astr, bstr;
vector <char> a, b;

//---------------------VAR---------------------

//---------------------FUNC--------------------
void check()
{
	for (int i = 0; i < a.size(); i++)
	if (a[i] != b[i])
	{
		cout << "NO" << endl;
		return (void)0;
	}

	cout << "YES" << endl;
}
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> test;
	for (s64 i = 0; i < test; i++)
	{
		cin >> astr >> bstr;
		a.clear();
		b.clear();
		if (astr.length() == bstr.length())
		{
			for (int i = 0; i < astr.length(); i++) a.push_back(astr[i]);
			for (int i = 0; i < bstr.length(); i++) b.push_back(bstr[i]);
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			check();
		}
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