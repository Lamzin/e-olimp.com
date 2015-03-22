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

char tmp;
bool fl = false;
long long a[2];

int main()
{
	while (in)
	{
		in >> tmp;
		if (in)
		{
			a[fl] += tmp - 48;
			if (fl) fl = 0;
				else fl = 1;
		}
	}

	out << abs(a[0]*a[1]) << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}