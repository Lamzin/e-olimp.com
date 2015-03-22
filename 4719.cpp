#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

pair <int, int> a, b;

int main()
{
	cin >> a.first >> a.second >> b.first >> b.second;
	if (b.first > 8 || b.second > 8 || b.first < 0 || b.second < 0
		|| a.first > 8 || a.second > 8 || a.first < 0 || a.second < 0)
	{
		cout << "NO\n";
	}
	else if (a.first == b.first || a.second == b.second /*|| abs(a.first - b.first) == abs(a.second - b.second)*/)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}

}