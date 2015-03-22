#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long n, answer;

long long rec(long long param)
{
	if (param < 0) return 0;
	if (param == 0) return 1;
	else if (param == 2) return 3;
	else return rec(param - 2) * 4 - rec(param - 4);
}

int main()
{
	do
	{
		cin >> n;
		if (n != -1)
		{
			if (n == 1) cout << "0\n";
			else cout << rec(n) << endl;
		}
	} while (n != -1);
}