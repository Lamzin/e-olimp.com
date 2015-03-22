#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long n;
string str;

int main()
{
	cin >> str;
	n = 0;
	if (str.length() > 3)
	{
		for (int i = str.length() - 3; i < str.length(); i++)
		{
			if (i >= 0)
			{
				n = n * 10 + (str[i] - 48);
			}
		}
	}
	else
	{
		for (int i = 0; i < str.length(); i++) n = n * 10 + (str[i] - 48);
	}
	//cout << n << endl;
	if (n % 2) cout << "No\n";
	else cout << "Yes\n";
	if (n % 4) cout << "No\n";
	else cout << "Yes\n";
	if (n % 8) cout << "No\n";
	else cout << "Yes\n";
}