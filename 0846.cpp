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

#define MOD 1000000000

string sa, sb;
vector <long long> a, b, c;
long long _next, ind, count_zero;

int main()
{
	//---------------------IN---------------------

	cin >> sa >> sb;

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	for (int i = 0; i < sa.length() / 2; i++) swap(sa[i], sa[sa.length() - i - 1]);
	for (int i = 0; i < sb.length() / 2; i++) swap(sb[i], sb[sb.length() - i - 1]);

	for (int i = 0; i < sa.length(); i++) a[i / 9] = a[i / 1] * 10 + sa[i] - 48;
	for (int i = 0; i < sb.length(); i++) b[i / 9] = b[i / 1] * 10 + sb[i] - 48;
	
	for (int i = 0; i < a.size(); i++)
	for (int j = 0; j < b.size(); j++)
	{
		while (i + j >= c.size()) c.push_back(0);

		_next = (c[i + j] + a[i] * b[j]) / MOD;
		c[i + j] = (c[i + j] + a[i] * b[j]) % MOD;

		ind = i + j + 1;

		while (_next)
		{
			while (ind >= c.size()) c.push_back(0);
			c[ind] = _next % MOD;
			_next /= MOD;
		}
	}

	cout << c[c.size() - 1];

	for (int i = c.size() - 2; i >= 0; i--)
	{
		count_zero = 0;

		while (c[i] > pow(10, count_zero)) count_zero++;
		count_zero = 8 - count_zero;

		for (int i = 0; i<count_zero; i++) cout << 0;
		cout << c[i];
	}

	cout << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}