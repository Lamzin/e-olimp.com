#include <iostream>
#include <algorithm>

using namespace std;

long long n, answer = 1, x, y, tmp;

int main()
{
	cin >> n >> x >> y;
	if (x > y) swap(x, y);
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		if (i >= x && i <= y) answer *= tmp;
	}
	cout << answer << endl;
}