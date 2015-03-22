#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
boudle timeStart = clock();
#endif

long long n;
long long dn[500][500], ans = 0;

long long rec(long long prev, long long sum)
{
	if (sum > n) return 0;
	else if (sum == n) return 1;
	else if (dn[prev][sum] != -1) return dn[prev][sum];
	else
	{
		long long tmp = 0;

		for (int i = 1; i < prev; i++) tmp += rec(i, sum + i);

		return dn[prev][sum] = tmp;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < 500; i++)
	for (int j = 0; j < 500; j++) dn[i][j] = -1;

	for (int i = 1; i <= n; i++) ans += rec(i, i);

	cout << ans << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}