#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

using namespace std;

long long int a, b;

long long int f(long long int a, long long int b)
{
	if (b == 0) return a;
	else return f(b, a % b);
}

int main()
{
	cin >> a >> b;

	cout << a*b / f(a, b) << endl;

	return 0;
}