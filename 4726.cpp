#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string str;
int value = 0;


int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	if (str[i] == 'f') value++;

	if (value == 0) return 0;
	else if (value == 1)
	{
		for (int i = 0; i < str.length(); i++)
		if (str[i] == 'f')
		{
			cout << i << endl;
			return 0;
		}
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		if (str[i] == 'f')
		{
			cout << i << " ";
			break;
		}

		for (int i = str.length()-1; i >=0; i--)
		if (str[i] == 'f')
		{
			cout << i << endl;
			return 0;
		}
	}
}