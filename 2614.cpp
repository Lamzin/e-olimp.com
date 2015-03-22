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

long long n, wr = 1, _count = 0;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (_count == wr)
		{
			_count = 0;
			wr++;
		}
		if (i != 0) cout << " ";
		cout << wr;
		_count++;
	}

	cout << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}