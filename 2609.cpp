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

bool simp(long long param)
{
	for (int j = 2; j*j <= param; j++)
	if (param % j == 0) return false;
	return true;
}

int main()
{
	cin >> n;

	for (int i = 2; i*i < n; i++)
	if (n % i == 0)
	if (simp(i) && simp(n / i))
	{
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}