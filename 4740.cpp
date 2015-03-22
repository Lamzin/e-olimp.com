#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, mas[1000], tmp, value = 0, ans;

int main()
{
	cin >> n;
	memset(mas, 0, 1000);

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		mas[tmp - 1]++;
	}

	for (int i = 0; i < 1000; i++)
	{
		if (mas[i] > value)
		{
			value = mas[i];
			ans = i + 1;
		}
	}
	cout << ans << endl;
}