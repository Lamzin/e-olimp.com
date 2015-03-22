#include <iostream>

using namespace std;

long long n, ans = 0;
long long dn[50][2];


long long rec(long long pos, long long code)
{
	if (pos == n) return 1;
	else if (pos > n) return 0;
	else
	{
		if (dn[pos][code] != -1)
			return dn[pos][code];
		else
		{
			if (code == 0)
			{
				return dn[pos][code] = rec(pos + 1, 1) + rec(pos + 2, 0);
			}
			else if (code == 1)
			{
				return dn[pos][code] = rec(pos + 1, 0) + rec(pos + 2, 1);
			}
		}
	}
}

int main()
{
	for (int i = 0; i<50; i++)
		dn[i][0] = dn[i][1] = -1;

	cin >> n;
	cout << rec(1, 0) + rec(1, 1) << endl;
}