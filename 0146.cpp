#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int n;

double answer = 0, stmp = 100;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		answer += stmp / 2;
		stmp /= 4;
	}

	cout.precision(5);
	cout << fixed << answer << endl;
}