#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string str;
pair <int, int> Sum;

int main()
{
	cin >> str;
	Sum.first = Sum.second = 0;
	for (int i = 0; i < str.length(); i++)
	if (i % 2) Sum.first += str[i] - 48;
	else Sum.second += str[i] - 48;
	
	if ((Sum.first - Sum.second) % 11 == 0)
		cout << "Yes\n";
	else cout << "No\n";
}