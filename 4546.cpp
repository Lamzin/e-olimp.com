#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <list>

using namespace std;

list <pair<int, long long>> vect;
int n, m, t;

int main()
{
	cin >> n >> m>> t;
	vect.push_back(make_pair(1, n));
	while (vect.front().second != m)
	{
		if (vect.front().second > t)
		{
			vect.push_back(make_pair(vect.front().first + 1, vect.front().second - t));
		}
		if (vect.front().second % t == 0)
		{
			vect.push_back(make_pair(vect.front().first + 1, vect.front().second / t));
		}
		if (vect.front().second * t < 1000000)
		{
			vect.push_back(make_pair(vect.front().first + 1, vect.front().second * t));
		}
		vect.pop_front();
	}
	cout << vect.front().first << endl;
}