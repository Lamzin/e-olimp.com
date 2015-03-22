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


int n, dn[5000];

int rec(int index)
{
	if (dn[index] != -1) return dn[index];
	else
	{
		int ans = 1 + rec(index - 1);

		for (int i = 2; i < index / 2; i++) ans = min(ans, rec(i) + rec(index - i));
		for (int i = 2; i <= sqrt(index); i++)
		if (index % i == 0) ans = min(ans, rec(i) + rec(index / i));

		return dn[index] = ans;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i <= n; i++) dn[i] = -1;

	dn[0] = dn[1] = 1;

	cout << rec(n) << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}