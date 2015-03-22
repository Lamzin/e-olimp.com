#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

pair <long long, long long> answer;
long long n, m, tmp, _count;

int main()
{
	cin >> n;
	answer.first = answer.second = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		_count = 0;
		tmp = m;
		while (tmp)
		{
			_count += tmp % 2;
			tmp >>= 1;
		}
		if ((_count > answer.first) || (_count == answer.first && m < answer.second))
		{
			answer.first = _count;
			answer.second = m;
		}
	}
	cout << answer.second << endl;
}