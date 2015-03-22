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
//#undef FILE

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

s64 n, tmp1, tmp2, count_len;
f32 ans;
bool bv[100];

vector< pair<s64, s64> > v;
vector< pair<f32, pair<s64, s64> > > len;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n;

	for (s64 i = 0; i < n; i++)
	{
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
	}
	
	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	for (s64 i = 0; i < n - 1; i++)
	for (s64 j = i + 1; j < n; j++)
		len.push_back(make_pair(hypot(v[i].first - v[j].first, v[i].second - v[j].second), make_pair(i, j)));

	sort(len.begin(), len.end());

	bv[len[0].second.first] = true;

	for (s64 i = 0; i < len.size(); i++)
	{
		if (count_len == n - 1) break;

		if (bv[len[i].second.first] ^ bv[len[i].second.second])
		{
			ans += len[i].first;
			bv[len[i].second.first] = bv[len[i].second.second] = true;
			i = 0;
		}
	}

	if (ans - (s32) ans >= 0.5) ans += 1;
	cout << (s32) ans << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}