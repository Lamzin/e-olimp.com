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

vector <int> vect;
long long n, k, tmp, ans = 0;
long long dn[200][200];

long long SUM(int left, int right)
{
	long long tmp = 0;
	for (int i = left; i <= right; i++)
		tmp += vect[i];

	return tmp;
}

long long rec(int index, int count)
{
	if (index >= n) return 1;
	else if (index == n - 1) return 1;
	else if (dn[index][count] != -1) return dn[index][count];
	else
	{
		long long tmp = 0;

		for (int i = 1; i <= index; i++) tmp = max(tmp, SUM(index, index + i - 1) - rec(index + i, i));

		return dn[index][count] = tmp;
	}
	
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}
	cin >> k;

	for (int i = 0; i < 200; i++) 
	for (int j = 0; j < 200; j++) dn[i][j] = -1;

	for (int i = 1; i <= k; i++)
		ans = max(ans, rec(0, i));

	cout << ans << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}