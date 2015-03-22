#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int mas[1000][1000], n, m, tmp, ans = 0;

int main()
{
	cin >> n >> m;
	tmp = 1;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		mas[i][j] = tmp++;
	}

	tmp = 1;
	for (int j = 0; j < m; j++)
	for (int i = 0; i < n; i++)
	{
		if (mas[i][j] == tmp) ans++;
		tmp++;
	}
	/*if (n == m) cout << n << endl;
	else cout << "2" << endl;*/
	cout << ans << endl;
}