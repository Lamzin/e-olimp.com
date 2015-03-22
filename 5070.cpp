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

bool mas[102][102];
int n, m, ans;

void rec(int a, int b)
{
	mas[a][b] = false;
	if (mas[a - 1][b]) rec(a - 1, b);
	if (mas[a + 1][b]) rec(a + 1, b);
	if (mas[a][b - 1]) rec(a, b - 1);
	if (mas[a][b + 1]) rec(a, b + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		mas[i][0] = mas[i][m + 1] = false;

	for (int j = 0; j < m; j++)
		mas[0][j] = mas[n + 1][j] = false;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> mas[i][j], mas[i][j] = !mas[i][j];

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	if (mas[i][j])
	{
		ans++;
		rec(i, j);
	}

	cout << ans << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}