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

pair <s64, s64> a, b, c, d;
s64 AB, AC, AD, BC, BD, CD;
bool x, y, z;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	AB = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
	AC = (a.first - c.first)*(a.first - c.first) + (a.second - c.second)*(a.second - c.second);
	AD = (a.first - d.first)*(a.first - d.first) + (a.second - d.second)*(a.second - d.second);
	BC = (b.first - c.first)*(b.first - c.first) + (b.second - c.second)*(b.second - c.second);
	BD = (b.first - d.first)*(b.first - d.first) + (b.second - d.second)*(b.second - d.second);
	CD = (c.first - d.first)*(c.first - d.first) + (c.second - d.second)*(c.second - d.second);

	x = (AB == CD) && (AC == BC) && (BC == BD) && (BD == AD) && (AC + BC == AB);
	y = (AC == BD) && (AB == BC) && (BC == CD) && (CD == AD) && (AB + BC == AC);
	z = (AD == BC) && (AB == BD) && (BD == CD) && (CD == AC) && (AB + BD == AD);

	if (x | y | z) cout << "YES" << endl;
	else cout << "NO" << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}