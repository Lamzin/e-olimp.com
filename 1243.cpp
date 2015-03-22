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

long long ans, n, m, tmp;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	//---------------------IN---------------------

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		cin >> ans;
		for (int j = 1; j < m; j++)
		{
			cin >> tmp;
			ans = ans * tmp / gcd(ans, tmp);
		}

		cout << ans << endl;
	}

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------






	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}