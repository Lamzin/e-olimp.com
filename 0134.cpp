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

pair <s64, s64> o1, o2, a;
s64 r1, r2;
s64 ans;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	o1 = o2 = a = make_pair(0,0);

	cin >> o1.first >> o1.second >> r1 >> o2.first >> o2.second >> r2;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (s64 x = -300; x < 300; x = x + 1)
	for (s64 y = -300; y < 300; y = y + 1)
	if ((o1.first - x)*(o1.first - x) + (o1.second - y)*(o1.second - y) <= r1*r1 || (o2.first - x)*(o2.first - x) + (o2.second - y)*(o2.second - y) <= r2*r2) ans++;

	cout << ans << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}