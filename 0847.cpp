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

int n, d[100][100], x = 0, y = 1, way = 0;

int main()
{
	//---------------------IN---------------------
	cin >> n;
	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = 0;

	d[0][0] = 1;

	for (int i = 2; i <= n*n; i++)
	{
		d[x][y] = i;

		if (way == 0)
		{
			x++;
			y--;
			if (x == n) way++, x = n - 1, y += 2;
			else if (y == -1) way++, y = 0;
		}
		else
		{
			x--;
			y++;
			if (y == n) way++, x += 2, y = n - 1;
			else if (x == -1) way++, x = 0;
		}

		way %= 2;
	}

	for (int i = 0; i < n; i++)
	{
		cout << d[i][0];
		for (int j = 1; j < n; j++) cout << " " << d[i][j];
		cout << endl;
	}

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}