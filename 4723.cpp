#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int ans = 0, n, tmp;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!tmp) ans++;
	}
	cout << ans << endl;
}