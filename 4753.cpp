#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

pair <long long, long long> a, b;
long long n, m, ans = 0;


int main()
{
	cin >> n >> m;
	a.first = a.second = b.first = b.second = 0;
	for (int i = 0; i < n*m; i++)
	{
		if (a == b) ans++;

		if (a.first < n - 1) a.first++;
		else
		{
			a.first = 0;
			a.second++;
		}
		
		if (b.second< m - 1) b.second++;
		else
		{
			b.second = 0;
			b.first++;
		}
	}

	cout << ans << endl;
}