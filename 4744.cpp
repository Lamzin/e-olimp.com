#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long x, y;

long long func(long long a, long long b)
{
	if (b == 0) return a;
	else return func(b, a % b);
}

int main()
{
	cin >> x >> y;
	cout << x*y / func(x, y) << endl;
}