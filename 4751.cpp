#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

pair <long long, long long> sum;
long long n, tmp;

int main()
{
	cin >> n;
	sum.first = sum.second = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> tmp;
		if (i == j) sum.first += tmp;
		if (n - i - 1 == j) sum.second += tmp;
	}
	cout << sum.first << " " << sum.second << endl;
}