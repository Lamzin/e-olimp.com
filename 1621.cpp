#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, ans = 0;

int main()
{
	//---------------------IN---------------------

	cin >> n;

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	if (n == 0) cout << 1 << endl;
	else if (n >= 1) cout << n*(n + 1) / 2 << endl;
	else if (n == -1) cout << 0;
	else
	{
		n *= -1;
		if (n % 2 == 0)
		{
			ans = (n / 2);
			ans *= -1;
			ans *= (n + 1);
			ans++;
		}
		else
		{
			ans = ((n + 1) / 2);
			ans *= -1;
			ans *= n;
			ans++;
		}

		cout << ans << endl;
	}
	
	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}