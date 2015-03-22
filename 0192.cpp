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

s64 n, a, b, _count;

//---------------------VAR---------------------

//---------------------FUNC--------------------
bool checker(s64 param)
{
	if (param == 2) return true;

	if (!(param % 2)) return false;
	
	for (int i = 3; i*i <= param; i+=2) if (!(param % i)) return false;
	
	return true;
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

	a = 1;
	b = 2;

	while (_count != n)
	{
		if (checker(b)) _count++;
		b += a;
		a = b - a;
	}

	cout << a << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}