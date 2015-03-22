#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

inline long long get5(long long a, long long b)
{
	return (b / 5) - ((a - 1) / 5);

}

int main()
{
	int n;
	vector <pair <long long, long> > vect;

	cin >> n;

	long long tmp1, tmp2;
	for (int i = 0; i<n; i++)
	{
		cin >> tmp1 >> tmp2;
		vect.push_back(make_pair(MIN(tmp1, tmp2), -1));
		vect.push_back(make_pair(MAX(tmp1, tmp2), 1));
	}
	sort(vect.begin(), vect.end());

	int cnt = 0;
	long long answ = 0;
	long long lf = -1;

	for (int i = 0; i < n * 2 - 1; i++)
	{
		if (vect[i].second < 0)
			cnt++;
		else
			cnt--;

		if (cnt > 0)
		{
			answ += get5(vect[i].first, vect[i + 1].first);
			if (vect[i].first == lf)
				answ--;
			if (vect[i + 1].first % 5 == 0) lf = vect[i + 1].first;
		}
		//cout << (vect[i + 1].first / 5) << " " << ((vect[i].first - 1) / 5) << "\n";
	}

	cout << answ << endl;

	return 0;
}