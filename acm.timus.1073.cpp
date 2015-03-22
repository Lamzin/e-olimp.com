#include <iostream>
#include <algorithm>
#include <math.h>
#define SIZE 60000

using namespace std;

int dn[SIZE], n;

int rec(int tmp)
{
	if (tmp <= 0) return 0;
	if (dn[tmp] != -1) return dn[tmp];
	else
	{
		int tmp_sq = 1, res = rec(tmp - 1) + 1;
		tmp_sq++;
		while (tmp_sq * tmp_sq <= tmp)
		{
			res = min(res, rec(tmp - tmp_sq*tmp_sq) + 1);
			tmp_sq++;
		}
		return dn[tmp] = res;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i <= n; i++) dn[i] = -1;

	cout << rec(n);
}