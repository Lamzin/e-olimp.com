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

vector <s16> vect;
s16 sum, tmp, tmpSum;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> sum;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	for (s16 i = 100; i < 1000; i++)
	{
		tmp = i;
		tmpSum = 0;
		while (tmp)
		{
			tmpSum += tmp % 10;
			tmp /= 10;
		}
		if (tmpSum == sum) vect.push_back(i);
	}

	cout << vect.size() << endl;

	for (s16 i = 0; i < vect.size(); i++) cout << vect[i] << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}