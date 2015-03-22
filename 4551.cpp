#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<double, double>> vect;
pair<double, double> a, b;
double x, y;
int n, answer, tmp;

int check(double X, double Y)
{
	double len_min = 100000000, len_tmp;
	int ret = 0;

	for (int i = 0; i < vect.size(); i++)
	{
		len_tmp = hypot(X - vect[i].first, Y - vect[i].second);
		if (len_tmp < len_min)
		{
			len_min = len_tmp;
			ret = i;
		}
	}
	return ret;
}

int main()
{
	cin >> n;
	cin >> a.first >> a.second >> b.first >> b.second;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}

	if (a.first > b.first) swap(a,b);

	tmp = check(a.first, a.second);

	if (a.first == b.first)
	{
		if (a.second > b.second) swap(a,b);

		x = a.first;
		tmp = check(a.first, a.second);
		
		for (y = a.second; y <= b.second; y+=0.001)
		{
			static int tmp_count;
			tmp_count = check(x, y);
			if (tmp_count != tmp)
			{
				tmp = tmp_count;
				answer++;
			}
		}
	}
	else
	{
		for (x = a.first; x <= b.first; x += 0.001)
		{
			y = (x - a.first) * (a.second - b.second) / (a.first - b.first) + (a.second);
			static int tmp_count;
			tmp_count = check(x, y);
			if (tmp_count != tmp)
			{
				tmp = tmp_count;
				answer++;
			}
		}
	}

	cout << answer << endl;
}