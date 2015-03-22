#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<long long, long long>> vect;

long long n, tmp, ans = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(make_pair(0, tmp));
		while (tmp % 10 == 0)
		{
			vect[vect.size() - 1].first++;
			tmp /= 10;
		}
	}

	tmp = -1;

	for (int i = 0; i < vect.size(); i++)
	if (vect[i].first > tmp)
	{
		tmp = vect[i].first;
		ans = vect[i].second;
	}

	for (int i = 0; i < vect.size(); i++)
	if (tmp == vect[i].first && vect[i].second < ans)
	{
		ans = vect[i].second;
	}

	cout << ans<< endl;
} 