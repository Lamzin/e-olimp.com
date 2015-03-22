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

s32 n, m, tmp1, tmp2, mas[100001], ans = 0, group = 0, TMP;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> tmp1 >> tmp2;

		tmp1--; tmp2--;

		if (!mas[tmp1] && !mas[tmp2])
		{
			group++; ans++;
			mas[tmp1] = mas[tmp2] = group;
		}
		else if (mas[tmp1] != 0 && mas[tmp2] == 0) mas[tmp2] = mas[tmp1];
		else if (mas[tmp2] != 0 && mas[tmp1] == 0) mas[tmp1] = mas[tmp2];
		else if (mas[tmp1] != mas[tmp2])
		{
			ans--;
			TMP = mas[tmp2];
			for (int j = 0; j < n; j++)
			if (mas[i] == TMP) mas[i] = TMP;
		}
	}

	for (int i = 0; i < n; i++) ans += mas[i] == 0;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	cout << ans << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}