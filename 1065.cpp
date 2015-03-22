#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

using namespace std;

#define DEBUG
#undef DEBUG
#define FILE
#undef FILE

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

int n, m, ans = 0;
bool d[200][200];
char tmp;

void rec(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
	{
		if (d[x][y])
		{
			d[x][y] = false;
			rec(x - 1, y);
			rec(x, y - 1);
			rec(x + 1, y);
			rec(x, y + 1);
		}
	}
}

int main()
{
	//---------------------IN---------------------

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> tmp;
		d[i][j] = tmp == '#';
	}

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	if (d[i][j])
	{
		ans++;
		rec(i,j);
	}

	cout << ans << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}