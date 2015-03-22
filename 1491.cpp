#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int n;

int main()
{
	cin >> n;

	if (n < 5)
	{
		cout << "-1\n";
	}
	else if (n == 5)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 0; i < n - 4; i++)
			cout << "0 ";
		cout << "1 0 1 1\n";
	}
}