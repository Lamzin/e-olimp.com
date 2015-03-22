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

long long n;

int main()
{
	//---------------------IN---------------------

	cin >> n;

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	if (n == 2) cout << "Yes" << endl;
	else if (n % 2 == 0) cout << "No" << endl;
	else
	{
		for (int i = 3; i*i <= n; i+=2)
		if (n % i == 0)
		{
			cout << "No" << endl;
			return 0;
		}

		cout << "Yes" << endl;
	}

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}