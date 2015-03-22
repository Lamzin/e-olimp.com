#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long n, Sum = 0;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		Sum += i*i;
	};
	cout << Sum << endl;
}