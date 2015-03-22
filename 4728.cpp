#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string str;

bool check(int a, int b)
{
	while (a <= b) if (str[a++] != str[b--]) return false;
	return true;
}

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	for (int j = i + 1; j < str.length(); j++)
	{
		if (j - i > 0)
		{
			if (check(i, j))
			{
				for (int h = i; h <= j; h++) cout << str[h];
				cout << endl;
				return 0;
			}
		}
	}
	cout << "0" << endl;
}