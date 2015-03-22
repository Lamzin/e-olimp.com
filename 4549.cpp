#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define SIZE 1000
bool mas[SIZE][SIZE];
long long n, m, answer = 0;
char tmp;
vector <pair<long long, long long>> vect;

void rec(long long x, long long y)
{
	mas[x][y] = 0;
	if (x > 1)
	{
		if (mas[x - 1][y] == true) rec(x - 1, y);
	}
	if (x < n - 2)
	{
		if (mas[x + 1][y] == true) rec(x + 1, y);
	}
	if (y > 1)
	{
		if (mas[x][y - 1] == true) rec(x, y - 1);
	}
	if (y < m - 2)
	{
		if (mas[x][y + 1] == true) rec(x, y + 1);
	}
}

int main()
{
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
	for (long long j = 0; j < m; j++)
	{
		cin >> tmp;
		if (tmp == '0')
		{
			mas[i][j] = true;
			vect.push_back(make_pair(i, j));
		}
		else mas[i][j] = false;
	}


	for (long long i = 0; i < vect.size(); i++)
	{
		if (mas[vect[i].first][vect[i].second] == true)
		{
			rec(vect[i].first, vect[i].second);
			answer++;
		}
	}
	cout << answer << endl;
}