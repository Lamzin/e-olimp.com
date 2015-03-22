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

int n, index = 0;
char ch, X, Y;
pair <char, char> _beg, _end;
bool input = false;
char d[50][50], dTMP[50][50];
vector < pair < pair < char, char >, int> > vect;

void PushtoVect(char x, char y, int k)
{
	if (x >= 0 && x < n && y >= 0 && y < n)
	if (dTMP[x][y] != '#')
	{
		dTMP[x][y] = '#';
		vect.push_back(make_pair(make_pair(x, y), k));
	}
}

int main()
{
	//---------------------IN---------------------

	cin >> n;
	for (char i = 0; i < n; i++)
	for (char j = 0; j < n; j++)
	{
		cin >> ch;
		if (ch == '@' && !input) _beg = make_pair(i,j), input = true;
		else if (ch == '@') _end = make_pair(i, j);
		
		d[i][j] = dTMP[i][j] = ch;
	}

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	PushtoVect(_beg.first, _beg.second, 0);

	while (vect[index].first != _end)
	{
		X = vect[index].first.first;
		Y = vect[index].first.second;
	
		PushtoVect(X + 1, Y + 2, index);
		PushtoVect(X + 2, Y + 1, index);
		PushtoVect(X - 1, Y + 2, index);
		PushtoVect(X + 2, Y - 1, index);
		PushtoVect(X + 1, Y - 2, index);
		PushtoVect(X - 2, Y + 1, index);
		PushtoVect(X - 1, Y - 2, index);
		PushtoVect(X - 2, Y - 1, index);

		index++;

		if (index >= vect.size())
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}

	while (index != 0)
	{
		d[vect[index].first.first][vect[index].first.second] = '@';
		index = vect[index].second;
	}

	for (char i = 0; i < n; i++)
	{
		for (char j = 0; j < n; j++) cout << d[i][j];
		cout << endl;
	}

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}