#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string> 

using namespace std;

bool f(string a, string b)
{
	return a + b > b + a;
}

int n;
vector <string> v;
string tmp;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), f);

	for (int i = 0; i < n; i++)
	{
		cout << v[i];
	}

	cout << endl;

	return 0;
}