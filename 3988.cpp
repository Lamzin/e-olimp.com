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
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		mas[x - 1][y - 1] = mas[y - 1][x - 1] = true;;
	}

	for (int a = 0; a < n; a++)
	for (int b = 0; b < n; b++)
	for (int c = 0; c < n; c++)
	if (a - b && b - c && a - c)
	{
		if (mas[a][b] && mas[b][c] && !mas[a][c]) ans = false;
	}

	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}