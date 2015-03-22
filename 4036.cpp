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

int n, d[100000];

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	sort(d, d + n);

	cout << d[0];

	for (int i = 1; i < n; i++) cout << " " << d[i];

	cout << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}