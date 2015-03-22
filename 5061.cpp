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

int n;
int d[500][500];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> d[i][j];

	for (int i = 1; i < n; i++) d[0][i] += d[0][i - 1];
	for (int i = 1; i < n; i++) d[i][0] += d[i - 1][0];

	for (int i = 1; i < n; i++)
	for (int j = 1; j < n; j++)
		d[i][j] += max(d[i - 1][j], d[i][j - 1]);

	cout << d[n - 1][n - 1] << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}