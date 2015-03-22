#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

string str;
vector <char> a, b;
bool found = true;

int main()
{
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') a.push_back(0);
		else if (str[i] == ')') a.push_back(1);
		else if (str[i] == '[') a.push_back(10);
		else if (str[i] == ']') a.push_back(11);
		else if (str[i] == '{') a.push_back(20);
		else if (str[i] == '}') a.push_back(21);
	}

	while (found)
	{
		found = false;
		b.clear();
		for (int i = 0; i < a.size(); i++)
		{
			if (i < a.size() - 1 && a[i + 1] - a[i] == 1)
			{
				found = true;
				i++;
			}
			else
			{
				b.push_back(a[i]);
			}
		}
		swap(a, b);
	}

	if (a.size() == 0)
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}