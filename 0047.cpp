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
long long timeStart = time(NULL);
#endif

vector <pair<int, pair<int, pair<int, int>>>> vect;
pair<int, pair<int, int>> a, b;
int n, m, x, y, index = 0;
int X, Y, TYPE;
pair<bool,bool> mas[100][100];

void check(int xtmp, int ytmp, int valuetype, int value)
{
	if (xtmp >= 0 && xtmp  < n && ytmp >= 0 && ytmp  < m)
	{
		if (valuetype)
		{
			if (mas[xtmp][ytmp].first == false)
			{
				vect.push_back(make_pair(value + 1, make_pair(valuetype, make_pair(xtmp, ytmp))));
				mas[xtmp][ytmp].first = true;
			}
		}
		else if (!valuetype)
		{
			if (mas[xtmp][ytmp].second == false)
			{
				vect.push_back(make_pair(value + 1, make_pair(valuetype, make_pair(xtmp, ytmp))));
				mas[xtmp][ytmp].second = true;
			}
		}
	}
}


int main()
{
	cin >> m >> n >> x >> y;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) mas[i][j].first = mas[i][j].second = false;

	a.first = x % 2;
	x--;
	a.second.first = (x / 2) / m;
	a.second.second = (x / 2) % m;

	b.first = y % 2;
	y--;
	b.second.first = (y / 2) / m;
	b.second.second = (y / 2) % m;

	vect.push_back(make_pair(0, a));

	if (a.first) mas[a.second.first][a.second.second].first = true;
		else mas[a.second.first][a.second.second].second = true;

	while (vect[index].second != b)
	{
		X = vect[index].second.second.first;
		Y = vect[index].second.second.second;
		TYPE = vect[index].second.first;

		if (TYPE)
		{
			check(X - 1, Y, !TYPE, vect[index].first);
			check(X, Y - 1, !TYPE, vect[index].first);
			check(X , Y, !TYPE, vect[index].first);
		}
		else
		{
			check(X + 1, Y, !TYPE, vect[index].first);
			check(X, Y + 1, !TYPE, vect[index].first);
			check(X , Y, !TYPE, vect[index].first);
		}

		index++;
	}

	cout << vect[index].first << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}