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

int n, m;
long long d[200][200], MAX, count_MAX = 0;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> d[i][j];

	for (int i = 1; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (j == 0) d[i][j] += max(d[i-1][j], d[i-1][j+1]);
		else if (j == m - 1) d[i][j] += max(d[i - 1][j], d[i - 1][j - 1]);
		else d[i][j] += max(max(d[i - 1][j - 1], d[i - 1][j + 1]), d[i - 1][j]);
	}

	MAX = d[n - 1][0];

	for (int i = 0; i < m; i++) MAX = max(MAX, d[n - 1][i]);

	for (int i = 0; i < m; i++) if (MAX == d[n - 1][i]) count_MAX++;

	cout << MAX << " " << count_MAX << endl;


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}