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

long test, n, ind, i, j;
string tmp;
string write[1000];
pair <short int, short int> index[1000];
pair <string, short int> vect[1000];

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> test;

	for (int _test = 0; _test < test; _test++)
	{
		cin >> n;

		for (i = 0; i < n; i++)
		{
			cin >> tmp;
			vect[i].first = tmp;
			vect[i].second = -1;
		}

		for (i = 0; i < n; i++)
		{
			cin >> tmp;
			ind = 0;
			while (vect[ind].first != tmp) ind++;
			index[i] = make_pair(ind,i);
		}

		sort(index, index + n);

		for (i = 0; i < n; i++) cin >> write[i];

		cout << write[index[0].second];
		for (i = 1; i < n; i++) cout << " " << write[index[i].second];
		cout << endl;
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