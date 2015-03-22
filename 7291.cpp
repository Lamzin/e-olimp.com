#include <iostream>
#include <algorithm>

using namespace std;

long long ans = 0;
long long n;

long long dn[10][30];

long long func(char k, char index)
{
	if (k > 9 || k < 0) return 0;
	else if (index == n - 1) return 1;
	else if (dn[k][index] != -1) return dn[k][index];
	else
	{
		return dn[k][index] = func(k, index + 1) + func(k + 1, index + 1) + func(k - 1, index + 1);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < 10; i++)
	for (int j = 0; j < n; j++)
		dn[i][j] = -1;

	for (char i = 1; i< 10; i++)
	{
		ans += func(i, 0);
	}

	cout << ans << endl;;

	return 0;
}