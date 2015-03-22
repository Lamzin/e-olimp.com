#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long ans, n, dn[100][10000], index[330];
vector <int> simple;


bool fsimple(int a)
{
	for (int i = 2; i*i <= a; i++)
	if (a % i == 0) return false;
	return true;
}

long long rec(int prev, long long Sum)
{
	if (Sum > n) return 0;
	else
	{
		if (Sum == n) return 1;
		else if (dn[index[prev]][Sum] != -1) return dn[index[prev]][Sum];
		else
		{
			long long tmp = 0;

			for (int i = 0; i < simple.size(); i++)
			if (simple[i] <= prev) tmp += rec(simple[i], Sum + simple[i]);
			else break;

			return dn[index[prev]][Sum] = tmp;
		}
	}
}

int main()
{
	fstream in("input.txt", ios::in), out("output.txt", ios::out);

	for (int i = 2; i < 330; i++) if (fsimple(i))
	{
		index[i] = simple.size();
		simple.push_back(i);
	}

	while (in)
	{
		in >> n;

		if (in)
		{
			for (int i = 0; i < simple.size(); i++)
			for (int j = 0; j < n; j++) dn[i][j] = -1;
			
			ans = 0;

			for (int i = 0; i < simple.size(); i++)
			if (simple[i] <= n) ans += rec(simple[i], simple[i]);
				else break;

			out << ans << endl;
		}
	}
}