#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, m, mas[500][500], tmp, Sum = 0;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> mas[i][j];
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> tmp;
		if (tmp == 1) Sum +=mas[i][j];
	}

	cout << Sum << endl;
}