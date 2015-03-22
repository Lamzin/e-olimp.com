#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, k, x, y;
bool mas[100][100], ans = true;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		mas[i][j] = false;
	
	for (int i = 0; i < k; i++)
	{
		cin >> x>> y;
		if (!mas[x - 1][y - 1])
		{
			mas[x - 1][y - 1] = mas[y - 1][x - 1] = true;
		}
		else ans = false;
	}
	
	if (ans)
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		if (i - j && !mas[i][j])
		{
			ans = false;
			i = j = n;
		}
	}

	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}