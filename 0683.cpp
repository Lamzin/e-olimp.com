#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, m, mas[1000][1000];
long long tmp = 0;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mas[i][j];
		}
	}

	for (int i = 1; i < n; i++) mas[i][0] += mas[i - 1][0];
	for (int j = 1; j < m; j++) mas[0][j] += mas[0][j - 1];

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			mas[i][j] += mas[i - 1][j] + mas[i][j - 1] - mas[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j) cout << " ";
			cout << mas[i][j];
		}
		cout << endl;
	}
}