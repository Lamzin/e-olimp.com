#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define SIZE 20

int mas[SIZE][SIZE], n, m;

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

	for (int i = 1; i < n; i++) mas[i][0] += mas[i-1][0];
	for (int j = 1; j < m; j++) mas[0][j] += mas[0][j-1];

	for (int i = 1; i < n; i++)
	for (int j = 1; j < m; j++)
	{
		mas[i][j] += min(mas[i-1][j], mas[i][j-1]);
	}

	cout << mas[n - 1][m - 1] << endl;
}