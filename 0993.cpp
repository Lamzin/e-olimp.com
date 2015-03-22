#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int mas[100], n, m, x, y;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) mas[i] = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		mas[x - 1]++; mas[y - 1]++;
	}

	cout << mas[0];
	for (int i = 1; i < n; i++)
		cout << " " << mas[i];
	cout << endl;

}