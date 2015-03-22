#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

pair <string, string> str;

pair <int, int> a, b;

int index;

int main()
{
	a.first = a.second = b.first = b.second = 0;
	cin >> str.first >> str.second;

	index = 0;
	while (str.first[index] != '^')
		a.first = a.first * 10 + (str.first[index++] - 48);
	index++;
	while (index < str.first.length())
		a.second = a.second * 10 + (str.first[index++] - 48);

	index = 0;
	while (str.second[index] != '^')
		b.first = b.first * 10 + (str.second[index++] - 48);
	index++;
	while (index < str.second.length())
		b.second = b.second * 10 + (str.second[index++] - 48);

	if (b.first == 1) cout << str.first << endl;
	else if (a.first == 1) cout << str.second << endl;
	else if (logf(a.first) * a.second > logf(b.first) * b.second) cout << str.first << endl;
	else cout << str.second << endl;
}