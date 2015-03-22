#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

long long n, ans = 0, tmpl, len = 0;
long long dn[10000][143];
long long simple_index[1000];


bool simp(long long tmp)
{
	if (tmp < 100) return false;

	for (int i = 2; i*i<=tmp; i++)
		if (tmp % i == 0) return false;

	return true;
}

long long rec(long long pos, long long num)
{
	if (pos == n) return 1;
	else
	{
		if (dn[pos][simple_index[num]] != -1)
			return dn[pos][simple_index[num]];
		else
		{
			long long res = 0;

			for (int ind = 1; ind < 10; ind += 2)
			{
				tmpl = (num % 100) * 10 + ind;
				if (simple_index[tmpl] != -1)
				{
					res += rec(pos + 1, tmpl);
					res %= 1000000009;
				}
			}
			return dn[pos][simple_index[num]] = res;
		}
	}
}

void mems()
{
	for (int i = 0; i<10000; i++)
		for (int j = 0; j<143; j++)
			dn[i][j] = -1;

	for (int i = 0; i < 1000; i++) simple_index[i] = -1;
}

int main()
{
	mems();

	for (int i = 101; i < 1000; i += 2)
		if (simp(i)) simple_index[i] = len++;

	cin >> n;

	for (int i = 101; i<1000; i+=2) 
	if (simp(i))
	{
		ans += rec(3, i);
		ans %= 1000000009;
	}

	cout << ans << endl;
}