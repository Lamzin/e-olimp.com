#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = i*n + 1; j < (i + 1) * n; j++) cout << j << " ";
			cout << (i + 1) * n;
		}
		else
		{
			for (int j = (i + 1) * n; j > i*n + 1; j--) cout << j << " ";
			cout << i*n + 1;
		}
		cout << endl;
	}
}