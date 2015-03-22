#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, m, tmp, x, y, ans = 0;
bool mas[1000][1000];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++)
		mas[i][j] = false;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		mas[x - 1][y - 1] = mas[y - 1][x - 1] = true;
	}

	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j]) tmp++;
		}
		if (tmp == 1) ans++;
	}
	cout << ans << endl;
}