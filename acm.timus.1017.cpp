#include <iostream>

using namespace std;

long long n, ans = 0;
long long dn[500][500];


long long rec(long long prlvl, long long sum)
{
	if (sum < 0) return 0;
	else if (sum == 0) return 1;
	else
	{
		if (dn[prlvl][sum] != -1)
			return dn[prlvl][sum];
		else
		{
			long long res = 0;
			for (int i = 1; i<prlvl; i++)
				res += rec(i, sum - i);
			return dn[prlvl][sum] = res;
		}
	}
}

void memorySet()
{
	for (int i = 0; i<500; i++)
	for (int j = 0; j<500; j++) dn[i][j] = -1;
}

int main()
{
	memorySet();

	cin >> n;
	for (int i = 1; i<n; i++)
		ans += rec(i, n - i);
	cout << ans << endl;
}