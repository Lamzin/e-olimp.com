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
//#undef DEBUG
#define FILE
//#undef FILE

#ifdef FILE
#define cin in
//#define cout out
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

//bitset <1000000000> bs;
bool bs[1000000000];
u64 _simple_count = 0;
//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------



	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (u64 i = 2; i < 1000000000; i++)
	{
		if (!bs[i])
		{
			_simple_count++;
			if (_simple_count % 10000 == 0) cout << i << endl;
			for (u64 j = i * 2; j < 1000000000; j += i) bs[j] = true;
		}
	}

	for (u64 i = 2; i < 1000000000; i++)
	if (!bs[i]) out << i << "," << endl;
	
	cout << endl << "count = " << _simple_count << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}