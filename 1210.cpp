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

unsigned long long ans = 0, a, n, power = 0;

int main()
{
	cin >> n >> a;
	power = a;

	if (a == 1) cout << n * (n+1) / 2 << endl;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			ans += i * power;
			power *= a;
		}

		cout << ans << endl;
	}
#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}