#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define SIZE 100

bool mas[100][100];

int n, m, answer = 0;
char tmp;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == '.') mas[i][j] = true;
			else mas[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j])
			{
				if (i > 0 && j > 0 && mas[i - 1][j] && mas[i][j - 1]) answer++;
				if (i > 0 && j < m - 1 && mas[i - 1][j] && mas[i][j + 1]) answer++;
				if (i < n - 1 && j < m - 1 && mas[i + 1][j] && mas[i][j + 1]) answer++;
				if (i < n - 1 && j > 0 && mas[i + 1][j] && mas[i][j - 1]) answer++;
			}
		}
	}
	
	cout << answer << endl;
}