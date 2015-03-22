#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, k, ans = 0;

int main()
{
	cin >> n >> k;
	if (n == 0) cout << "-1" << endl;
	else 
	{
		for (int i = 2; i <= n*2; i++)
		{
			if (n % i == k) ans++;
		}
		cout << ans << endl;
	}
}