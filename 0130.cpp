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

pair <s64, s64> a, b, c, d, delta;
s64 ab, ac, bc;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	ab = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
	ac = (a.first - c.first)*(a.first - c.first) + (a.second - c.second)*(a.second - c.second);
	bc = (c.first - b.first)*(c.first - b.first) + (c.second - b.second)*(c.second - b.second);

	if (ab > bc) swap(a, c);
	else if (ac > bc) swap(a, b);
	

	/*cout << a.first << " " << a.second << endl;
	cout << b.first << " " << b.second << endl;
	cout << c.first << " " << c.second << endl;*/

	delta.first = a.first - b.first;
	delta.second = a.second - b.second;

	d.first = c.first - delta.first;
	d.second = c.second - delta.second;

	cout << d.first << " " << d.second << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}