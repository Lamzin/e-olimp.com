#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, ans = 0, x, y;

int main()
{
	cin >> n;
	for (int i = n; i < 9999; i++)
	{
		x = i;
		y = i + 1;
		while (x)
		{
			if (x % 10 != y % 10) ans++;
			x /= 10;
			y /= 10;
		}
	}
	cout << ans << endl;
}