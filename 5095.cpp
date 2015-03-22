#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, m;
bool first = false;
string a, b = "", c;

int main()
{
	cin >> n >> m >> a >> c;

	if (n < m)
	{
		swap(n, m);
		swap(a, c);
	}

	for (int i = 0; i < n - m; i++)
	{
		b += "0";
	}
	b += c;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] + b[i] == 97)
		{
			cout << "1";
			first = true;
		}
		else if (first)cout << "0";
	}
	if (!first) cout << "0";
	cout << endl;
}