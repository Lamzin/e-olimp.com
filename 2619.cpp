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

long n, Sum = 0, tmp = 0;
unsigned char mas[1000000], ch;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		Sum += mas[i] - 48;
	}

	for (int i = 0; i < n; i++)
	{
		tmp += mas[i] - 48;
		if (tmp * 2 == Sum)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}