#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long tmp, ans = 0;

int main()
{
	do
	{
		cin >> tmp;
		if (tmp) ans++;
	} while (tmp);

	cout << ans << endl;
}