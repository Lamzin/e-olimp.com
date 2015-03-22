#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <Windows.h>

#define DEBUG
//#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
double timeStart = clock();
#endif

#define MAX(a,b) (a < b) ? (b) : (a) 

int n, d[1000], mas[1000], ans = 1;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> mas[i];


	for (int i = 0; i < n; i++)
	{
		d[i] = 1;

		for (int j = 0; j < i; j++)
		if (mas[j] < mas[i])
		{
			d[i] = MAX(d[i], d[j] + 1);
		}
	}

	ans = d[0];

	for (int i = 0; i < n; i++)
		ans = MAX(ans, d[i]);

	cout << ans << endl;

#ifdef DEBUG
	cout.precision(3);
	double timeEnd = clock();
	cout << "\n=======\n\nTime = " << fixed << (timeEnd - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}