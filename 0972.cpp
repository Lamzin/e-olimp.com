#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, a[100], b[100], c[100];
long long d[100];

int main()
{
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		d[i] = a[i] * 3600 + b[i] * 60 + c[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[i] > d[j])
			{
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				swap(c[i], c[j]);
				swap(d[i], d[j]);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " " << b[i] << " " << c[i] << endl;
	}
}