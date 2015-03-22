#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

using namespace std;

long long st, tmp1, tmp2, tmp3, n;

long long f(long long a, long long b, long long c)
{
	return c + b * 29 + a * 17 * 29;
}

int main()
{
	cin >> tmp1 >> tmp2 >> tmp3 >> n;
	st = f(tmp1, tmp2, tmp3);

	for (int i = 0; i<n; i++)
	{
		cin >> tmp1 >> tmp2 >> tmp3;
		st -= f(tmp1, tmp2, tmp3);
		if (st < 0)
		{
			cout << -1 << endl;
			st = -1;
			return 0;
		}
	}

	long long st1, st2, st3;

	st1 = st / (17 * 29);
	st = st - st1 * 17 * 29;
	st2 = st / 29;
	st = st - st2 * 29;
	st3 = st;

	if (st == -1) cout << -1<< endl;
	else cout << st1 << " " << st2 << " " << st3 << endl;

	return 0;
}