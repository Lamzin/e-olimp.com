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

bool mas[20][20];
int x, y, n, m, ans;
char tmp;

void rec(int a, int b)
{
	mas[a][b] = false;
	ans++;

	if (a > 0 && mas[a - 1][b]) rec(a - 1, b);
	if (a < n - 1 && mas[a + 1][b]) rec(a + 1, b);
	if (b > 0 && mas[a][b - 1]) rec(a, b - 1);
	if (b < m - 1 && mas[a][b + 1]) rec(a, b + 1);

}

int main()
{
	do
	{
		cin >> m >> n;

		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == '#') mas[i][j] = false;
			else if (tmp == '.') mas[i][j] = true;
			else if (tmp == '@')
			{
				x = i;
				y = j;
				mas[i][j] = true;
			}
		}
		ans = 0;
		rec(x, y);

		if (n) cout << ans << endl;

	} while (n);


#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}